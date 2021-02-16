/**
2018/11/02/ 解説AC。ボーナス点解法
式を変形して考える。O(N)の計算量
**/
#include <iostream>
#include <algorithm>

using namespace std;
 
int main()
{
    long long n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;
 
    long long cost = a * n;
 
    for (int x = 0; x <= n; ++x)
    {
        long long y;
        if ((n - x) * e - h - b * x <= 0) y = 0;
        else y = ((n - x) * e - h - b * x) / (d + e) + 1;
        if (x + y <= n) cost = min(cost, a * x + c * y);
    }
 
    cout << cost << endl;
    return 0;
}