/**
2018/11/11/ 解説用
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

    pair<int, int> a[N + 2];
    a[0].first = 0;
    a[1].first = 0;
    for(int i = 2; i <= N; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + N + 2);
    reverse(a, a + N + 2);

    int sal[N + 1][2] = {};
    for(int i = 0; i < N - 1; ++ i){
        int m = sal[a[i].second][0] + sal[a[i].second][1] + 1;
        if(i == 0 || a[i].first != a[i - 1].first){
            sal[a[i].first][0] = m;
            sal[a[i].first][1] = m;
        }else{
            if(m > sal[a[i].first][0]) sal[a[i].first][0] = m;
            if(m < sal[a[i].first][1]) sal[a[i].first][1] = m;
        }
    }

    cout << sal[1][0] + sal[1][1] + 1 << endl;

    return 0;
}