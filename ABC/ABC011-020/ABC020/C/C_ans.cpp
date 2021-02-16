/**
ABC020
2018/12/17/ 解説AC
ダイクストラ法
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
typedef tuple<int, int, int> T;
typedef tuple<int, int, int, int> TT;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int h, w, t;
int sy, sx, gy, gx;
char s[20][20];

bool dijkstra(int m){
    int dist[20][20];
    priority_queue< T, vector<T>, greater<T> > q;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            dist[i][j] = INF+1;
        }
    }

    dist[sy][sx] = 0;
    q.push(T(0, sy, sx));
    while( !q.empty() ){
        int c, y, x;
        tie(c, y, x) = q.top();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= nx && nx < w && 0 <= ny && ny < h){
                if(s[ny][nx] == '#'){
                    if( c+m < dist[ny][nx] ){
                        dist[ny][nx] = c + m;
                        q.push(make_tuple(c+m, ny, nx));
                    }
                }else{
                    if( c+1 < dist[ny][nx] ){
                        dist[ny][nx] = c + 1;
                        q.push(make_tuple(c+1, ny, nx));
                    }
                }
            }
        }
    }

    if(dist[gy][gx] <= t) return true;
    else return false;
}

int main(){
    cin >> h >> w >> t;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            
            cin >> s[i][j];
            if(s[i][j] == 'S'){
                sy = i;
                sx = j;
            }
            if(s[i][j] == 'G'){
                gy = i;
                gx = j;
            }
        }
    }

    int l = 0, h = INF;
    for(int i = 0; i < 100; i++){
        int mid = (l + h) / 2;
        if(dijkstra(mid)){
            l = mid;
        }else{
            h = mid;
        }
    }

    cout << l << endl;

    return 0;
}
