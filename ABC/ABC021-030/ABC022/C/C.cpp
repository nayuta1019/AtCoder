/**
ABC022
2018/12/10/ 解説AC
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

const int MAX_V = 400;
int d[MAX_V][MAX_V];
int V, E;

void warshall_floyd(){
    for(int k = 0; k <= V; k++){
        for(int i = 0; i <= V; i++){
            for(int j = 0; j <= V; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    cin >> V >> E;

    for(int i = 0; i < MAX_V; i++){
        for(int j = 0; j < MAX_V; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    vector<pair<int, int>> checklist;
    for(int i = 0; i < E; i++){
        int u, v, l;
        cin >> u >> v >> l;
        if(u == 1){
            //1とつながりのある場合
            checklist.push_back(make_pair(v, l));
        }else{
            d[u][v] = l;
            d[v][u] = l;
        }
    }

    warshall_floyd();
    int check = checklist.size();
    int ans = 1e9;
    for(int i = 0; i < check - 1; i++){
        for(int j = i + 1; j < check; j++){
            ans = min(ans, checklist[i].second + d[checklist[i].first][checklist[j].first] + checklist[j].second);
        }
    }

    if(ans < 1e9) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}