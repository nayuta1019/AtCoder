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
    int N;
    cin >> N;
    vector<pair<int,int> > pos(N);
    for(int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;

    double ans = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            double dist = sqrt( pow( (pos[i].first - pos[j].first), 2) + pow( (pos[i].second - pos[j].second), 2) );

            ans = max(ans, dist);
        }
    }

    cout << ans << endl;

    return 0;
}