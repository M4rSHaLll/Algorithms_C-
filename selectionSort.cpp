#include <iostream>

using namespace std;


void selectionSort(int* mass, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minPosition = i, tmp;
        for (int j = i + 1; j < n; j++)
            if (mass[minPosition] > mass[j])
                minPosition = j;
        tmp = mass[minPosition];
        mass[minPosition] = mass[i];
        mass[i] = tmp;
    }
    
}


int main()
{
    int mass[] = { 20, 7, 3 ,21};
    
    selectionSort(mass, sizeof(mass) / sizeof(mass[0]));



    for (int i = 0; i < sizeof(mass) / sizeof(mass[0]); i++) 
    {
        cout << "mass[" << i << "] = " << mass[i] << endl;
    }
    
    return 0;
}