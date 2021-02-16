/**
ABC025
2018/12/19/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<string> s(N);
    vector<int> d(N);
    rep(i, N) cin >> s[i] >> d[i];

    int x = 0;
    rep(i, N){
        if(s[i] == "West"){
            if(d[i] < A){
                x -= A;
            }else if(B < d[i]){
                x -= B;
            }else{
                x -= d[i];
            }
        }else{
            if(d[i] < A){
                x += A;
            }else if(B < d[i]){
                x += B;
            }else{
                x += d[i];
            }
        }
    }

    if(x < 0){
        cout << "West " << abs(x) << endl;
    }else if(0 < x){
        cout << "East " << x << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}