/**
2018/10/27/ 自力AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    int H, W;
    char s[100][100];

    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> s[i][j];
        }
    }

    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            bool flag = true;
            if(s[i][j] == '#'){
                for(int p = 0; p < 4; p++){
                    int nx = j + dx[p];
                    int ny = i + dy[p];

                    if(0 <= nx && nx <= W-1 && 0 <= ny && ny <= H-1){
                        if(s[ny][nx] == '#'){
                            flag = false;
                            break;
                        }

                    }
                }
            }else flag = false;

            if(flag){
                cout << "No" << endl;
                return 0;
            }

        }
    }

    cout << "Yes" << endl;
    

    return 0;
}