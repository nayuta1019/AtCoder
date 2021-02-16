/**
2018\10/23/ 初見AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include<iomanip>

using namespace std;

int card[7] = {1, 2, 3, 4, 5, 6};

int main(){
    int N;

    cin >> N;

    int loop = N / 5 % 6;
    for(int i = 0; i < loop; i++){
        int tmp = card[0];
        for(int j = 0; j < 5; j++) card[j] = card[j+1];
        card[5] = tmp;
    }

    int change = N % 5;
    for(int i = 0; i < change; i++){
        swap(card[i], card[i+1]);
    }

    for(int i = 0; i < 6; i++) cout << card[i];
    cout << endl;

    return 0;
}