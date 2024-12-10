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

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heap_sort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}


/*
void countsort(int arr[], int n) {
	int k = arr[0];
	for (int i = 0; i < n; i++) {
		k = max(k, arr[i]);
	}

	int count[k] = { 0 };
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		count[i] += count[i - 1];
	}
	int output[n];
	for (int i = n - 1; i >= 0; i--) {
		output[--count[arr[i]]] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}
}
*/



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
			heap_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			heap_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			heap_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Heap sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Heap sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Heap sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}

	
}



