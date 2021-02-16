/**
ABC051
2018/12/19/ 解説AC
ワーシャルフロイド
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
    int n, m;
    cin >> n >> m;
    int a[1000], b[1000], c[1000], dist[100][100];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
        dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }

    //ワーシャルフロイド
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    int ans = m;
    for(int i = 0; i < m; i++){
        bool shortest = false;
        for(int j = 0; j < n; j++){
            if( dist[j][a[i]] + c[i] == dist[j][b[i]] ) shortest = true;
        }
        if(shortest == true) ans--;
    }

    cout << ans << endl;

    return 0;
}