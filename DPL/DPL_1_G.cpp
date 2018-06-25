/*
 * Contents   : AOJ DPL 1 G TLE // AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180619
 * Since      : 20180619
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// int dp[101][10001]; // dp[i][w]: i種類目まで使い重さwまでの荷物を作ったときの最大価値
int dp[10001]; // dp[w]: 重さwまでの荷物を作ったときの最大価値

int N, W;
int main(void){
    cin >> N >> W;

    for(int i=0; i<N; ++i){
        int v, m, w;
        cin >> v >> w >> m;
        // TLE
        // for(int j=0; j<=W; ++j){
        //     for(int key=0; key<=m; ++key){
        //         if(j>=key*w) dp[i+1][j] = max(dp[i+1][j], dp[i][j-key*w] + key*v);
        // AC ?
        for(int k=0; m>0; ++k){
            int key = min(m, (1<<k)); // 2^n個ずつ調べる．加えるか加えないかしかないから，うまくいく．たぶん．
            m -= key;
            cout << m << ' ' << key << endl;
            for(int j=W; j>0; --j){
                if(j>=key*w) dp[j] = max(dp[j], dp[j-key*w] + key*v);
            }
            for(int l=0; l<=100; l++) cout << dp[l] << ' ';
            cout << endl;
        }
    }
    int ret = 0;
    for(int j=0; j<=W; ++j) ret = max(ret, dp[j]);
    cout << ret << endl;
}