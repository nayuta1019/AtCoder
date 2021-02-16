/**
2018/10/27/	自力AC
計算量の計算をしっかり！
**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
	long long int N, a[100];

	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];

	sort(a, a+N);

	long long int res = 1 << 21;
	for(int f = a[0]; f <= a[N-1]; f++){
		
		long long m = 0;
		for(int i = 0; i < N; i++){
			m += (a[i] - f) * (a[i] - f);
		}

		if(m < res) res = m;
	}

	

	cout << res << endl;

	return 0;
}