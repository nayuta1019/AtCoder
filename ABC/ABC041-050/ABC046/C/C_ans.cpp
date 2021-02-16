/**
2018/11/12/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
	int N;
    cin >> N;
    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> A[i];

    ll t, a;
    t = T[0]; a = A[0];
    for(int i = 1; i < N; i++){
        ll tx, ay;
        tx = t/T[i]; ay = a/A[i];
        if(t % T[i] != 0) tx++;
        if(a % A[i] != 0) ay++;

        ll n;
        n = max(tx, ay);
        t = n * T[i];
        a = n * A[i];
    }
	
    cout << t + a << endl;

    return 0;
}