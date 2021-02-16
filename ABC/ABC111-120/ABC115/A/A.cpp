/**
ABC115
2018/12/08/ 初見AC
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
    int d;
    cin >> d;
    if(d == 25){
        cout << "Christmas" << endl;
    }else if(d == 24){
        cout << "Christmas Eve" << endl;
    }else if(d == 23){  
        cout << "Christmas Eve Eve" << endl;
    }else if(d == 22){
        cout << "Christmas Eve Eve Eve" << endl;
    }

    return 0;
}