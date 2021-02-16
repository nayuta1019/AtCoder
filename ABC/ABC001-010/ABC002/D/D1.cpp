/**
2018/10/22/ 未完成
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

const int nmax = 13;

int N, M;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){  //  vが現在いる頂点

    bool all_visited = true;    //  全ての頂点を訪れたかどうか

    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }

    if(all_visited){
        return 0;
    }

    int cnt = 0;

    for(int i = 0; i < N; i++){
        if(graph[v][i] == false) continue;  //  頂点どうしが繋がっていなければcontinue
        if(visited[i]){
            return 1; // すでに訪れた場所であれば
        }

        visited[i] = true;  //  iが次に訪れる頂点。頂点iを訪れたことにする
        cnt += dfs(i, N, visited);  //  現在の頂点をiにしてdfs
        visited[i] = false; //  初期化
    }
    return cnt;
}

int main(){
    

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x][y] = graph[y][x] = true;
    }

    bool visited[13];
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }

    int max = 1;
    for(int i = 0; i < M; i++){
        int x = 1;
        visited[i] = true;  //  最初の頂点
        x += dfs(i, N, visited);
        if(max < x) max = x;
    }
    
    cout << max << endl;

    return 0;
}