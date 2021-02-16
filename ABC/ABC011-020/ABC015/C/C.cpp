/**
2018/11/03/ 解説AC
dfsを使った全探索
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K;
int T[10][10];
 
bool dfs(int num, int q){
  if(q == N){
    if(num == 0) return false;
    else return true;
  }
 
  for(int i = 0; i < K; i++){
    if( !dfs(num^T[q][i], q+1) ) return false;
  }
 
  return true;
}
 
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
        cin >> T[i][j];
        }
    }
 
    if(!dfs(0,0)){
        cout << "Found" << endl;
    }else{
        cout << "Nothing" << endl;
    }

    return 0;
}