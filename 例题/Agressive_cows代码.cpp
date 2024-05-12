#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N, C;
	scanf("%d %d", &N, &C);
	int* a = new int[N];
	for (int i = 0;i < N;i++)
		scanf("%d", &a[i]);
	sort(a, a + N);  //ʹ��sort������ʼλ�õĵ�����������λ�õĵ�������
	int L = 1, R = (a[N - 1] - a[0]) / (C - 1);
	int D = (L + R) / 2;
	int j = 1;
	int result = 0;  //������һ��result�����������ΪD��ÿ��ѭ��֮���ֻ�ı�
	//cout<<L<<' '<<R;
	while (L <= R) {
		j = 1;
		int k = 0;
		for (int i = k + 1;i < N;++i) {
			if (a[i] - a[k] >= D) {
				j++;
				k = i;
				//cout << a[i] << ' ' << j<<endl;
			}
		}
		if (j >= C) {   //����Ҫ��j==C���������
			result = D;   //ֻ��Ҫ��result�ڴ˴����¼��ɣ�
			L = D + 1;
		}
		else if (j < C) {
			R = D - 1;
		}
		D = (L + R) / 2;
		//cout << result << ' ' << L << ' ' << R << ' ' << D << endl;
		//cout << j << ' ' << D << endl;
	}
	cout << result;
	return 0;
}