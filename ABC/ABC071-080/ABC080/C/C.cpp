/**
2018/10/20/ 解説AC
bit全探索
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int N;
int F[100][14];
int P[100][15];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            scanf("%d", &F[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 11; j++){
            scanf("%d", &P[i][j]);
        }
    }

    int res = -(1 << 30);   //  十分に小さな値

    for(int b = 1; b < (1<<10); b++){   //  店を営業する時間帯の組み合わせは 2^10 − 1 = 1023 通り
        int cc = 0;
        for(int i = 0; i < N; i++){
            int c = 0;
            for(int j = 0; j < 10; j++){
                if( (b>>j & 1) && F[i][j] ) c++;
                
            }
            cc += P[i][c];
            
        }
        if(res < cc) res = cc;
    }

    printf("%d\n", res);

    return 0;
}