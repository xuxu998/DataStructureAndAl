#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] < arr[j + 1])
            swap(arr[j],arr[j+1]);
        }
    }
}
int main(void)
{
    int arr[6] = {5,4,1,10,4,8};
    BubbleSort(arr,6);
    for(int element : arr)
        cout<<element<<" ";
}