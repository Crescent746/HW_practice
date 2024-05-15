#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<cmath>
using namespace std;
/*���ַ���
1.��L=0,R=�ܳ��ȣ�len=��L+R��/2����Ϊ����ܵ������Ծ����
2.����㿪ʼ����һ��λ�þ�����һ��С�� len ��ȥ������ cnt++��ֱ������>=len���˴�����Ϊ��һ����ʼ�㣬�Դ�����
3.�Ƚ� cnt �� M����������˵��len���ˣ�����R-1����֮����L+1
*/

int main() {
	int Len, N, M;
	cin >> Len >> N >> M;
	int* d = new int[N+2];
	for (int i = 1;i <= N;i++) cin >> d[i];
	d[0] = 0;
	d[N+1] = Len;
	int L = 0, R = Len, len = (L + R) / 2;
	int cnt = 0, f = 0, result;
	while (L<=R) {
		cnt = 0;
		f = 0;
		for (int i = 1;i <= N + 1;i++) {
			if (d[i] - d[f] < len) {
				cnt++;
			}
			else f = i;
		}
		if (cnt > M) R =len- 1;
		if (cnt <= M) {
			L =len+1;
			result = len;
		}
		len = (L + R) / 2;
	}
	cout << result;
	return 0;
}