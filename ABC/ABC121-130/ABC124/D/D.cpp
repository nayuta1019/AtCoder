/**
ABC124
2019/04/15/ 自力AC
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    vector< pair<int, int> > islands;
    int b = 0, w = 0;
    rep(i, N){
        if(s[i] == '0'){
            if(w == 0) b++;
            else{
                pair<int, int> p(w, 1);
                islands.push_back(p);
                b++;
                w = 0;
            }
        }else{
            if(b == 0) w++;
            else{
                pair<int, int> p(b, 0);
                islands.push_back(p);
                w++;
                b = 0;
            }
        }

        if(i == N-1){
            if(b != 0){
                pair<int, int> p(b, 0);
                islands.push_back(p);
            }else{
                pair<int, int> p(w, 1);
                islands.push_back(p);
            }
        }
    }

    int r = 0, ans = 0, sum = 0, kk = 0;
    for(int l = 0; l < islands.size(); l++){
        while(kk < K && r < islands.size()){
            if(islands[r].second == 0){
                kk++;
                sum += islands[r].first;
            }else{
                sum += islands[r].first;
            }
            r++;
        }
        if(r < islands.size()) sum += islands[r].first;
        ans = max(ans, sum);
        if(islands[l].second == 0) kk--;
        sum -= islands[l].first;
        if(r < islands.size()) sum -= islands[r].first;
    }

    cout << ans << endl;

    return 0;
}