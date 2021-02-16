/**
2018/11/11/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    cout << max(A+D+E, B+C+E) << endl;

    return 0;
}