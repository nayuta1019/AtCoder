/**
2018/10/19/ 初見AC
cstadio でやればよかった
 printf ("% d -% d -% d -% d =7\ n " ,a ,b ,c , d );
でかける
入力は
char s[5];
scanf ("% s " ,& s );
int a = s [0] - ’0 ’ , b = s [1] - ’0 ’ , c = s [2] - ’0 ’ , d = s [3] - ’0 ’;
の方が楽かも

**/

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
    vector <int> v;

    cin >> N;

    while(0 < N){
        int tmp = N % 10;
        v.push_back(tmp);
        N /= 10;
    }

    if(v[3]+v[2]+v[1]+v[0] == 7) cout << v[3] << "+" << v[2] << "+" << v[1] << "+" << v[0] << "=7" << endl;
    else if(v[3]+v[2]+v[1]-v[0] == 7) cout << v[3] << "+" << v[2] << "+" << v[1] << "-" << v[0] << "=7" << endl;
    else if(v[3]+v[2]-v[1]+v[0] == 7) cout << v[3] << "+" << v[2] << "-" << v[1] << "+" << v[0] << "=7" << endl;
    else if(v[3]+v[2]-v[1]-v[0] == 7) cout << v[3] << "+" << v[2] << "-" << v[1] << "-" << v[0] << "=7" << endl;

    else if(v[3]-v[2]+v[1]+v[0] == 7) cout << v[3] << "-" << v[2] << "+" << v[1] << "+" << v[0] << "=7" << endl;
    else if(v[3]-v[2]+v[1]-v[0] == 7) cout << v[3] << "-" << v[2] << "+" << v[1] << "-" << v[0] << "=7" << endl;
    else if(v[3]-v[2]-v[1]+v[0] == 7) cout << v[3] << "-" << v[2] << "-" << v[1] << "+" << v[0] << "=7" << endl;
    else if(v[3]-v[2]-v[1]-v[0] == 7) cout << v[3] << "-" << v[2] << "-" << v[1] << "-" << v[0] << "=7" << endl;

    return 0;
}