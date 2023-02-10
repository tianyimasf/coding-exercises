#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int binarySearch(int arr[], int e, int len)
{
    int l = 0;
    int h = len - 1;
    int i = int((h - l) / 2);
    while (arr[i] != e){
        if (e < arr[i]){
            h = i;
        } else if (e > arr[i]){
            l = i;
        }
        i = int((h + l) / 2);
    }
    return i;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int e = 4;
    int idx = binarySearch(arr, e, len);
    printArray(arr, len);
    cout << "e: " << e << " idx: " << idx;
}