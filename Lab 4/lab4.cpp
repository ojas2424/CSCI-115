#include <iostream>
using namespace std;
class Heap
{
public:

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { 
        return (2 * i + 2); 
    }

    void printArray(int arr[], int n);


    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void modifyValMax(int arr[], int n, int i, int val); 

    void insert_value_maxHeap(int arr[], int val, int& n); 

    void max_heapify(int arr[], int i, int n); 

    int extract_maximum(int arr[], int& n); 

    void ascendingHeapSort(int arr[], int n); 


    void buildMaxHeap(int arr[], int n) 
    {

    }

    void modifyValMin(int arr[], int n, int i, int val) 
    {

    }

    void insert_value_minHeap(int arr[], int val, int& n) 
    {
        
        n++;
        int i = n - 1;
        arr[i] = val;

        min_heapify(arr, i, n);
    }

    void min_heapify(int arr[], int i, int n) 
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < n && arr[l] < arr[i])
            smallest = l;
        if (r < n && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            min_heapify(arr, i, n);
        }
    }

    int extract_minimum(int arr[], int n) 
    {
        if (n == 1)
        {
            n--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[n - 1];
        n--;
        min_heapify(arr, 0, n);

        return root;
    }

    void descendingHeapSort(int arr[], int n) {

        for (int i = 0;i < n / 2;i++) {
            int min = extract_maximum(arr, n);
            cout << min << "    ";

        }

    }; 


    void buildMinHeap(int arr[], int n) 
    {

        int startIdx = (n / 2) - 1;

        for (int i = startIdx; i >= 0; i--) {
            cout << "min heapify " << arr[i] << "   ";
            min_heapify(arr, i, n);
        }
        cout << endl;
    }

};
int main() {
    int n;
    cout << "enter the size of array  ";
    cin >> n;
    int arr[n];
    Heap hObj;
    arr[0] = 2;
    arr[1] = 1;
    arr[2] = 3;
    hObj.buildMinHeap(arr, n);
    cout << "returning after min heapify ";
    for (int i = 0;i < n;i++) {

        cout << arr[i] << "  ";
    }
    cout << endl;


}

