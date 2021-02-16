/**
2018/11/20/ 解説AC
数学
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    cout << (1900*M + 100*(N-M))*pow(2, M) << endl;

    return 0;
}