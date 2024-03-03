#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[],int size_off_arr)
{
    for(int i = 0; i < size_off_arr - 1; i++)
    {
        for(int j = i + 1; j < size_off_arr; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

}
int main(void)
{
    int arr[10] = {4,5,3,2,4,9,7,8,10,6};
    SelectionSort(arr,sizeof(arr)/sizeof(int));
    for(int element : arr)
    cout<<element<<" ";
}