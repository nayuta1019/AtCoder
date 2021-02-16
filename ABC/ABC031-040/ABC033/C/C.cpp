/**
2018/11/08/ 解説AC
'+'で区切って考える
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    string s;
    cin >> s;


    int ans = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') flag = true;

        if(s[i] == '+'){
            if(!flag) ans++;
            flag = false;
        }
    }

    if(!flag) ans++;

    cout << ans << endl;

    return 0;
}