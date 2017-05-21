#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;
LL n;               //移动次数
int endP;           //移动n次后，球在shell endP 的下面
int startP;         //球 初始时 在shell startP 的下面

int main()
{
	int code[3] = { 0, 1, 2 };
	
	while (cin >> n) {
		scanf("%d", &endP);
		if (n % 2 == 0) {
			int k = n / 2;
			if (k % 3 == 0) {
				if (endP == 0) printf("0\n");
				else if (endP == 1) printf("1\n");
				else if (endP == 2) printf("2\n");
			}
			else if (k % 3 == 1) {
				if (endP == 2) printf("0\n");
				else if (endP == 0) printf("1\n");
				else if (endP == 1) printf("2\n");
			}
			else if (k % 3 == 2) {
				if (endP == 1) printf("0\n");
				else if (endP == 2) printf("1\n");
				else if (endP == 0) printf("2\n");
			}
		}
		else {
			int t = (n + 1) / 2;
			if (t % 3 == 0) {
				if (endP == 0) printf("0\n");
				else if (endP == 2) printf("1\n");
				else if (endP == 1) printf("2\n");
			}
			else if (t % 3 == 1) {
				if (endP == 1) printf("0\n");
				else if (endP == 0) printf("1\n");
				else if (endP == 2) printf("2\n");
			}
			else if (t % 3 == 2) {
				if (endP == 2) printf("0\n");
				else if (endP == 1) printf("1\n");
				else if (endP == 0) printf("2\n");
			}
		}
	}
	return 0;
}