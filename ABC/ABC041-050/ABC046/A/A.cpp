#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    int a, b, c, ans=0;

    cin >> a >> b >> c;

    if(a == b && b == c) ans = 1;
    else if(a == b && a != c) ans = 2;
    else if(a == c && a != b) ans = 2;
    else if(b == c && b != a) ans = 2;
    else ans = 3;

    cout << ans << endl;

	return 0;
}