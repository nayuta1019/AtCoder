/**
2018/11/30/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    if(A + B == C && A - B == C){
        cout << "?" << endl;
    }else if(A + B == C){
        cout << "+" << endl;
    }else if(A - B == C){
        cout << "-" << endl;
    }else{
        cout << "!" << endl;
    }

    return 0;
}