/**
ABC105
2019/02/14/ 解説AC
author:kort0n
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

    ll N, M;
    cin >> N >> M;
    vector<ll> sum;
    sum.push_back(0);
    unordered_map<ll, ll> mp;
    mp[0]++;
    for(int i = 0; i < N; i++){
        ll in;
        cin >> in;
        sum.push_back((sum.back() + in) % M);
        mp[sum.back()]++;
    }
    ll ans = 0;
    ll val;
    for(int i = 0; i < sum.size(); i++){
        val = sum[i];
        ans += mp[val] * (mp[val] - 1) / 2;
        mp[val] = 0;
    }

    cout << ans << endl;

    return 0;
}