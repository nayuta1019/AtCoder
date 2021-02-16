/**
2018/11/04/ 初見AC
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
    string S[50];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];

    int cntmax = 0, cnt;
    string ans;

    for(int i = 0; i < N; i++){
        cnt = 0;

        for(int j = 0; j < N; j++){
            if(S[i] == S[j]) cnt++;
        }

        if(cntmax < cnt){
            cntmax = cnt;
            ans = S[i];
        }
    }

    cout << ans << endl;


    return 0;
}