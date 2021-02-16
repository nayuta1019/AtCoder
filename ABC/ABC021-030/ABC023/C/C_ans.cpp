/**
2018/11/23/ 解説用
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef pair<int, int> P;

int rr[101010], cc[101010];
int contr[101010], contc[101010];

int main(){
    int R, C, K, N;
    cin >> R >> C >> K >> N;

    vector<P> v;
    for(int i = 0; i < N; i++){
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        rr[r]++;
        cc[c]++;
        v.push_back(P(r, c));
    }

    //飴がｘ個ある行・列がcont[x]個ある
    for(int i = 0; i < R; i++){
        contr[rr[i]]++;
    }
    for(int i = 0; i < C; i++){
        contc[cc[i]]++;
    }

    ll ans = 0;
    for(int i = 0; i <= K; i++){
        ans += contr[i] * contc[K - i];
    }

    for(auto x : v){
        if(rr[x.first] + cc[x.second] == K){
            ans--;
        }else if(rr[x.first] + cc[x.second] == K + 1){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}