#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  string N;
  int ans, total = 0;
  istringstream ss;

  cin >> N;

  for(int i = 0; i < N.size(); i++) total += N[i] - '0';

  ss = istringstream(N);
  ss >> ans;

  if(ans % total == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

	return 0;
}
/**
# include < cstdio >
int N ;
int main ()
{
  scanf ("% d " ,& N );
  int t =N , c =0;
  while (t >0) c += t %10 , t /=10;
  if ( N % c ==0) puts (" Yes ");
  else puts (" No ");
}
**/
