#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int split(int arr[], int l, int h, int len)
{
    int x = arr[l];
    int i = l + 1;
    int j = h;
    while (i < j)
    {
        while (x > arr[i] && i < j)
        {
            i++;
        }
        while (x < arr[j] && i < j)
        {
            j--;
        }
        if (i != j)
        {
            int arr_i = arr[i];
            int arr_j = arr[j];
            arr[i] = arr_j;
            arr[j] = arr_i;
        }
    }
    i = i - 1;
    int tmp = arr[i];
    arr[i] = x;
    arr[l] = tmp;
    return i;
}

void quicksort(int arr[], int l, int h, int len)
{
    if (l < h)
    {
        int m = split(arr, l, h, len);
        quicksort(arr, l, m - 1, len);
        quicksort(arr, m + 1, h, len);
    }
}

int main()
{
    int arr[] = {7, 3, 5, 4, 2, 9, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, len - 1, len);
    printArray(arr, len);
}