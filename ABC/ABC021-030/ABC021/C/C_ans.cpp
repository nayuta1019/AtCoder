/**
ABC021
2018/12/17/ 解説AC
ダイクストラ法とDFSの組み合わせ
ダイクストラ法ではなくBFSなどでもOK
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
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

vector<vector<int>> link(101);
int dist[101];
int n;
int a, b;
int used[101];
ll route[101];

void dijkstra(int a){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[a] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, a));
    while( !que.empty() ){
        P pp = que.top();
        que.pop();
        int p = pp.second;
        for(int v : link[p]){
            if(dist[p] + 1 < dist[v]){
                dist[v] = dist[p] + 1;
                que.push( P(dist[v], v) );
            }
        }
    }
}

ll dfs(int v){
    if(0 < route[v]) return route[v];
    int res = 0;
    for(int p : link[v]){
        if(dist[p] == dist[v] - 1) res += dfs(p) % MOD;
    }
    return route[v] = res % MOD;
}

int main(){
    cin >> n;
    cin >> a >> b;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        link[x].push_back(y);
        link[y].push_back(x);
    }

    dijkstra(a);
    route[a] = 1;
    
    cout << dfs(b) << endl;

    return 0;
}