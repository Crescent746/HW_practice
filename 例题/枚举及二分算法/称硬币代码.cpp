#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
char Left[3][7];
char Right[3][7];
char result[3][7];
bool IsFake(char c, bool light) {  //同时判读是否为假币以及轻还是重
	for (int i = 0;i < 3;i++) {
		char* pleft, * pright;
		 if(light){
			pleft = Left[i];
			pright = Right[i];
		}
		 else {
			 pleft = Right[i];
			 pright = Left[i];
		 }
		 switch (result[i][0])
		 {
		 case 'u':
			 if (strchr(pright, c) == NULL)  
				 //strchr:查找某元素在字符串中第一次出现，char *strchr(const char *str, int character);
				 return false;
			 break;
		 case 'd':
			 if (strchr(pleft, c) == NULL)
				 return false;
			 break;
		 case 'e':
			 if (strchr(pleft, c) || strchr(pright, c))
				 return false;
			 break;
		 default:
			 break;
		 }
	}
	return true;
	}
int main() {
	int N;cin >> N;
	while (N--) {
		for (int i = 0;i < 3;i++) cin >> Left[i] >> Right[i] >> result[i];
		for (char c = 'A';c <= 'L';c++) {
			if (IsFake(c, true)) {
				cout << c << " is the counterfeit coin and it is light.\n";
				break;
			}
			if (IsFake(c, false)) {
				cout << c << " is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
		
	}
	return 0;
}
