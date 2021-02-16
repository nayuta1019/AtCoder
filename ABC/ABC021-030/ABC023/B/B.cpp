/**
ABC023
2018/12/19/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N;
    string S;
    cin >> N >> S;

    int num = 1;
    string str = "b";
    for(num = 1; str.size() < N; num++){
        if(num % 3 == 1) str = "a" + str + "c";
        else if(num % 3 == 2) str = "c" + str + "a";
        else if(num % 3 == 0) str = "b" + str + "b";
    }

    if(S == str){
        cout << num-1 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}