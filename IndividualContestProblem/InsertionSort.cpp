#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[],int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        int j = i + 1;
        while (arr[j] < arr[j - 1])
        {
            swap(arr[j],arr[j - 1]);
            j--;
            if(j == 0)
            break;
        }
        
    }
}
int main(void)
{
    int arr[6] = {10,4,5,12,9,20};
    InsertionSort(arr,6);
    for(int element : arr)
    {
        cout<<element<<" ";
    }
}