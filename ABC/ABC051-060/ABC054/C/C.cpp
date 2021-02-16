/**
20018/10/20/ 未完成
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

int N, M;
bool graph[30][30];
bool node[10];


void print(bool g){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int dfs(int x, int y){
    
    if(node[x]){
        return ;
    }else{
        node[x] = true;

        y++;
        while(!graph[x][y]) y++;
        
        dfs(y, x);
    }

}

int main(){
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = graph[b][a] = true;
    }

    print(graph);

    ans = dfs(0, 0);

    return 0;
}