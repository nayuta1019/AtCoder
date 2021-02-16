/**
ABC065
2019/01/30/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int x, a, b;
    cin >> x >> a >> b;

    if(b <= a) cout << "delicious" << endl;
    else if(0 <=  x - (b - a) ) cout << "safe" << endl;
    else cout << "dangerous" << endl;

    return 0;
}