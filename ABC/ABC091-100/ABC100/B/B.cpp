#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int D, N;
	cin >> D >> N;

  int cnt = 0, ans = 0;
	while(cnt < N) {
		ans++;

    int ret = 0, val = ans;
  	while(val % 100 == 0) {
  		val /= 100;
  		ret++;
  	}

		if(ret == D) cnt++;
	}

  cout << ans << endl;

	return 0;
}
