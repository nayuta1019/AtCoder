/**
ABC057
2018/12/20/ 解説AC
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

ll C[51][51];

void comb_table(int N){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                C[i][j] = 1LL;
            }else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
}

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    const int NMAX = 50;
    ll v[NMAX];

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    comb_table(N);
    sort(v, v+N);
    reverse(v, v+N);

    double max_average = 0.0;
    for(int i = 0; i < A; i++){
        max_average += v[i];
    }
    max_average /= A;

    int a_th_val_num = 0, a_th_val_pos = 0;
    for(int i = 0; i < N; i++){
        if(v[i] == v[A-1]){
            a_th_val_num++;
            if(i < A){
                a_th_val_pos++;
            }
        }
    }

    ll cnt = 0LL;
    if(a_th_val_pos == A){
        for(a_th_val_pos = A; a_th_val_pos <= B; a_th_val_pos++){
            cnt += C[a_th_val_num][a_th_val_pos];
        }
    }else{
        cnt += C[a_th_val_num][a_th_val_pos];
    }

    cout.precision(20);
    cout << fixed << max_average << endl;
    cout << cnt << endl;

    return 0;
}