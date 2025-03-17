#include <iostream>
#include <vector>

using namespace std;
int sum(vector<int> mass)
{
    
    if (mass.size() == 1)
        return mass[0];
    
    int s = mass[mass.size() - 1];
    mass.pop_back();
    return s + sum(mass);

}
int main()
{
    
    vector<int>  arr = { 1, 4, 7, 8};
    cout << sum(arr);

}
