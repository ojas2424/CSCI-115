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


void merge(int start, int mid, int end, int arr[]) {

	int left_size = mid - start + 1, right_size = end - mid;
	int i, j, k;
	int* temp_left = new int[left_size];
	int* temp_right = new int[right_size];

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
	int n = 200000;
	int mrr[n];

	generateHalfSortedArray(mrr, n);
	t = clock();
	merge_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, mergesort on half sorted arr: " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateSortedArray(mrr, n);
	t = clock();
	merge_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, merge sort on sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateReverseArray(mrr, n);
	t = clock();
	merge_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, merge sort reverse sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;
	
	cout << endl;
	//selection sort ---

	generateHalfSortedArray(mrr, n);
	t = clock();
	selection_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, selection sort half sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateSortedArray(mrr, n);
	t = clock();
	selection_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, selection sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;

	generateReverseArray(mrr, n);
	t = clock();
	selection_sort(n, mrr);
	t = clock() - t;
	cout << "time taken, selection sort reverse sorted arr :  " << ((float)t / CLOCKS_PER_SEC) * 10e6 << " micro seconds" << endl;


	return 0;
}


