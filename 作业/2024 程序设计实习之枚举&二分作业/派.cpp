#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<cmath>
using namespace std;
/*���ַ���
1.�������/����=����ÿ���СS
2.����ÿ����/ÿ�����ֵ ��� =ʵ���ܸ�������
3.�ö��ַ���L=0��R=S ��ÿ�Σ�R+L��/2
4.�����ˣ���˵��ÿ�����ֵ���ˣ�����R����֮������Ϊÿ�����ֵС�ˣ�����L
*/
const double Pi = acos(-1.0); //��Pi�ĳ��÷�����arccos��-1��=Pi ��ע��double���ͣ�
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