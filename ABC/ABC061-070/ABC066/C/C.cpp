/**
ABC066
2019/01/06/ 自力AC
dequeを使う
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    if(n % 2){
        rep(i, n){
            int x;
            cin >> x;
            if( (i+1) % 2 ) a.insert(a.begin(), x);
            else a.push_back(x);
        }
    }else{
        rep(i, n){
            int x;
            cin >> x;
            if( (i+1) % 2 ) a.push_back(x);
            else a.insert(a.begin(), x);
        }
    }

    rep(i, n){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}