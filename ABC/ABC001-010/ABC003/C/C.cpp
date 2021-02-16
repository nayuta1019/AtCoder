/**
2018/10/23/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include<iomanip>

using namespace std;


int main(){
    int N, K, R[110];

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> R[i];

    sort(R, R+N);

    double C = 0;
    for(int i = N-K; i < N; i++){
        C = (double)(C + R[i]) / 2;
    }

    cout << fixed << setprecision(6);
    cout << C << endl;

    return 0;
}