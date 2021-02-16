/**
ABC042
2019/04/25/ 解説用
**/
#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }


const long long MOD = 1000000007;

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

inline long long inv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    return mod(u, m);
}

const int MAX_R = 510000;
long long Com1[MAX_R];
long long Com2[MAX_R];

void calc_Dcom(long long a, long long b) {
    memset(Com1, 0, sizeof(Com1));
    memset(Com2, 0, sizeof(Com2));
    long long s = 1, t = 1;
    Com1[0] = s, Com2[0] = t;
    for (int i = 1; i < MAX_R; ++i) {
        s = mod(s * (a-i+1), MOD);
        s = mod(s * inv(i, MOD), MOD);
        Com1[i] = s;
        
        t = mod(t * (b-i+1), MOD);
        t = mod(t * inv(i, MOD), MOD);
        Com2[i] = t;
    }
}

int main() {
    int n, m, A, B;
    while (cin >> n >> m >> A >> B) {
        --n; --m;
        calc_Dcom(n - A + B, m + A - B);
        
        long long res = 0;
        for (long long i = 0; i < max(n+1, m+1); ++i) {
            long long tmp = mod(Com1[B+i] * Com2[A+i], MOD);
            res += tmp;
            res %= MOD;
        }
        cout << res << endl;
    }
}





















