#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int get_max(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSortPayload(int arr[], int n, int exp) {

	int output[n]; 
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void count_sort(int arr[], int n) {
	int m = get_max(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSortPayload(arr, n, exp);
	}
}

void radix_sort(int arr[], int n)
{
	int m = get_max(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSortPayload(arr, n, exp);
}

void generateRandomArray(int arr[], int n) {
	for (int j = 0; j < n; j++) {
		arr[j] = rand() % 100;
	}
}

void generateSortedArray(int arr[], int n) {
	generateRandomArray(arr, n);
	sort(arr, arr + n);
}

void generateHalfSortedArray(int arr[], int n) {
	generateSortedArray(arr, n);
	int k = (n / 2);
	for (int j = 0; j < k; j++) {
		arr[j] = rand() % 100;
	}
}

void generateReverseArray(int arr[], int n) {
	generateSortedArray(arr, n);
	int i, j, temp;
	for (i = 0, j = n - 1;i < j;i++, j--) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	clock_t t;
	int n = 200;
	int mrr[n];

	generateHalfSortedArray(mrr, n);
	t = clock();
	count_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, count sort on half sorted arr: " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateSortedArray(mrr, n);
	t = clock();
	count_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, count sort on sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateReverseArray(mrr, n);
	t = clock();
	count_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, count sort reverse sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	cout << endl;

	generateHalfSortedArray(mrr, n);
	t = clock();
	radix_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, radix sort half sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateSortedArray(mrr, n);
	t = clock();
	radix_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, radix sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateReverseArray(mrr, n);
	t = clock();
	radix_sort(mrr, n);
	t = clock() - t;
	cout << "time taken, radix sort reverse sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	return 0;
}