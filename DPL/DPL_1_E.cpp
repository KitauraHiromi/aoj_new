/*
 * Contents   : AOJ DPL 1 E AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180614
 * Since      : 20180614
 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string S, T;
int INF = 1e9+1;
int dp[1010][1010];
int main(void){
    cin >> S >> T;
    dp[0][0] = 0;
    for(int i=-1; i<=(int)S.size(); ++i){
        for(int j=-1; j<=(int)T.size(); ++j){
            if(i == -1 && j == -1) continue;
            // 変更
            if(i >= 0 && j >= 0){
                if(S[i] == T[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
            }
            // 削除
            if(i >= 0) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);
            // 追加
            if(j >= 0) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}