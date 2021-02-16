/**
2018/11/27/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;

    int dist = abs(a - b);
    if( dist < 10 - dist ){
        cout << dist << endl;
    }else{
        cout << 10 - dist << endl;
    }

    return 0;
}