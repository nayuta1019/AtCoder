/**
2018/12/02/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    string X;
    cin >> X;

    bool flag = true;
    for(int i = 0; i < X.size(); i++){
        
        if(X[i] == 'c' && X[i+1] == 'h'){
            i++;
        }else if (X[i] == 'o' || X[i] == 'k' || X[i] == 'u'){
            continue;
        }else{
            flag = false;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}