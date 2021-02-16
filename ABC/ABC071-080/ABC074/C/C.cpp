/**
ABC074
2018/12/27/ 自力AC
全列挙
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
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    int water=0, suger=0, waterans=0, sugerans=0;
    double res = -1.0;
    for(int i = 0; 100*A*i <= F; i++){
        for(int j = 0; 100*B*j <= F; j++){
            for(int x = 0; C*x <= F; x++){
                for(int y = 0; D*y <= F; y++){
                    water = 100*A*i + 100*B*j;
                    suger = C*x + D*y;
                    if(F < water + suger) break;
                    if(water/100*E < suger) break;
                    double tmp = max(res, (double)(100*suger)/(water+suger) );
                    if(res < tmp){
                        waterans = water+suger;
                        sugerans = suger;
                        res = tmp;
                    }
                }
            }
        }
    }

    cout << waterans << " " << sugerans << endl;

    return 0;
}