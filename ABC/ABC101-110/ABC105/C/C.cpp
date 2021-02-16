#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main() {
    int N;

    cin >> N;

    string s;
    while(N){
        if(N % 2){
            s += '1';
            N--;
        }else{
            s += '0';
        }
        N /= (-2);
    }
    reverse(s.begin(),s.end());

    if(s == "") cout << 0 << endl;
    else cout << s << endl;

	return 0;
}