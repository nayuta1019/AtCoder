/**
2018/10/24/ 初見AC
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

int main(){
    int N, T[100];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> T[i];

    sort(T, T+N);

    cout << T[0] << endl;

    return 0;
}