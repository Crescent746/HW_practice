#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int main() {
	int move[9];  //记录每种移动的次数
	int best[9];
	int mincount = 999999;
	memset(move, 0, sizeof(move));
	int num[9]; //每个钟的点数
	for (int i = 0;i < 9;i++) cin >> num[i];
	int sum = 0; ///所有时钟的总点数
	for (move[0] = 0;move[0] < 4;move[0]++)
		for (move[1] = 0;move[1] < 4;move[1]++)
			for (move[2] = 0;move[2] < 4;move[2]++)
				for (move[3] = 0;move[3] < 4;move[3]++)
					for (move[4] = 0;move[4] < 4;move[4]++)
						for (move[5] = 0;move[5] < 4;move[5]++)
							for (move[6] = 0;move[6] < 4;move[6]++)
								for (move[7] = 0;move[7] < 4;move[7]++)
									for (move[8] = 0;move[8] < 4;move[8]++) {
										sum = 0;
										sum += (num[0] + move[0] + move[1] + move[3]) % 4;
										sum += (num[1] + move[0] + move[1] + move[2] + move[4]) % 4;
										sum += (num[2] + move[1] + move[2] + move[5]) % 4;
										sum += (num[3] + move[0] + move[3] + move[4] + move[6]) % 4;
										sum += (num[4] + move[0] + move[2] + move[4] + move[6] + move[8]) % 4;
										sum += (num[5] + move[2] + move[4] + move[5] + move[8]) % 4;
										sum += (num[6] + move[3] + move[6] + move[7]) % 4;
										sum += (num[7] + move[4] + move[6] + move[7] + move[8]) % 4;
										sum += (num[8] + move[5] + move[7] + move[8]) % 4;
										if (sum == 0) {
											int count = 0;
											for (int j = 0;j < 9;++j) count += move[j];
											if (count < mincount) {
												mincount = count;
												memcpy(best, move, sizeof(move));
											}
											for (int j = 0;j < 9;++j) {
												while (best[j]--) {
													cout << j + 1 << ' ';
												}
											}

										}
									}

	return 0;
}