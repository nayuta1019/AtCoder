#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

int cake[1000][1000];
 
int main(){
    int N;
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cake[i][j] == 0){
                cake[i][j] = 2;
                if(0 < i && i < N && 0 < j && j < N){
                    cake[i+1][j] = 1;
                    cake[i][j+1] = 1;
                    cake[i-1][j] = 1;
                    cake[i][j-1] = 1;
                }else if(i == 0){
                    if(j == 0){
                        cake[i][j+1] = 1;
                        cake[i+1][j] = 1;
                    }else{
                         cake[i][j-1] = 1;
                         cake[i+1][j] = 1;
                    }
                    
                }else if(i == N-1){
                    if(j == 0){
                        cake[i][j+1] = 1;
                        cake[i-1][j] = 1;
                    }else{
                        cake[i-1][j] = 1;
                        cake[i][j-1] = 1;
                    }
                }else if(j == 0){
                    cake[i+1][j] = 1;
                    cake[i][j+1] = 1;
                    cake[i-1][j] = 1;
                }else if(j == N-1){
                    cake[i-1][j] = 1;
                    cake[i][j-1] = 1;
                    cake[i+1][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << cake[i][j];
        }
        cout << endl;
    }

    return 0;
}