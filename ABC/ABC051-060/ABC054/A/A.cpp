/**
2018/11/09/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int A, B;
    cin >> A >> B;

    if(A == 1) A += 13;
    if(B == 1) B += 13;

    if(A < B) cout << "Bob" << endl;
    else if(B < A) cout << "Alice" << endl;
    else cout << "Draw" << endl;

    return 0;
}