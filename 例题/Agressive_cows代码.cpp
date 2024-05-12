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
	sort(a, a + N);  //使用sort：（起始位置的迭代器，结束位置的迭代器）
	int L = 1, R = (a[N - 1] - a[0]) / (C - 1);
	int D = (L + R) / 2;
	int j = 1;
	int result = 0;  //单独设一个result用于输出，因为D在每次循环之后又会改变
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
		if (j >= C) {   //不需要把j==C单独拎出来
			result = D;   //只需要将result在此处更新即可！
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