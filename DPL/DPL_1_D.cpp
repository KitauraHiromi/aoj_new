/*
 * Contents   : AOJ DPL 1 D 
 * Author     : KitauraHiromi
 * LastUpdate : 20180613
 * Since      : 20180613
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N;
int dp[100001]; // dp[i]: i番目までの文字を見たときのLIS
long long a[100001];
int main(void){
    cin >> N;
    int res = 0;
    for(int i=0; i<N; ++i) dp[i] = 1;
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int i=0; i<N; ++i){
        for(int j=0; j<i; ++j){
            if(a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}