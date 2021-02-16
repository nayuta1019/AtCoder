#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)







class weighted_unionfind {
private:
    vector<int> par;
    vector<int> rank;
    vector<ll> diff_weight;
public:
    weighted_unionfind(int n) : rank(n), diff_weight(n) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
        }
    }
    
    int find(int x){
        if (par[x] == x) {
            return x;
        }
        else {
            int t = find(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = t;
        }
    }
    
    void unite(int x, int y, ll w){
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y)return;
        
        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }
        if(rank[x] == rank[y]){
            rank[x]++;
        }
        
        par[y] = x;
        diff_weight[y] = w;
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    ll weight(int x){
        find(x);
        return diff_weight[x];
    }
    
    ll diff(int x, int y){
        return weight(y) - weight(x);
    }
};




int main(){
    ll n, m;
    cin >> n >> m;
    
    weighted_unionfind uni(n);
    
    REP(i, m){
        ll l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        if(uni.same(l, r)){
            ll diff = uni.diff(l, r);
            if(diff != d){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            uni.unite(l, r, d);
        }
    }
    
    cout << "Yes" << endl;
}
