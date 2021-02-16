#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    int N;
    cin >> N;

    int cnt  = 0;
    int tmp = N;
    while(tmp <= 100){
        cnt++;
        tmp += N;
    }

    cout << 100 - cnt << endl;

    return 0;
}