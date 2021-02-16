/**
2018/11/11/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    ll N;
    cin >> N;

    int depth = 0;
    for(ll n = N; 0 < n; n /= 2) depth++;
    //cout << depth << endl;

    ll num = 1;
    bool flag = false;
    if(depth % 2 == 0){
        while(num <= N){
            if(num*2 <= N){
                num *= 2;
                flag = true;
            }else{
                flag = false;
                break;
            }

            if(num*2 + 1 <= N){
                num = num * 2 + 1;
                flag = false;
            }else{
                flag = true;
                break;
            }
        }
    }else{

        while(num <= N){
            if(num*2+1 <= N){
                num = num * 2 + 1;
                flag = true;
            }else{
                flag = false;
                break;
            }

            if(num*2 <= N){
                num *= 2;
                flag = false;
            }else{
                flag = true;
                break;
            }
        }
    }

    if(flag) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}