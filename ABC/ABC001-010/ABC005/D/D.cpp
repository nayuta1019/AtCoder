/**
2018/10/24/ 未完成
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>

using namespace std;

const int nmax = 50;
int CumulativeSum[nmax][nmax];
int N, D[nmax][nmax], Q, P;

void printmatrix(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << CumulativeSum[i][j];
            if(j != N-1) cout << " ";
        }
        cout << endl;
    }
}

void CumulativeSumFunc(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            CumulativeSum[j][i] += D[j][i];
            if(i == 0) continue;
            CumulativeSum[j][i] += CumulativeSum[j][i-1];
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            CumulativeSum[i][j] += CumulativeSum[i-1][j];
        }
    }

}

int main(){
    

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> D[i][j];
        }
    }

    CumulativeSumFunc();
    printmatrix();

    int maxarea = 0;
    for(int m = 2; m <= 2; m++){
        for(int i = 0; i < N; i++){
            
            for(int j = 0; j < N; j++){
                //  横方向
                int widtharea = 0;
                if(j - m < 0) widtharea = CumulativeSum[i][j];
                else widtharea = CumulativeSum[i][j] - CumulativeSum[i][j-m];
                
 
                //  縦方向
                int heightarea = 0;
                if(j - m < 0) heightarea = CumulativeSum[j][i];
                else heightarea = CumulativeSum[j][i] - CumulativeSum[j-m][i];

                cout << "i = " << i << " " << "j = " << j << endl;
                cout << "widtharea = " << widtharea << endl;
                cout << "heightarea = " << heightarea << endl;

                int area = max(heightarea, widtharea);

                if(maxarea < area) maxarea = area;
            }
        
        }
    }
    
    
    

    cout << "max = " << maxarea << endl;

    return 0;
}