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
    string s;
    cin >> s;

    if(s.size() == 3) reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}