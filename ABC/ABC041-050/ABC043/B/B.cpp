#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  string s;
  vector<int> v;

  cin >> s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == '0') v.push_back(0);
    else if(s[i] == '1') v.push_back(1);
    else if(!v.empty())v.pop_back();
  }

  for (int i : v) cout << i;
  cout << endl;

  return 0;

}
