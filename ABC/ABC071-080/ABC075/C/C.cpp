/**
2018/10/20/ 未完成
**/
#include <bits/stdc++.h>

using namespace std;

int N, M;
bool graph[55][55];

int dfs(int v, bool visited[55]){


}

int  main(){

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[55];

    for(int i = 0; i < N; i++){

    }


    return 0;
}