#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<cmath>
using namespace std;
/*二分法：
1.先L=0,R=总长度，len=（L+R）/2假设为最长可能的最短跳跃距离
2.从起点开始，下一个位置距离上一个小于 len 则去掉块数 cnt++，直到距离>=len，此处更新为下一个起始点，以此类推
3.比较 cnt 和 M，若大了则说明len大了，更新R-1；反之更新L+1
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