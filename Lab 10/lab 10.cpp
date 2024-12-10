#include <bits/stdc++.h>
using namespace std;
int max(int a, int b);
int N = 0;

void findLCS(char* str1, char* str2, int x, int y)
{
	int lcsArray[x + 1][y + 1];
	int i, j;

	for (i = 0; i <= x; i++) {
		for (j = 0; j <= y; j++) {
			if (i == 0 || j == 0)
				lcsArray[i][j] = 0;

			else if (str1[i - 1] == str2[j - 1])
				lcsArray[i][j] = lcsArray[i - 1][j - 1] + 1;

			else
				lcsArray[i][j] = max(lcsArray[i - 1][j], lcsArray[i][j - 1]);
		}
	}
	int idx = lcsArray[x][y];
	char lcsSubSeqnceStr[idx + 1];
	lcsSubSeqnceStr[idx] = '\0';

	i = x, j = y;
	while (i > 0 && j > 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			lcsSubSeqnceStr[idx - 1] = str1[i - 1];
			i--; j--; idx--;
		}
		else if (lcsArray[i - 1][j] > lcsArray[i][j - 1])
			i--;
		else
			j--;
	}

	cout << lcsArray[x][y];
	cout << "(" + std::string(lcsSubSeqnceStr) + ")" << endl;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	char str1[] = "ACADB";
	char str2[] = "CBDA";

	int m = strlen(str1);
	int n = strlen(str2);
	findLCS(str1, str2, m, n);
	return 0;
}