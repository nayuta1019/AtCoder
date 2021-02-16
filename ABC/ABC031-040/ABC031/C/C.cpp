/**
2018/11/10/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    int ans = -50*50;
    for(int takahashi = 0; takahashi < N; takahashi++){
        int amax = -50*50, tmax = -50*50;
        
        for(int aoki = 0; aoki < N; aoki++){
            if(takahashi == aoki) continue;

            int t_sum = 0, a_sum = 0;

            for(int i = min(takahashi, aoki); i <= max(takahashi, aoki); i+=2){
                t_sum += a[i];
                if( i+1 <= max(takahashi, aoki) ) a_sum += a[i+1];
            }

            if(amax < a_sum){
                amax = a_sum;
                tmax = t_sum;
            }

        }

        if(ans < tmax) ans = tmax;

    }

    cout << ans << endl;

    return 0;
}