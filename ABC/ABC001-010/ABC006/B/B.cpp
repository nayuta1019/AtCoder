/**
2018/10/24/ 解説AC
再帰は無理っぽい
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

const int p = 10007;

int main(){
    int n;

    cin >> n;

    vector<int> a(n);

    a[0] = a[1]= 0;
    a[2] = 1;
 
    for(int i = 3; i < n; i++){
        a[i] = a[i-1] + a[i-2] + a[i-3];
        a[i] %= p;
    }
 
    cout << a[n-1] << endl;

    return 0;
}