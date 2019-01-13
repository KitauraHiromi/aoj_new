#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <string>
#define MAX_N 1001
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef pair<string, int> P;
P p[MAX_N];
int n;

int main(){
    string s;
    n = 0;
    while(cin >> s){
        bool flag = false;
        rep(i, n){
            if(p[i].first == s){
                p[i].second++;
                flag = true;
            }
        }
        if(!flag){ 
            p[n].first = s;
            p[n].second++;
            n++;
        }
    }
    // rep(i, n) cout << p[i].first << " " << p[i].second << endl;
    sort(p, p+n, [](const P &left, const P &right){
        return left.second > right.second;
    });
    cout << p[0].first << " ";
    sort(p, p+n, [](const P &left, const P &right){
        return left.first.size() > right.first.size();
    });
    cout << p[0].first << endl;
    return 0;
}