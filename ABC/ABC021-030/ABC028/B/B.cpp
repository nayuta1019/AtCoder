/**
ABC028
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
    string s;
    cin >> s;

    int a=0, b=0, c=0, d=0, e=0, f=0;
    rep(i, s.size()){
        if(s[i] == 'A') a++;
        else if(s[i] == 'B') b++;
        else if(s[i] == 'C') c++;
        else if(s[i] == 'D') d++;
        else if(s[i] == 'E') e++;
        else if(s[i] == 'F') f++;
    }

    printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);

    return 0;
}