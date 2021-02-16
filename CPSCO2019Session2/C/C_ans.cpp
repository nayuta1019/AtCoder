#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
Int n;
Int a[100];
Int ans=1e9;
Int calc(Int x){
  Int res=0;
  while(x){
    Int y=x%10;
    if(y>=5) y-=5,res++;
    res+=y;
    x/=10;
  }
  return res;
}
void dfs(Int x,Int y,Int s){
  if(y==0){
    chmin(ans,calc(s));
    return;
  }
  if(x==n) return;
  dfs(x+1,y,s);
  dfs(x+1,y-1,s+a[x]);  
}
signed main(){
  Int k;
  cin>>n>>k;
  for(Int i=0;i<n;i++) cin>>a[i];
  dfs(0,k,0);
  cout<<ans<<endl;
  return 0;
}
