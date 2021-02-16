#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int n, mem[100001], v[100001]={0}, max_v=0, min_v=INT_MAX;

  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    mem[i] = x;
    v[x] += 1;
    if(max_v < x) max_v = x;
    if(x < min_v) min_v = x;
  }

  int r1=0, r2=0;
  int m1=0, m2=0;
  for(int i = min_v; i <= max_v; i++){
    if(r2 <= v[i]){
      r2 = v[i];
      m2 = i;
      if(r1 < r2){
        int tmp = r1;
        r1 = r2;
        r2 = tmp;
        int tm = m1;
        m1 = m2;
        m2 = tm;
      }
    }
  }

  int p1=0, p2=0, ans1=0;
  for(int i = 0; i < n; i+=2){
    if(mem[i] != m1) p1++;
    if(mem[i+1] != m2) p2++;
  }
  ans1 = p1 + p2;

  int q1=0, q2=0, ans2=0;
  for(int i = 0; i < n; i+=2){
    if(mem[i] != m2) q1++;
    if(mem[i+1] != m1) q2++;
  }
  ans2 = q1 + q2;

  //cout << ans1 << " " << ans2 << endl;

  if(ans1 < ans2) cout << ans1 << endl;
  else cout << ans2 << endl;

/**

  cout << ans << endl;
  cout << m1 << " " << m2 << endl;
  cout << r1 << " " << r2 << endl;

  **/

	return 0;
}
