#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;						// to be set
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.sssign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int N, M, Q;
typedef pair<int,int> pint;
typedef pair<pint,int> ipint;
vector<ipint> ins;
vector<int> alts;

bool cmp(ipint a, ipint b) {
    return make_pair(a.first.second, a.second) < make_pair(b.first.second, b.second);
}

int main() {
    // 入力受け取り、区間終点ソート、座標圧縮
    cin >> N >> M >> Q;
    ins.resize(M + Q);
    alts.clear();
    for (int i = 0; i < M + Q; ++i) {
        cin >> ins[i].first.first >> ins[i].first.second;
        ++ins[i].first.second;
        if (i < M) ins[i].second = -1; else ins[i].second = i - M;
        alts.push_back(ins[i].first.first), alts.push_back(ins[i].first.second);
    }
    sort(alts.begin(), alts.end());
    alts.erase(unique(alts.begin(), alts.end()), alts.end());
    sort(ins.begin(), ins.end(), cmp);
    
    // 座標圧縮
    for (int i = 0; i < M + Q; ++i) {
        int left = lower_bound(alts.begin(), alts.end(), ins[i].first.first) - alts.begin();
        int right = lower_bound(alts.begin(), alts.end(), ins[i].first.second) - alts.begin();
        ins[i].first.first = left + 1;
        ins[i].first.second = right + 1;
    }

    // 平面走査
    BIT<int> bit( (M+Q)*2 + 10 );
    vector<int> res(Q);
    for (int i = 0; i < M + Q; ++i) {
        if (ins[i].second == -1) bit.add(ins[i].first.first, 1);
        else res[ins[i].second] = bit.sum(ins[i].first.first, ins[i].first.second);
    }
    for (int i = 0; i < Q; ++i) cout << res[i] << endl;
}
