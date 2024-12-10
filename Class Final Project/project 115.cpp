//check all sorting algorithms and their time complexity
//rough file
//class individual project
//Part one
//complete file with all the functions
//the output == run time, is already in values of average


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

void insertion_sort(int n, int arr[]) {
	int i, j, temp;

	for (i = 1; i < n; i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {

			if (arr[j] <= temp) {
				break;
			}
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = temp;
	}
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

void bubble_sort(int n, int arr[]) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				swap(j, j + 1, arr);
			}
		}
	}
}

int partition(int start, int end, int arr[]) {
	int pivot = arr[end], i = start - 1, j, temp;

	for (j = start; j < end; j++) {

		if (arr[j] < pivot) {
			i++;
			swap(i, j, arr);
		}
	}
	swap(i + 1, end, arr);

	return i + 1;
}

void quick_sort_helper(int start, int end, int arr[]) {

	if (start >= end) {
		return;
	}
	int partition_index = partition(start, end, arr);

	quick_sort_helper(start, partition_index - 1, arr);

	quick_sort_helper(partition_index + 1, end, arr);
}

void quick_sort(int n, int arr[]) {

	quick_sort_helper(0, n - 1, arr);
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


int get_max(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSortPayload(int arr[], int n, int exp) {

	int output[n]; // output array
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void count_sort(int arr[], int n) {
	int m = get_max(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSortPayload(arr, n, exp);
	}
}



// The main function to that sorts arr[] of size n using
// Radix Sort
void radix_sort(int arr[], int n)
{
	// Find the maximum number to know number of digitsa
	int m = get_max(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
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
			insertion_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			insertion_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			insertion_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Insertion sort random avg time " << (float)(avg_time[0] / CLOCKS_PER_SEC) * 10e6 << " microsec for n = " << n << endl;
		cout << "Insertion sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Insertion sort reverse sorted avg time " << (float)(avg_time[2] / CLOCKS_PER_SEC) * 10e6 << " microsec for n = " << n << endl;
	}

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

	for (int n : sizes) {
		int arr[n], i;
		float avg_time[3];
		for (i = 0;i < 10;i++) {

			generateRandomArray(arr, n);

			time = clock();
			bubble_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			bubble_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			bubble_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Bubble sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Bubble sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Bubble sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}


	for (int n : sizes) {
		int arr[n], i;
		float avg_time[3];
		for (i = 0;i < 10;i++) {

			generateRandomArray(arr, n);

			time = clock();
			quick_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			quick_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			quick_sort(n, arr);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Quick sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Quick sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Quick sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}

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

	for (int n : sizes) {
		int arr[n], i;
		float avg_time[3];
		for (i = 0;i < 10;i++) {

			generateRandomArray(arr, n);

			time = clock();
			count_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			count_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();

			count_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Count sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Count sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Count sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}

	//Radic sort average times for all arrays
	for (int n : sizes) {
		int arr[n], i;
		float avg_time[3];
		for (i = 0;i < 10;i++) {

			generateRandomArray(arr, n);

			time = clock();
			radix_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort random time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[0] += (float)time / CLOCKS_PER_SEC;

			generateSortedArray(arr, n);

			time = clock();
			radix_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort sorted time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[1] += (float)time / CLOCKS_PER_SEC;


			generateReverseArray(arr, n);

			time = clock();
			radix_sort(arr, n);
			time = clock() - time;
			//	cout<<"Quick sort reverse time " << (float) time/CLOCKS_PER_SEC << " sec for n = " << n <<endl;
			avg_time[2] += (float)time / CLOCKS_PER_SEC;

		}

		avg_time[0] /= i;
		avg_time[1] /= i;
		avg_time[2] /= i;

		cout << "Radix sort random avg time " << (float)((avg_time[0] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Radix sort sorted avg time " << (float)((avg_time[1] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
		cout << "Radix sort reverse sorted avg time " << (float)((avg_time[2] / CLOCKS_PER_SEC) * 10e6) << " microsec for n = " << n << endl;
	}
}



