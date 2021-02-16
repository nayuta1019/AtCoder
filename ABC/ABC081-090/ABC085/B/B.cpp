#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
	int N, d[110], ans=1;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> d[i];

	sort(d, d+N);

	for(int i = 1; i < N; i++) if(d[i-1] != d[i]) ans++;

	cout << ans << endl;

	return 0;
}
