/**
2018/10/28/
lower_bound()とupper_bound()を使う

**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;
 
int main(){

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) cin >> b[i];
	
	for (int i = 0; i < n; i++) cin >> c[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	long long ans = 0;

	for (int i = 0; i < n; i++){

		long long  t = (lower_bound(a.begin(), a.end(), b[i]) - a.begin()); //  b[i]以上の最初の要素の位置をイテレータで返す

		long long  s =  n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());    //  b[i]より大きい最初の要素の位置

		ans += t * s;

	}

	cout << ans << endl;

	return 0;
 
}