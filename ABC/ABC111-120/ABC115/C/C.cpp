/**
ABC115
2018/12/08/ 初見AC
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
    vector<int> h(N);
    rep(i, N) cin >> h[i];

    sort(h.begin(), h.end());

    int right = 0, cnt = 0;
    ll ans = 1e9;
    for(int left = 0; left < N; left++){
        ll hmin, hmax;
        while(right < N && cnt < K){
            hmin = h[left];
            hmax = h[right];
            right++;
            cnt++;
        }

        ans = min(ans, hmax - hmin);

        cnt--;
    }

    cout << ans << endl;


    return 0;
}