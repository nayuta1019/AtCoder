 #include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main() {
    int N;
    long long int a[11000];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    int ans = 0;

    for(int i = 0; i < N; i++){

        if(a[i] % 2) continue;
        
        while(a[i] % 2 == 0){
            ans++;
            a[i] /= 2;
        }
 
    }
    
    cout << ans << endl;

	return 0;
}