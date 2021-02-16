/**
ABC067
2019/04/26
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

int n;
int distF[100005], distS[100005];
vector< vector<int> > graph;

void dfs(int current, int prev, int d, int dist[]){
    dist[current] = d;
    for(auto next : graph[current]){
        if(next != prev) dfs(next, current, d+1, dist);
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n;
    graph.resize(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1, 0, distF);
    dfs(n-1, -1, 0, distS);

    int cnt = 0;
    rep(i, n){
        if(distF[i] <= distS[i]) cnt++;
        else cnt--; 
    }

    cout << (0 < cnt ? "Fennec" : "Snuke") << endl;

    return 0;
}