/**
ABC019
2018/12/09/ 自力AC
string str = to_string(int x);
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

    char c = s[0];
    int num = 1;
    string ans = "";
    for(int i = 1; i < s.size(); i++){
        
        if(c == s[i]){
            num++;
        }else{
            ans += c;
            ans += to_string(num);
            c = s[i];
            num = 1;
        }
        
        if(i == s.size()-1){
            ans += c;
            ans += to_string(num);
        }
    }

    cout << ans << endl;

    return 0;
}