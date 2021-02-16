#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    string s;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',') s[i] = ' ';
    }

    cout << s << endl;

    return 0;
}