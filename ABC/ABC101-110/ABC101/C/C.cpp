#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;
 
int main() {
    int N, K, x[110000];

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> x[i];

    long long int r, l, ans = INT_MAX;
    for(int i = 0; i < N - K + 1; i++){
        l = x[i]; r = x[i+K-1];

        long long int val = min(abs(l) + abs(r-l), abs(r) + abs(r-l));

        if(val < ans) ans = val;
    }

    cout << ans << endl;

	return 0;
}