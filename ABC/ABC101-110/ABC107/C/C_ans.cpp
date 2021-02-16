#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int inf = 1e9 + 7;

#define nd second
#define st first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 6;
const int logN = 17;

int n, k, x;
vector< int > v1, v2;

int main() {

	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if(x < 0) {
			v1.pb(-x);
		}
		else if(x > 0) {
			v2.pb(x);
		}
		else k--;
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if(k <= 0) {
		cout << 0 << endl;
		return 0;
	}

	int ans = inf;

	for(int i = 0; i <= k; i++) {
		int t1 = i - 1;
		int t2 = k - i - 1;
		int c1 = 0, c2 = 0, cur = 0;
		if(t1 >= (int)v1.size()) continue;
		if(t2 >= (int)v2.size()) continue;
		if(t1 >= 0) c1 = v1[t1];
		if(t2 >= 0) c2 = v2[t2];
		ans = min(ans, c1 + c2 + min(c1, c2));
	}

	cout << ans << endl;

	return 0;
}
