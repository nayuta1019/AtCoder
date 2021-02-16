/**
2018/12/02/ 未完成
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

    int cnt = 0, tmp = N;
    while(0 < tmp){
        tmp /= 10;
        cnt++;
    }

    int ans = 0;

    if(cnt <= 3){
        for(int i = 100; i <= N; i++){
            int t = i;
            bool flag3 = false, flag5 = false, flag7 = false, flag = true;
            while(0 < t){
                int a = t % 10;
                t /= 10;
                if(a == 3) flag3 = true;
                else if(a == 5) flag5 = true;
                else if(a == 7) flag7 = true;
                else flag = false;
            }

            if(flag3 && flag5 && flag7 && flag){
                ans++;
            }
        }

    }else{
        int p = 1;
        for(int i = 1; i < cnt; i++) p *= i;

        if(N <= 3*pow(10, cnt-1)){
            ans = 1;
            for(int i = 1; i < cnt; i++) ans *= i;

        }else if(N <= 4*pow(10, cnt-1)){
            for(int i = 3*pow(10, cnt-1); i <= N; i++){
                int t = i;
                bool flag3 = false, flag5 = false, flag7 = false, flag = true;
                while(0 < t){
                    int a = t % 10;
                    t /= 10;
                    if(a == 3) flag3 = true;
                    else if(a == 5) flag5 = true;
                    else if(a == 7) flag7 = true;
                    else flag = false;
                }

                if(flag3 && flag5 && flag7 && flag){
                    ans++;
                }
            }
            ans += p;
        
        }else if(N <= 6*pow(10, cnt-1) ){
            for(int i = 5*pow(10, cnt-1); i <= N; i++){
                int t = i;
                bool flag3 = false, flag5 = false, flag7 = false, flag = true;
                while(0 < t){
                    int a = t % 10;
                    t /= 10;
                    if(a == 3) flag3 = true;
                    else if(a == 5) flag5 = true;
                    else if(a == 7) flag7 = true;
                    else flag = false;
                }

                if(flag3 && flag5 && flag7 && flag){
                    ans++;
                }
            }
            int q = 1;
            for(int i = 1; i < cnt-1; i++) q *= i;
            ans = 2*q - ans;
            ans += p;


        }else if(N <= 8*pow(10, cnt-1)){
            for(int i = 7*pow(10, cnt-1); i <= N; i++){
                int t = i;
                bool flag3 = false, flag5 = false, flag7 = false, flag = true;
                while(0 < t){
                    int a = t % 10;
                    t /= 10;
                    if(a == 3) flag3 = true;
                    else if(a == 5) flag5 = true;
                    else if(a == 7) flag7 = true;
                    else flag = false;
                }

                if(flag3 && flag5 && flag7 && flag){
                    ans++;
                }
            }
            int q = 1;
            for(int i = 1; i < cnt-1; i++) q *= i;
            cout << ans << endl;
            ans = 3*q - ans;
            ans += p;

        }else{
            ans = 1;
            for(int i = 1; i <= cnt; i++) ans *= i;
        }

    }

    cout << ans << endl;

    return 0;
}