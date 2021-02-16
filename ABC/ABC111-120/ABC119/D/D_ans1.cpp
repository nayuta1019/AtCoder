#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void chmin(long long &a, long long b){if(a > b) a = b;}
const long long INF = 1LL<<58;

// vector v において、xの前方と後方のindexを求める
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main(){
    int A, B, Q; cin >> A >> B >> Q;
    vector<long long> s(A), t(B);
    for(int i = 0; i < A; i++) cin >> s[i];
    for(int i = 0; i < B; i++) cin >> t[i];
    s.push_back(INF); s.push_back(-INF); sort(s.begin(), s.end());
    t.push_back(INF); t.push_back(-INF); sort(t.begin(), t.end());

    for(int _ = 0; _ < Q; _++){
        long long x; cin >> x;
        long long res = INF;

        // 最初に s (前方に行くか後方に行くか場合分け)
        for(int i = 0; i < 2; i++){
            long long first = (i ? s[former(s, x)] : s[latter(s, x)]);

            // 次に t (現在の前後を見る)
            for(int j = 0; j < 2; j++){
                long long second = (j ? t[former(t, first)] : t[latter(t, first)]);
                chmin(res, abs(x - first) + abs(first - second));
            }
        }

        // 最初に t (前方に行くか後方に行くか場合分け)
        for(int i = 0; i < 2; i++){
            long long first = (i ? t[former(t, x)] : t[latter(t, x)]);

            // 次に t (現在地の前後を見る)
            for(int j = 0; j < 2; j++){
                long long second = (j ? s[former(s, first)] : s[latter(s, first)]);
                chmin(res, abs(x - first) + abs(first - second));
            }
        }
        cout << res << endl;
    }
    
    return 0;
}