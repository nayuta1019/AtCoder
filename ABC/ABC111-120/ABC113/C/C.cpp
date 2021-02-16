/**
ABC113
2018/11/04/ 未完成
2018/12/11/ 解説AC
**/
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
    int N, M;
    cin >> N >> M;
    tuple<int, int, int> T[M];
    for(int i = 0; i < M; i++){
        int p, y;
        cin >> p >> y;
        T[i] = make_tuple(y, p, i);
    }
    sort(T, T+M);

    int cnt[N+1];
    fill(cnt, cnt+N+1, 0);

    pair<int, int> id[M];

    for(int i = 0; i < M; i++){
        int y, p, idx;
        tie(y, p, idx) = T[i];
        cnt[p]++;
        id[idx] = make_pair(p, cnt[p]);
    }

    for(int i = 0; i < M; i++){
        cout << setw(6) << setfill('0') << id[i].first;
        cout << setw(6) << setfill('0') << id[i].second << endl; 
    }

    return 0;
}