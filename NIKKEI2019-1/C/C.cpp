/**
NIKKEI2019
2019/01/27/ 解説AC
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    vector< pair<ll, int> > ab(N);
    rep(i, N){
        cin >> a[i] >> b[i];
        ab[i].first = a[i] + b[i];
        ab[i].second = i;
    }

    sort(ab.begin(), ab.end(), greater<pair<ll,int> >());

    ll ao = 0, t = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) t += a[ab[i].second];
        else ao += b[ab[i].second];
    }

    cout << t - ao << endl;

    return 0;
}