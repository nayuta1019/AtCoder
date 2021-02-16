#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
    vector<int> par;
    vector<int> sz;
    long long ans;

    UnionFind(int n = 0){
        if(n > 0) initialize(n);
    }

    void initialize(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }

        ans = (long long)(n * (n-1) / 2);
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        ans -= (long long)(sz[x] * sz[y]);

        if(sz[x] < sz[y]){
            par[x] = y;
            sz[y] += sz[x];
        }else{
            par[y] = x;
            sz[x] += sz[y];
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){

    int N, M, A[100005], B[100005];
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    UnionFind uf(N);
    long long ans[100000];
    for(int i = M-1; i>= 0; i--){
        ans[i] = uf.ans;
        uf.unite(A[i], B[i]);
    }

    for(int i = 0; i < M; i++) cout << ans[i] << endl;

    return 0;
}