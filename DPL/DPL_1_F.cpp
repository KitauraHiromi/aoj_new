/*
 * Contents   : (プロジェクト全体の役割)
 *              (モジュールの役割) (ファイル名)
 * Author     : (製作者の名前) (製作者の所属)
 * LastUpdate : (更新日YYYY/MM/DD)
 * Since      : (作成日YYYY/MM/DD)
 */
#include <iostream>
using namespace std;
int value[101], weight[101];
int dp[101]; // i個目までの荷物を選択肢に入れたときの最大価値
int w[101]; // i個目までの荷物を選択肢に入れたときに最大価値になる場合の重さ
int N, W;
int main(void){
    fill(value, value+101, 0);
    fill(weight, weight+101, 0);
    cin >> N >> W;
    for(int i=0; i<N; ++i){
        cin >> value[i];
        cin >> weight[i];
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(dp[j]+value[i])
            dp[i+1] = max(dp[j]+value[i], dp[i+1]);
        }
    }
}