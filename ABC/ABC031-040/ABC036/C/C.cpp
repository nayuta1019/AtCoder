/**
2018/11/07/ 自力AC
pair<int, int>を二回使てソート。mapを使えばもう少しきれいに書けるかも。
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
    vector<pair<int, int>> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<pair<int, int>> b(N);
    int bnum = 0;
    int tmp = a[0].first;

    for(int i = 1; i < N; i++){
        
        if(tmp == a[i].first){
            tmp = a[i].first;

            b[i].first = a[i].second;
            b[i].second = bnum;

            b[i-1].first = a[i-1].second;
            b[i-1].second = bnum;

        }else{
            tmp = a[i].first;

            b[i-1].first = a[i-1].second;
            b[i-1].second = bnum;
            bnum++;
            b[i].first = a[i].second;
            b[i].second = bnum;
        }
    }
    
    sort(b.begin(), b.end());

    for(int i = 0; i < N; i++){
        cout << b[i].second << endl;
    }

    return 0;
}