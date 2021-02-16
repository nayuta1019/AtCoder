/**
KEYENCEPC2019
2019/01/13/ 自力AC
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
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    ll total = 0;
    rep(i, N){
        cin >> A[i];
        total += A[i];
    }
    rep(i, N) cin >> B[i];

    ll ans = 0, aa = 0, bb = 0;
    vector<ll> dis;//たりない分
    vector<ll> amari;//余る分
    rep(i, N){
        if(A[i] < B[i]){
            bb += B[i] - A[i];
            dis.push_back(B[i] - A[i]);
            ans++;
        }else if(B[i] < A[i]){
            aa += A[i] - B[i];
            amari.push_back(A[i] - B[i]);
        }
    }
    sort(dis.begin(), dis.end());
    sort(amari.begin(), amari.end(), greater<ll>());

    if(bb == 0){
        cout << 0 << endl;
        return 0;
    }
    if(aa < bb){
        cout << -1 << endl;
        return 0;
    }else{
        ans++;
        int i = 0, j = 0;
        while(j < dis.size()){

            if(amari[i] < dis[j]){
                ans++;
                dis[j] -= amari[i];
                i++;
            }else{
                
                amari[i] -= dis[j];
                j++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}