/**
ABC016
2018/12/21/ 解説用
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

int N, M;
vector< vector<bool> > graph(11, vector<bool>(11, false));
int cnt;

void bfs(int x){
    vector<int> cost(N, 0);
    rep(i, N){
        if(graph[x][i]) cost[i] = 1;
    }

    rep(i, N){
        if(cost[i] == 1){
            rep(j, N){
                if(graph[i][j] && cost[j] == 0){
                    cost[j] = 2;
                }
            }
        }
    }
    cost[x] = 0;
    rep(i, N) if(cost[i] == 2) cnt++;
    return ;
}

int main(){
    cin >> N >> M;
    rep(i, M){
        int to, from;
        cin >> to >> from;
        to--; from--;
        graph[to][from] = true;
        graph[from][to] = true;
    }

    rep(i, N){
        cnt = 0;
        bfs(i);
        cout << cnt << endl;
    }

    return 0;
}