#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string s, ans="";

  cin >> s;

  ans += s[0];
  ans += to_string(s.size()-2);
  ans += s[s.size()-1];

  cout << ans << endl;

	return 0;
}
