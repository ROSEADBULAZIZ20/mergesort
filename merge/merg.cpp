// Merge sort
#include <iostream>
using namespace std;
void merge(int arr[], int x, int y, int z) 
{//sortd
    int A = y - x + 1;
    int B = z - y;
    int L[A], M[B];
    for (int i = 0; i < A; i++)
        L[i] = arr[x + i];
    for (int j = 0; j < B; j++)
        M[j] = arr[y + 1 + j];
    // Maintain indexing of the array
    int i, j, k;
    i = 0;
    j = 0;
    k = x;
    //pick larger among element L and M than put them in the right place
    while (i < A && j < B) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    // collect the remaining elements in an array
    while (i < A) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < B) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
// divide the array into two subarray , sort them and merge them
void mergeSort(int arr[], int d, int g) {
    if (d < g) {
        int m = d + (g - d) / 2;
        mergeSort(arr, d, m);
        mergeSort(arr, m + 1, g);
        merge(arr, d, m, g);
    }
}
// print arrray
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = { 3, 20, 14, 9, 1, 18 };
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: \n";
    printArray(arr, size);
    return 0;
}