/**
2018/11/02/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int    INF = (int)1e9;
const int    MOD = (int)1e9+7;

int main(){
    int N, M;
    cin >> N >> M;
 
    int d[20][20];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        d[i][j] = INF;
        }
    }

    for(int i = 0; i < N; i++) d[i][i] = 0;
 
    for(int t = 0; t < M; t++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a][b] = d[b][a] = 1;
    }
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
            }
        }
    }

/**
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << d[i][j];
        }
        cout << endl;
    }
**/

    for(int i = 0; i < N; i++){
        int ans = 0;
        for(int j = 0; j < N; j++){
            if( d[i][j] == 2 ) ans++;
        }
        cout << ans << endl;
    }
 
    return 0;
}
