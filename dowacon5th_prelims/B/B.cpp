/**
2018/11/25/ 未完成
**/
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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<ll> v(N*(N+1)/2);

    int right = 0;
    for(int left = 0; left < N; left++){
        right = left;
        ll add = 0;
        while(right < N){
            add += a[right];
            v.push_back(add);
            right++;
        }
    }
    sort(v.begin(), v.end(), greater<ll>());

    ll ans = 0;
    for(int left = 0; left < v.size()-K-1; left++){
        int cnt = 1;
        ll tmp = v[left];
        int right = left+1;
        while(right < v.size() && cnt < K){
            tmp = tmp & v[right];
            cnt++;
            right++;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}