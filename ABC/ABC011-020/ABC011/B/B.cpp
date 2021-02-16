/**
2018/11/23/ 初見AC
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

    rep(i, S.size()){
        if(i == 0 && 'Z' < S[i]){
            S[i] = S[i] - ('a' - 'A');
        }
        if(0 < i && S[i] < 'a'){
            S[i] = S[i] + ('a' - 'A');
        }
    }

    cout << S << endl;

    return 0;
}