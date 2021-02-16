/**
2018/11/23/ 解説用
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int a[3][3];
int b[2][3], c[3][2];

int dfs(int x){

    if(x == 10){
        int score = 0;
        for(int i = 0; i < 2; ++ i)
            for(int j = 0; j < 3; ++ j)
                if(a[i][j] == a[i + 1][j])
                    score += b[i][j];

        for(int i = 0; i < 3; ++ i)
            for(int j = 0; j < 2; ++ j)
                if(a[i][j] == a[i][j + 1])
                    score += c[i][j];

        return score;
    }

    int tmp;
    if(x & 1) tmp = 0;
    else tmp = 2e9;

    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < 3; ++ j){
            if(a[i][j] != 0) continue;

            a[i][j] = (x % 2 ? 1 : -1);
            if(x & 1) tmp = max(tmp, dfs(x + 1));   //直大君のスコアを最大化
            else tmp = min(tmp, dfs(x + 1));    //直子さんのスコアを最小化
            a[i][j] = 0;
        }
    }
    return tmp;
}

int main(){
    int sum = 0;
    for(int i = 0; i < 2; ++ i){
        for(int j = 0; j < 3; ++ j){
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < 2; ++ j){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    int score = dfs(1);

    cout << score << endl;
    cout << sum - score << endl;

    return 0;
}