/**
ABC063
2019/01/06/ 自力AC
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
    cin >> N;
    vector<int> s(N);
    int total = 0;
    rep(i, N){
        cin >> s[i];
        total += s[i];
    }

    if(total % 10 == 0){
        sort(s.begin(), s.end());
        rep(i, N){
            if(s[i] % 10 != 0){
                cout << total - s[i] << endl;
                return 0;
            }
        }
    }else{
        cout << total << endl;
        return 0;
    }

    cout << 0 << endl;

    return 0;
}