#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<cmath>
using namespace std;
/*二分法：
1.求总体积/人数=估计每块大小S
2.再用每个派/每块估计值 求和 =实际能给多少人
3.用二分法，L=0，R=S ，每次（R+L）/2
4.若少了，则说明每块估计值大了，更新R；反之多了则为每块估计值小了，更新L
*/
const double Pi = acos(-1.0); //求Pi的常用方法：arccos（-1）=Pi （注意double类型）
int main() {
	int N, F;
	cin >> N >> F;
	int* r = new int[N];
	double* s = new double[N];
	double S = 0;
	for (int i = 0;i < N;i++) {
		cin >> r[i];
		s[i] = Pi * r[i] * r[i];
		S += s[i];
	}
	double L = 0, R = double(S) / (F + 1);
	double perS = (L + R) / 2, result = 0;
	int cnt = 0;
	while (R - L > 1e-6) {
		cnt = 0;
		for (int i = 0;i < N;i++) {
			cnt += s[i] / perS;
		}
		if (cnt >= F + 1) {
			L = perS;
			result = perS;
		}
		if (cnt < F + 1) R = perS;
		perS = (L + R) / 2;
	}
	cout << fixed << setprecision(3) << result;
	return 0;
}