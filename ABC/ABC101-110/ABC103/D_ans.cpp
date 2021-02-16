#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
pair<int, int> p[100005];
int ta;

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].second, &p[i].first);
	sort(p, p + n);
	ans = 1;
	ta = p[0].first;
	for (int i = 1; i < n; i++)
		if (p[i].second >= ta) {
			ans++;
			ta = p[i].first;
		}
	printf("%d\n", ans);
	return 0;
}
