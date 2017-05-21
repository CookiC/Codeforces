#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 500000 + 10;
int n;
string label[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> label[i];
	}
	for (int i = n - 1; i > 0; i--)
	{
		int k, len = min(label[i - 1].size(), label[i].size());
		if (label[i - 1] > label[i]) {
			for (k = 1; k < len; k++) {
				if (label[i - 1][k] > label[i][k]) {
					break;
				}
			}
			if (k <= len) {
				label[i - 1] = label[i - 1].substr(0, k);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << label[i] << endl;
	}

	return 0;
}




