/**
ABC075
2019/01/25/ 解説AC
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

    int n, k;
    cin >> n >> k;

    vector<int> x(n), y(n);
    vector<int> xary, yary;
    
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(begin(xary), end(xary));
    sort(begin(yary), end(yary));

    ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);

    for(int xi = 0; xi < n; xi++){
        for(int xj = xi + 1; xj < n; xj++){
            for(int yi = 0; yi < n; yi++){
                for(int yj = yi + 1; yj < n; yj++){
                    int num = 0;
                    ll lx = xary[xi], rx = xary[xj];
                    ll by = yary[yi], uy = yary[yj];

                    for(int i = 0; i < n; i++){
                        if(lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy){
                            num++;
                        }
                    }

                    if(k <= num) ans = min(ans, 1LL * (rx - lx) * (uy - by));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}