/*
 * Contents   : AOJ DPL 1 D AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180613
 * Since      : 20180613
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N;
int INF = 1e9 + 1;
int dp[100001]; // dp[i]: i番目までの文字を見たときのLIS
int a[100001];
int main(void){
    cin >> N;
    for(int i=0; i<N; ++i) cin >> a[i];
    fill(dp, dp+N, INF);
    for(int i=0; i<N; ++i){
        *lower_bound(dp, dp+N, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp+N, INF) - dp << endl;
    return 0;
}