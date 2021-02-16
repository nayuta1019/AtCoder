/**
ABC029
2018/12/30/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int ans=0;

    rep(i, 12){
        string s;
        cin >> s;
        rep(j, s.size()){
            if(s[j] == 'r'){
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}