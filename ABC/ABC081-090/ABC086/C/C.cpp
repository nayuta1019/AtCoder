#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;
 
int main() {
    int N;
    int t[110000], x[110000], y[110000];
    cin >> N;
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i < N+1; i++) cin >> t[i] >> x[i] >> y[i];

    bool flag = true;
    for (int i = 1; i < N+1; i++) {
        int dt = t[i] - t[i-1];
        int dist = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        if (dt < dist) flag = false;
        if (dist % 2 != dt % 2) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}