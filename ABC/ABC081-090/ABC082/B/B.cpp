#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string s, t;
  bool flag = false;

  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  if(s.size() < t.size()){
    for(int i = 0; i < s.size(); i++){
      if(s[i] != t[i]) flag = false;
      else flag = true;
    }
  }

  int r = min(s.size(), t.size());
  for(int i = 0; i < r; i++){
    if(s[i] == t[i]) continue;
    if(s[i] > t[i]){
      flag = false;
      break;
    }else{
      flag = true;
      break;
    }
  }

  if(s == t) flag = false;

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}

/**
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	string t;
	cin >> t;
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());

	if (s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
}
**/
