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
void merge(int start, int mid, int end, int arr[]) {

	int left_size = mid - start + 1, right_size = end - mid;
	int i, j, k;
	int* temp_left = new int[left_size];
	int* temp_right = new int[right_size];
	// int temp_left[left_size], temp_right[right_size];

	for (i = 0; i < left_size; i++) {

		temp_left[i] = arr[start + i];
	}

	for (i = 0; i < right_size; i++) {

		temp_right[i] = arr[mid + 1 + i];
	}

	i = 0, j = 0, k = start;

	while (i < left_size && j < right_size) {

		if (temp_left[i] <= temp_right[j]) {

			arr[k++] = temp_left[i++];
		}
		else {
			arr[k++] = temp_right[j++];
		}
	}
	while (i < left_size) {

		arr[k++] = temp_left[i++];
	}
	while (j < right_size) {

		arr[k++] = temp_right[j++];
	}
}

void merge_sort_helper(int start, int end, int arr[]) {

	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;

	merge_sort_helper(start, mid, arr);

	merge_sort_helper(mid + 1, end, arr);

	merge(start, mid, end, arr);
}

void merge_sort(int n, int arr[]) {

	merge_sort_helper(0, n - 1, arr);
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
			merge_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			merge_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			merge_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Merge sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Merge sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Merge sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}

	
}



