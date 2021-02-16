/**
ABC119
2019/03/17/ 解説AC
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
const long long INF = (long long)1e18;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];
    s.push_back(INF); s.push_back(-INF); sort(s.begin(), s.end());
    t.push_back(INF); t.push_back(-INF); sort(t.begin(), t.end());

    rep(k, Q){
        ll x;
        cin >> x;
        ll res = INF;

        rep(i, 2){
            ll first;
            if(i == 0) first = s[upper_bound(all(s), x) - s.begin() - 1];
            else first = s[lower_bound(all(s), x) - s.begin()];

            rep(j, 2){
                ll second;
                if(j == 0) second = t[upper_bound(all(t), x) - t.begin() - 1];
                else second = t[lower_bound(all(t), x) - t.begin()];
                res = min(res, abs(x-first) + abs(first-second));
            }
        }
        rep(i, 2){
            ll first;
            if(i == 0) first = t[upper_bound(all(t), x) - t.begin() - 1];
            else first = t[lower_bound(all(t), x) - t.begin()];

            rep(j, 2){
                ll second;
                if(j == 0) second = s[upper_bound(all(s), x) - s.begin() - 1];
                else second = s[lower_bound(all(s), x) - s.begin()];
                res = min(res, abs(x-first) + abs(first-second));
            }
        }
        cout << res << endl;
    }

    return 0;
}