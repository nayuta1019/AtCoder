/**
ABC068
2019/01/06/ 自力AC
binary_serch()使ってもいいかも
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> island;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        if(a == 1) island.push_back(b);
        if(b == N) island.push_back(a);
    }

    sort(island.begin(), island.end());
    int tmp = island[0];
    FOR(i, 1, island.size()){
        if(tmp == island[i]){
            cout << "POSSIBLE" << endl;
            return 0;
        }else{
            tmp = island[i];
        }
    }
    
    cout << "IMPOSSIBLE" << endl;

    return 0;
}