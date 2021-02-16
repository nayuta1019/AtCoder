#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

const int MAX = 100000;

int main(){
	int N;
	long long K, cnt[MAX+1] = {0};

	cin >> N >> K;

	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		cnt[a] += b;
	}

	for(int i = 1; i <= MAX; i++){
		if(K <= cnt[i]){
			cout << i << endl;
			break;
		}
		K -=cnt[i];
	}

	return 0;
}