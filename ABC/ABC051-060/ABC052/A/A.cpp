#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    int A, B, C, D;

    cin >> A >> B >> C >> D;
    
    if(A*B < C*D) cout << C*D << endl;
    else cout << A*B << endl;


    return 0;
}