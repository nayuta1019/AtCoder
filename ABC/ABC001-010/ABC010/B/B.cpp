/**
2018/11/04/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

 
int main(){
    int n, a[10];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++){

        while( a[i]%3 == 2 || a[i]%2 == 0 ){
            a[i]--;
            ans++;

        }
        
    }

    cout << ans << endl;

    return 0;
}