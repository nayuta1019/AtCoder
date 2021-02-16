/**
ABC064
2018/12/28/ 解説用
author:Mayimg
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
    int n;
    string s;
    cin >> n >> s;

    stack<char> st;
    for(int i = 0; i < n; i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == '('){
            if(s[i] == ')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
            continue;
        }
        if(st.top() == ')'){
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        char tmp = st.top();
        st.pop();
        if(tmp == '('){
            s.push_back(')');
        }else{
            s.insert(s.begin(), '(');
        }
    }

    cout << s << endl;

    return 0;
}