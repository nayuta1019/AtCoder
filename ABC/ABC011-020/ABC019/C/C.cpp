#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    set<int> st;
	for(int i = 0; i < N; i++){
		while(a[i] % 2 == 0) a[i] /= 2;
		st.insert(a[i]);
	}
	cout << st.size() << endl;

    return 0;
}
