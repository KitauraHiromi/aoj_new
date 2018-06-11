/*
 * Contents   : AOJ DPL 1 A AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180611
 * Since      : 20180611
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N, M;
int dp[21][50001]; // dp[m][i]: m種類目までのコインをi円集めたときの最小枚数を保持
int value[21];
int main(void){
    cin >> N >> M;
    memset(dp, 50001, sizeof(dp));
    for(int m=0; m<M; ++m) cin >> value[m];
    for(int m=0; m<=M; ++m) dp[m][0] = 0;
    for(int m=0; m<M; ++m){
        for(int i=0; i<=N; ++i){
            if(i >= value[m]) dp[m+1][i] = min(dp[m+1][i-value[m]] + 1, dp[m][i]);
            else dp[m+1][i] = dp[m][i];
        }
    }
    cout << dp[M][N] << endl;
}