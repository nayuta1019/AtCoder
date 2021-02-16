#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
  int A, B, C, flag = 0;

	cin >> A >> B >> C;

	for (int i = A; i <= A*B; i+=A) {
		if (i%B == C) {
			flag = 1;
			break;
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
