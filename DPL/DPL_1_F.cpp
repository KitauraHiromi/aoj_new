/*
 * Contents   : AOJ DPL 1 F
 * Author     : KitauraHiromi
 * LastUpdate : 20180618
 * Since      : 20180618
 */
#define INF 1000000001
#include <iostream>
#include <algorithm>
using namespace std;
int N, W;
int dp[101][101*101]; // dp[i][v]: i個目までの荷物を価値vまで入れたときの最小重さ
int value[101], weight[101];
int main(void){
    cin >> N >> W;
    fill((int*)dp, (int*)(dp+101), INF);
    dp[0][0] = 0;
    for(int i=0; i<N; ++i) cin >> value[i] >> weight[i];
    for(int i=0; i<N; ++i){
        for(int v=0; v<101*101; ++v){
            (v >= value[i]) ? dp[i+1][v] = min(dp[i][v], dp[i][v-value[i]] + weight[i]) : dp[i+1][v] = dp[i][v];
        }
    }
    // dp[N][i]がWを超えない最大のiが答え
    int res = 0;
    for(int i=0; i<101*101; ++i) if(dp[N][i] <= W) res = i;
    cout << res << endl;
}