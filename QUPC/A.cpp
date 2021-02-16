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

    int ans = 2014;
    for(int i = 0; i < N-1; i++) ans += 4;

    cout << ans << endl;

    return 0;
}