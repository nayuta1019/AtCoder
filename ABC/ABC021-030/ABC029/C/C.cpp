/**
2018/11/10/ 解説AC
再帰関数
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

void f(int N, string S) {
    if (N == S.size()) {
        cout << S << endl;
        return;
    }
    f(N, S + "a");
    f(N, S + "b");
    f(N, S + "c");
}

int main() {
    int N;
    cin >> N;

    f(N, "");

    return 0;
}