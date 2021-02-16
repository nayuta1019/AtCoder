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

int main(){
    int N,D,K;
    cin >> N >> D >> K;
    vector<pair<int,int>> days(D);
    vector<pair<int,int>> kingdoms(K);
    for(int i = 0; i < D; i++) cin >> days[i].first >> days[i].second ;
    for(int i = 0; i < K; i++) cin >> kingdoms[i].first >> kingdoms[i].second;

    for(int i = 0; i < K; i++){
        int current = kingdoms[i].first;
        int goal = kingdoms[i].second;
        for(int j = 0; j < D; j++){
            int l = days[j].first;
            int r = days[j].second;
            //移動完了
            if( l <= current && current <= r && l <= goal && goal <= r){
                cout << j + 1 << endl;
                break;
            }else if( l <= current && current <= r ){
                if(abs(current - goal) > abs(r - goal)) current = r;
                if(abs(current - goal) > abs(l - goal)) current = l;
            }
        }
    }
    
    return 0;
}