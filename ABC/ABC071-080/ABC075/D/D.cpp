/**
ABC075
2019/01/25/ 未完成
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

struct point{
    long long int x;
    long long int y;
};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<point> v(N);
    rep(i, N) cin >> v[i].x >> v[i].y;

    ll ans = 9e18;
    for(int i = 0; i < N; i++){

        for(int j = i+1; j < N; j++){
            point p1, p2;
            p1.x = v[i].x; p1.y = v[i].y;
            p2.x = v[j].x; p2.y = v[j].y;

            int cnt = 0;
            for(int k = 0; k < N; k++){
                if( min(p1.x, p2.x) <= v[k].x && v[k].x <= max(p1.x, p2.x) ){
                    cnt++;
                }

                if(K <= cnt){
                    if( min(p1.y, p2.y) <= v[k].y && v[k].y <= max(p1.y, p2.y) ){
                        ll area = abs(p1.x - p2.x) * abs(p1.y - p2.y);
                        ans = min(ans, area);
                    }else{
                        int y1, y2;
                        y1 = max({p1.y, p2.y, v[k].y});
                        y2 = min({p1.y, p2.y, v[k].y});

                        ll area = abs(p1.x - p2.x) * abs(y1 - y2);
                        ans = min(ans, area);
                        cnt--;
                    }
                    
                }
            }

        }
    }

    cout << ans << endl;

    return 0;
}