#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void swap(int i, int j, int arr[]) {
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	return;
}
void selection_sort(int n, int arr[]) {
	int i, j;

	for (i = 0; i < n - 1; i++) {

		for (j = i + 1; j < n; j++) {

			if (arr[j] < arr[i]) {
				swap(i, j, arr);
			}
		}
	}
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
	srand(time(NULL));
	clock_t time;

	int sizes[] = { 500, 900, 1500, 2000, 5000, 10000 };

	
	for (int n : sizes) {
		int arr[n], i;
		float avg_time[3];
		for (i = 0;i < 10;i++) {

			generateRandomArray(arr, n);

			time = clock();
			selection_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			selection_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			selection_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Selection sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Selection sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Selection sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}

	
}



