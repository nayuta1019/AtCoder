/**
2018/11/07/ 初見AC
いもす法
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

ll imos[200010];

int main(){
    int N, Q;
    cin >> N >> Q;

    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        imos[l]++;
        imos[r+1]--;
    }


    for(int i = 1; i < N+2; i++){
        imos[i] += imos[i-1];
    }


    for(int i = 1; i < N+1; i++){
        if(imos[i]%2 == 0) cout << "0";
        else cout << "1";
    }
    cout << endl;

    return 0;
}