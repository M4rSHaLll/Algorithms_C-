
#include <iostream>
#include <vector>

using namespace std;
vector<int> sumVect(vector<int> arr1, int point, vector<int> arr2)
{
    vector<int> exit;
    for (int i = 0; i < arr1.size(); i++)
        exit.push_back(arr1[i]);
    exit.push_back(point);
    for (int i = 0; i < arr2.size(); i++)
        exit.push_back(arr2[i]);
    return exit;
        
}
vector<int> quicSort(vector<int> arr)
{
    if (arr.size() < 2)
        return arr;
    int point = arr[0];

    vector<int> less, greater;

    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] < point)
            less.push_back(arr[i]);
        else
            greater.push_back(arr[i]);
    }
    
    return sumVect(quicSort(less), point, quicSort(greater));
}

int main()
{
    vector<int> arr = { 21, 7, 3, 9, 14, 2, 8, 45, 24 };
    arr = quicSort(arr);

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

