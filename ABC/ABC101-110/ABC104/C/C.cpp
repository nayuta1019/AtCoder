//　未完成
/**
 たぶんiは小さいがコンプリートボーナスが大きいときに対応できてない
コンプリートしたときのtotalスコアが大きいかつ解く問題数が少ないiから選ん
でいく？

**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){

  int D, G, ans = INT_MAX, p[100], c[100];

  cin >> D >> G;

  for(int i = 1; i <= D; i++) cin >> p[i] >> c[i];
  
  //  ボーナスなし
  for(int i = 1; i <= D; i++){
    int cnt = 0;
    int total = 0;
    for(int j = 0; j < p[i]; j++){
      if(G <= total) break;
      total += i * 100;
      cnt++;
    }
    if(G <= total && cnt < ans) ans = cnt;
  }
  /**
  if(ans < INT_MAX){
    cout << ans << endl;
    return 0;
  }
  **/

  // 全部解く(ボーナスあり)
  for(int i = 1; i <= D; i++){
    int cnt = p[i];
    int total = p[i] * i * 100 + c[i];
    if(G <= total && cnt < ans) ans = cnt;
  }
  
  if(ans < INT_MAX){
    cout << ans << endl;
    return 0;
  }

  //  まずtotalスコアが
  //  中途半端に解く問題があればそれは一番配点が高い問題
  int cnt = 0;
  int total = 0;
  for(int i = D-1; 0 < i; i--){
    cnt += p[i+1];
    total += p[i+1] * (i+1) * 100 + c[i+1];
    //cout << cnt << " " << total << endl;
    int k = 0;
    int t = 0;
    for(int j = 0; j < p[i]; j++){
      if(G <= total + t) break;
      //cout << cnt+k << " " << total+t << endl;
      t += i * 100;
      k++;
    }
    if(k == p[i]) t += c[i];
    if(G <= (total + t) && (cnt + k) < ans) ans = cnt + k;

  }

  cout << ans << endl;

  return 0;
}
