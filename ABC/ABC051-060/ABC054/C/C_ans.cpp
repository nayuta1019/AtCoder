/**
2018/10/20/ 解説AC

**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

const int nmax = 8;

bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){  //  vが現在いる頂点

    bool all_visited = true;    //  全ての頂点を訪れたかどうか

    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }

    if(all_visited){
        return 1;   //  全ての頂点を訪れていたら1をr返す
    }

    int ret = 0;

    for(int i = 0; i < N; i++){
        if(graph[v][i] == false) continue;  //  頂点どうしが繋がっていなければcontinue
        if(visited[i]) continue;    //  すでに訪れていたらcontinue

        visited[i] = true;  //  iが次に訪れる頂点。頂点iを訪れたことにする
        ret += dfs(i, N, visited);  //  現在の頂点をiにしてdfs
        visited[i] = false; //  初期化
    }

    return ret; //  全ての頂点を訪れた回数が何回あったか
}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;
    }

    bool visited[nmax];
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }

    visited[0] = true;  //  最初の頂点

    cout << dfs(0, N, visited) << endl;

    return 0;
}