/*
 * Contents   : DPL 2 B
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180701
 * Since      : 20180701
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 15
#define INF 1<<20
int n, E;
int d[MAX_N][MAX_N]; // d[v][u]: 頂点uから頂点vに行くコスト
int dp[1<<MAX_N][MAX_N]; // dp[S][v]: 訪れていない頂点集合Sに状態で，出発頂点から頂点vに行くときの最短距離

int main(void){
    cin >> n >> E;
    fill((int*)dp, (int*)(dp+(1<<MAX_N)), INF);
    fill((int*)d, (int*)(d+MAX_N), INF);
    for(int e=0; e<E; e++){
        int i, j, tmp;
        cin >> i >> j;
        cin >> tmp;
        d[i][j] = d[j][i] = min(d[i][j], tmp);
    }
    dp[(1<<n) - 1][0] = 0;

    for(int S=(1<<n)-2; S>=0; S--){
        for(int v=0; v<n; v++){
            for(int u=0; u<n; u++){
                // 頂点uを訪れていれば
                if(!(S>>u & 1)){
                    // 頂点uを訪れるコスト + 頂点uから頂点vに行くコストのほうが低ければ更新
                    dp[S][v] = min(dp[S][v], dp[S|1<<u][u] + d[v][u]);
                }
            }
        }
    }
    if(dp[0][0] >= INF) cout << -1 << endl;
    else cout << dp[0][0] << endl;
}