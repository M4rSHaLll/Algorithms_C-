#include <iostream>

void countSort(int arr[], int n)
{
    int keys[10] = {0, 0,0 ,0 ,0, 0, 0, 0, 0, 0};
    for(int i = 0; i < n; i++){
        keys[arr[i]]++;
    }
    int i = 0;
    for(int j = 0; j < 10;j++)
    {
        for(int k = 0; k < keys[j];k++){
            arr[i++] = j;
        }
    }
    
}

using namespace std;
int main()
{
    int arr[] = {7, 1, 2, 8, 5, 9, 4, 3, 6, 7};
    countSort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}