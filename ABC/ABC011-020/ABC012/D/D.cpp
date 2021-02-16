/**
2018/11/21/ 解説AC
ワーシャルフロイド
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector< vector<int> > Matrix;
const int INF = 1e9;

Matrix graph;

void warshall_floyd(int n) { // nは頂点数
    for (int k = 0; k < n; k++)      // 経由する頂点
        for (int i = 0; i < n; i++)    // 開始頂点
            for (int j = 0; j < n; j++)  // 終端
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main(){
    int N, M;
    cin >> N >> M;

    graph = Matrix(N, vector<int>(N, INF));
    for(int i = 0; i < N; i++) graph[i][i] = 0;

    for(int i = 0; i < M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        graph[from][to] = min(graph[from][to], cost);
        graph[to][from] = min(graph[to][from], cost);
    }

    warshall_floyd(N);

    int minTime = INF;
    for(int i = 0; i < N; i++){
        int maxTime = 0;
        for(int j = 0; j < N; j++){
            maxTime = max(graph[i][j], maxTime);
        }
        minTime = min(minTime, maxTime);
    }

    cout << minTime << endl;

    return 0;
}