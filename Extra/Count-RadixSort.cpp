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



