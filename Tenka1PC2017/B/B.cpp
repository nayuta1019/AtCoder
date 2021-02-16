/**
2018/10/27/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

int main(){

    int N, A, B;

    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        if(A < x){
            A = x;
            B = y;
        }
    }

    cout << A + B << endl;

    return 0;
}