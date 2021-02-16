/**
ABC062
2019/02/17/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    ll h, w;
    cin >> h >> w;

    ll ans = 1e12;
    for(ll i = 1; i < h; i++){
        ll Sa, Sb, Sc, Smax, Smin;
        Sa = i * w;
        Sb = ((h - i) / 2) * w;
        Sc = ((h - i) - ((h - i) / 2)) * w;
        Smax = max({Sa, Sb, Sc});
        Smin = min({Sa, Sb, Sc});
        ans = min(ans, Smax-Smin);

        Sa = i * w;
        Sb = (h - i) * (w / 2);
        Sc = (h - i) * (w - w / 2);
        Smax = max({Sa, Sb, Sc});
        Smin = min({Sa, Sb, Sc});
        ans = min(ans, Smax-Smin);
    }

    swap(h, w);
    for(ll i = 1; i < h; i++){
        ll Sa, Sb, Sc, Smax, Smin;
        Sa = i * w;
        Sb = ((h - i) / 2) * w;
        Sc = ((h - i) - ((h - i) / 2)) * w;
        Smax = max({Sa, Sb, Sc});
        Smin = min({Sa, Sb, Sc});
        ans = min(ans, Smax-Smin);

        Sa = i * w;
        Sb = (h - i) * (w / 2);
        Sc = (h - i) * (w - w / 2);
        Smax = max({Sa, Sb, Sc});
        Smin = min({Sa, Sb, Sc});
        ans = min(ans, Smax-Smin);
    }

    cout << ans << endl;

    return 0;
}