/**
2018/11/16/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    char a, b;
    cin >> a >> b;

    if(a == 'H'){
        if(b == 'H'){
            cout << "H" << endl;
        }else{
            cout << "D" << endl;
        }

    }else{
        if(b == 'H'){
            cout << "D" << endl;
        }else{
            cout << "H" << endl;
        }
    }

    return 0;
}