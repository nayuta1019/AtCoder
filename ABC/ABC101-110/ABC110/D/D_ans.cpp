#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
 
 
long mod = 1000000007;
 
//aのp乗を求めるアルゴリズム
//p=62の時、pの変化は、62->31->30->15->14->7->6->3->2->1->0
//と、半分半分になっていく
//よって、計算量はO(logp)になる
long modpow(long a, int p) {
	if (p == 0) return 1;
	if (p % 2 == 0) {
		//pが偶数の時
		int halfP = p / 2;
		long half = modpow(a, halfP);
		//a^(p/2) をhalfとして、half*halfを計算
		return half * half % mod;
	}
	else {
		//pが奇数の時は、
		//pを偶数にするために1減らす
		return a * modpow(a, p - 1) % mod;
	}
}
 
 
//(10*9*8)/(3*2*1);
//10*9*8 -> ansMul
//3*2*1 -> ansDiv
long calcComb(int a, int b) {
	if (b > a - b) return calcComb(a, a - b);
 
 
	long ansMul = 1;
	long ansDiv = 1;
	for (int i = 0; i < b; i++)
	{
		ansMul *= (a - i);
		ansDiv *= (i + 1);
		ansMul %= mod;
		ansDiv %= mod;
	}
	//ansMul / ansDivをやりたい
	//ansDivの逆元を使って求めよう！
 
	long ans = ansMul * modpow(ansDiv, mod - 2) % mod;
	return ans;
}
 
 
int main() {
	int N, M;
	cin >> N >> M;
 
	int MNokori = M;
	long ans = 1;
	for (int i = 2; i * i <= MNokori; i++)
	{
		if (MNokori % i == 0) {
			int cnt = 0;
			while (MNokori % i == 0) {
				cnt++; MNokori /= i;
			}
			//cntが2^Xとか3^XのXの部分
			ans *= calcComb(N + cnt - 1, N - 1); //N-1はcntと同じ
			ans %= mod;
		}
	}
	if (MNokori != 1) {
		//最後に素数が残ってる分を処理する
		ans *= calcComb(N + 1 - 1, N - 1); //N-1はcntと同じ
		ans %= mod;
	}
 
	cout << ans << endl;
}