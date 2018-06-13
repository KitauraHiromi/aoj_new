/*
 * Contents   : AOJ DPL 1 AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180613
 * Since      : 20180613
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N, W;
int dp[101][10001]; // dp[i][w]: i種類までの荷物をw kgまで選択できるときの最大価値を保持
int value[101], weight[101];
int main(void){
    cin >> N >> W;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<N; ++i) cin >> value[i] >> weight[i];
    for(int i=0; i<N; ++i){
        for(int w=0; w<=W; ++w){
            (w >= weight[i]) ? dp[i+1][w] = max(dp[i+1][w-weight[i]] + value[i], dp[i][w]) : dp[i+1][w] = dp[i][w];
        }
    }
    cout << dp[N][W] << endl;
}