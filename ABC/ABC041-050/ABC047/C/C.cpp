/**
2018/11/12/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    string S;
    cin >> S;

    char color = S[0];
    int res = 0;
    for(int i = 1; i < S.size(); i++){
        if(color != S[i]){
            color = S[i];
            res++;
        }
    }

    cout << res << endl;

    return 0;
}