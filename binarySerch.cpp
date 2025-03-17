#include <iostream>
#include <string>
using namespace std;
int binarySerch(int list[],int index)
{
    //int max = sizeof(list) / sizeof(list[0]), min = 0;
    int max = 10, min = 0;
    int count = 1;
    while(min < max)
    {
        int mid = (max + min) / 2;
        if(list[mid] == index)
        {
            cout << "\n" <<count << endl;
            return mid;
        }
        else if(list[mid] > index)
            max = mid;
        else
            min = mid;
        count++;
    }
    cout << "\n" <<count << endl;
    return -1;

}


int main()
{
    // char list[][80] = {"asa","axd","bdf","cer","der","eef","gsp","ppy","xys","zuu"};
    // char index[] = "gsp";
    int list[] = {1, 3, 4, 6 ,7, 9, 12, 13 ,16, 19, 31};
    int index = 12;
    cout <<"index" << binarySerch(list,index);
    return 0;
}