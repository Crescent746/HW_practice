#include<iostream>
#include<cstring>
#include<string.h>
#include<bitset>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	//bitset<30> begin(a), end(b);
	int cnt = 0;
	/*for (int i = a.length() - 1;i >= 0;i--) cout << begin[i];
	cout << endl;
	cout << begin.flip(0);*/
	for (int k = 0;k < 2;k++) {   ///////////ע��� ��0λ�Ƿ��� �������������
		cnt = 0;
		bitset<30> begin(a), end(b);
		for (int i = 0;i <= a.length() - 1;++i) {
			if (begin[i] != end[i]) {
				if (i == 0 && k == 1) {
					begin.flip(1);   ////csdn���ң�����flip��n) ���ǰѵ�nλȡ��������������0��ʼ����
					begin.flip(0);
					cnt++;
				}
				if (k == 0 || (i > 0 && k == 1)) {
					if (i < a.length() - 2) {
						begin.flip(i);
						begin.flip(i + 1);
						begin.flip(i + 2);
						//cout <<k<<' '<< begin << endl;
					}
					else if (i == a.length() - 2) {
						begin.flip(i);
						begin.flip(i + 1);
						//cout <<k<<' '<<"@" << begin << endl;
					}
					/*else if (i == a.length() - 1) {
						cout << "impossible";
						return 0;
					}*/
					cnt++;
				}
			}
			//if (i == begin.size() - 1 && begin[i] == end[i]) cout << cnt;
		}
		if (begin == end) {
			cout << cnt;
			return 0;
		}
	}
	cout << "impossible";

	return 0;
}