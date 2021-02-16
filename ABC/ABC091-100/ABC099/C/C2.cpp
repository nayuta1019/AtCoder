/**
2018/11/30/ 未完成   
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
    int n;
    cin >> n;

    int cnt1 = 0, tmp1 = n;
    int p = 0;
    while(p != 1){
        p = 1;
        while(p * 6 < tmp1){
            p *= 6;
        }
        
        if(p != 1){
            tmp1 -= p;
            cnt1++;
        }
        cout << "p1 = " << p << endl;
        cout << "cnt1 = " << cnt1 << endl;
    }
    

    p = 0;
    while(p != 1){
        p = 1;
        while(p * 9 < tmp1){
            p *= 9;
        }
        cout << "p1 = " << p << endl;
        if(p != 1){
            tmp1 -= p;
            cnt1++;
        }
    }
    
    cout << "tmp1 = " << tmp1 << endl;
    while(9 <= tmp1){
        tmp1 -= 9;
        cnt1++;
    }
    while(6 <= tmp1){
        tmp1 -= 6;
        cnt1++;
    }

    cnt1 += tmp1;

    int cnt2 = 0, tmp2 = n;
    p = 0;
    while(p != 1){
        p = 1;
        while(p * 9 < tmp2){
            p *= 9;
        }
        cout << "p2 = " << p << endl;
        if(p != 1){
            tmp2 -= p;
            cnt2++;
        }
    }
    
    p = 0;
    while(p != 1){
        p = 1;
        while(p * 6 < tmp2){
            p *= 6;
        }
        cout << "p2 = " << p << endl;
        if(p != 1){
            tmp2 -= p;
            cnt2++;
        }
    }
    cout << "tmp2 = " << tmp2 << endl;

    while(9 <= tmp2){
        tmp2 -= 9;
        cnt2++;
    }
    while(6 <= tmp2){
        tmp2 -= 6;
        cnt2++;
    }

    cnt2 += tmp2;

    int ans = min(cnt1, cnt2);
    cout << ans << endl;

    return 0;
}