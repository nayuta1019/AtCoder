/**
2018/11/21/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for(int i = 0; i < D; i++) cin >> p[i] >> c[i];

    int res = 1<<21;
    for(int bit = 0; bit < 1<<D; bit++){
        int score = 0, total = 0;
        for(int i = 0; i < D; i++){
            if(bit>>i & 1){
                score += 100*(i+1)*p[i] + c[i];
                total += p[i];
            }
        }

        if(score < G){
            for(int j = D-1; 0 <= j; j--){
                if(bit>>j & 1) continue;
                for(int k = 0; k < p[j]; k++){
                    score += 100*(j+1);
                    total++;
                    if(G <= score) break;
                }
                if(G <= score) break;
            }
        }

        res = min(res, total);
        //cout << "score = " << score << endl;
        //cout << "total = " << total << endl;

    }

    cout << res << endl;

    return 0;
}