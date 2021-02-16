/**
ABC061
2018/12/25/ 解説AC
ベルマンフォード
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
//const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

const ll INF = 1LL << 50;

int main(){
    int N, M;
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];

    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }

    ll dist[NMAX];

    for(int i = 0; i < N; i++){
        dist[i] = INF;
    }

    dist[0] = 0;

    for(int loop = 0; loop < N - 1; loop++){
        for(int i = 0; i < M; i++){
            if(dist[a[i] - 1] == INF) continue;

            if(dist[b[i] - 1] > dist[a[i] - 1] + c[i]){
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    ll ans = dist[N - 1];

    bool negative[NMAX];

    for(int i = 0; i < N; i++){
        negative[i] = false;
    }

    for(int loop = 0; loop < N; loop++){
        for(int i = 0; i < M; i++){
            if(dist[a[i] - 1] == INF) continue;

            if(dist[b[i] - 1] > dist[a[i] - 1] + c[i]){
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                negative[b[i] - 1] = true;
            }

            if(negative[a[i] - 1] == true){
                negative[b[i] - 1] = true;
            }
        }
    }

    if(negative[N - 1]){
        cout << "inf" << endl;
    }else{
        cout << -ans << endl;
    }

    return 0;
}