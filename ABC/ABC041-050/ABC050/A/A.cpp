#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    int A, B;
    char op;

    cin >> A >> op >> B;
    
    int ans;
    if(op == '+') ans = A + B;
    else ans = A - B;

    cout << ans << endl;     


    return 0;
}