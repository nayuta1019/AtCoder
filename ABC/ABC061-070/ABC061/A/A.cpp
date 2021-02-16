/**
ABC061
2018/12/29/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(a <= c && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}