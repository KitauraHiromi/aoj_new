/*
 * Contents   : DPL 2 A AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180626
 * Since      : 20180626
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 15
#define INF 1<<20
int n, E;
int d[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];

int main(void){
    cin >> n >> E;
    fill((int*)dp, (int*)(dp+(1<<MAX_N)), INF);
    fill((int*)d, (int*)(d+MAX_N), INF);
    for(int e=0; e<E; e++){
        int i, j;
        cin >> i >> j;
        cin >> d[i][j];
    }
    dp[(1<<n) - 1][0] = 0;

    for(int S=(1<<n)-2; S>=0; S--){
        for(int v=0; v<n; v++){
            for(int u=0; u<n; u++){
                if(!(S>>u & 1)){
                    dp[S][v] = min(dp[S][v], dp[S|1<<u][u] + d[v][u]);
                }
            }
        }
    }
    if(dp[0][0] >= INF) cout << -1 << endl;
    else cout << dp[0][0] << endl;
}