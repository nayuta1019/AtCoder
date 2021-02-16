/**
2018/10/29/ 解説AC
貪欲でいける。条件分岐しっかり！
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
 
int main(){
    int N, NG1, NG2, NG3;
    vector<int> v;

    cin >> N >> NG1 >> NG2 >> NG3;

    if(N == NG1 || N == NG2 || N == NG3){
        printf("NO\n");
        return 0;
    }

    int x = N;
    for(int i = 0; i < 100; i++){
        
        if(x-3 != NG1 && x-3 != NG2 && x-3 != NG3){
            x -= 3;
        }else if(x-2 != NG1 && x-2 != NG2 && x-2 != NG3){
            x -= 2;
        }else if(x-1 != NG1 && x-1 != NG2 && x-1 != NG3){
            x -= 1;
        }else{
            printf("NO\n");
            return 0;
        }

    }

    if(x <= 0) printf("YES\n");
    else printf("NO\n"); 

    return 0;
}