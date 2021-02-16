/**
2018/11/25/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    string a, b, c;
    cin >> a >> b >> c;

    cout << (char)(a[0]-32);
    cout << (char)(b[0]-32);
    cout << (char)(c[0]-32);
    cout << endl;

    return 0;
}