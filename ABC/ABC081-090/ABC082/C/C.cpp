/**
2018/11/18/ 解説AC
mapの使い方
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int a[100000];

int main(){
    int N;

    cin >> N;

    for(int i = 0; i < N; i++) cin >> a[i];

    map<int, int> m;
    for(int i = 0; i < N; i++)m[a[i]]++;

    int res = 0;
    for (auto p : m){
        if(p.second - p.first < 0) res += p.second;
        else res += p.second - p.first;
    }

    cout << res << endl;

    return 0;
}