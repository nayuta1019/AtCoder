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

    ll n; cin >> n;
    string ans = "";

    ll tmp = n, sum = 0, cnt = 0;
    while(tmp > 0){
        sum += tmp % 10;
        tmp /= 10;
        cnt++;
    }

    while(0 < sum){
        if(0 <= sum-9){
            ans.push_back('9');
            sum -= 9;
        }else{
            ans.push_back('0'+sum);
            sum = 0;
        }
    }

    reverse(all(ans));
    string nn = to_string(n);
    if(nn == ans){
        if(ans[0] == '9'){
            ans.insert(0, "1");
            ans[1] = '8';
        }else{
            char q = ans[0];
            int qq = (int)q;
            qq++;
            q = qq;
            ans[0] = q;
            ans[1] = '8';
        }
    }

    cout << ans << endl;

    return 0;
}