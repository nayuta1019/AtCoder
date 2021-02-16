/**
2018/12/06/ 自力AC
貪欲法
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, D, K;
    cin >> N >> D >> K;
    vector< pair<int, int> > LR(D);
    vector< pair<int, int> > ST(K);
    rep(i, D) cin >> LR[i].first >> LR[i].second;
    rep(i, K) cin >> ST[i].first >> ST[i].second;

    rep(i, K){
        int s = ST[i].first, cnt = 1;

        if(ST[i].first <= ST[i].second){
            rep(j, D){
                if(LR[j].first <= s && s < LR[j].second){
                    s = LR[j].second;
                }
                if(ST[i].second <= s){
                    cout << cnt << endl;
                    break;
                }
                cnt++;
            }
        }else{
            rep(j, D){
                if(s <= LR[j].second && LR[j].first < s){
                    s = LR[j].first;
                }
                if(s <= ST[i].second){
                    cout << cnt << endl;
                    break;
                }
                cnt++;
            }
        }
        
    }

    return 0;
}