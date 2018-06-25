/*
 * Contents   : AOJ DPL 1 H
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180625
 * Since      : 20180625
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
ll v[40], w[40];
ll INF = (1<<20);
pair<ll, ll> ps[1<<20]; // sw, svを保持
ll N, W;
int main(void){
    cin >> N >> W;
    for(int i=0; i<N; i++) cin >> v[i] >> w[i];
    // 前半分の2^N/2を全探索
    for(int i=0; i<1<<N/2; i++){
        ll sw=0, sv=0;
        for(int j=0; j<N/2; j++){
            if(i>>j & 1){
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }
    // sw[i] <= sw[j]かつsv[i] >= sv[j]なるjを取り除く
    // 0~mまでの数が残る
    sort(ps, ps+(1<<N/2));
    int m = 1;
    for(int i=1; i<1<<N/2; i++){
        cout << ps[i].first << ' ' << ps[i].second << ' ' << m-1 << ' ' << i << ' ' << ps[m-1].second << ' ' << ps[i].second << endl;
        if(ps[m-1].second < ps[i].second){
            ps[m++] = ps[i];
            // ps[i] = ps[m++];
        }
    }
    cout << endl;
    for(int i=0; i<N/2; i++) cout << ps[i].first << ' ' << ps[i].second << endl;
    // 後ろ半分の2^N/2を全探索
    ll res = 0;
    for(int i=0; i<1<<(N-N/2); i++){
        ll sw=0, sv=0;
        for(int j=0; j<(N-N/2); j++){
            if(i>>j & 1){
                sw += w[N/2+j];
                sv += v[N/2+j];
            }
        }
        if(sw <= W){
            ll tv = (lower_bound(ps, ps+m, make_pair(W-sw, INF)) - 1)->second;
            res = max(res, sv+tv);
        }
    }
    printf("%lld\n", res);
}