/**
2018/10/20/ 解説AC　理解はしたが自力で実装できるか怪しい
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;
 
int N, M, a[51], b[51];
bool graph[51][51];
bool visited[51];
 
void dfs(int v){

    for(int i = 0; i < N; i++){
        if(graph[v][i] == true && visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }

}
 
int main(){

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
 
    int ans = 0;
    for(int i = 0; i < M; i++){

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
 
        for(int j = 0; j < N; j++) visited[j] = false;

        visited[0] = true;
 
        dfs(0);

        for(int j = 1; j < N; j++){
            if(visited[j] == false){
                ans++;
                break;
            }
        }

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
 
    cout << ans << endl;
 
    return 0;
}