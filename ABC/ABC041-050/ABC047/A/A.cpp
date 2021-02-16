#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;

    bool flag = true;

    if(a+b == c) flag = true;
    else if(a+c == b) flag = true;
    else if(b+c == a) flag = true;
    else flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}