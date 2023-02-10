#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int *merge(int arr[], int l1, int h1, int l2, int h2){
    int len = (h1-l1)+1+(h2-l2)+1;
    int new_arr[len];
    int idx1 = l1;
    int idx2 = l2;
    for (int i = 0; i < len; i++){
        if (arr[idx1] < arr[idx2] && idx1 <= h1){
            new_arr[i] = arr[idx1];
            idx1++;
        } else if (arr[idx1] >= arr[idx2] && idx2 <= h2) {
            new_arr[i] = arr[idx2];
            idx2++;
        } else if (idx1 > h1 && idx2 <= h2) { // corner cases
            new_arr[i] = arr[idx2];
            idx2++;
        } else if (idx2 > h2 && idx1 <= h1) { // corner cases
            new_arr[i] = arr[idx1];
            idx1++;
        }
    }
    // fill the subarray of the original array with the new sorted array
    for (int i = 0; i < len; i++){
        arr[l1+i] = new_arr[i];
    }
    return arr;
}

void mergesort(int arr[], int l1, int h1, int l2, int h2){
    if (l1 < h1){
        int i = int((l1+h1)/2);
        mergesort(arr, l1, i, i+1, h1);
    }
    if (l2 < h2){
        int i = int((l2 + h2) / 2);
        mergesort(arr, l2, i, i + 1, h2);
    }
    merge(arr, l1, h1, l2, h2);
}

int main(){
    int arr[] = {7, 3, 5, 4, 2, 9, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int m = int((len-1)/2);
    mergesort(arr, 0, m, m+1, len - 1);
    printArray(arr, len);
}