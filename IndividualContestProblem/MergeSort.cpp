#include <bits/stdc++.h>
using namespace std;
void MergeOperation(int arr[],int middle,int head,int tail)
{
    int left_side_length = middle - head + 1;
    int right_side_length = tail - middle;
    int *left_temp_arr = new int[left_side_length];
    int *rigth_temp_arr = new int[right_side_length];
    for(int i  = 0 ; i < left_side_length ; i ++)
    {
        left_temp_arr[i] = arr[head + i];
    }
    for(int i = 0 ; i < right_side_length ; i ++)
    {
        rigth_temp_arr[i] = arr[middle + 1 + i];
    }
    int *left_ptr = left_temp_arr;
    int *right_ptr = rigth_temp_arr;
    int left_count = 0;
    int right_count = 0;
    for(int i = 0 ; i < left_side_length + right_side_length ; i++)
    {
        if(left_count < left_side_length && right_count < right_side_length)
        {
            if(*left_ptr > *right_ptr)
            {
                arr[head+i] = *right_ptr;
                right_count +=1;
                right_ptr++;
            }
            else
            {
                arr[head+i] = *left_ptr;
                left_count +=1;
                left_ptr++;
            }
        }
        else
        {
            if(left_count == left_side_length && right_count < right_side_length)
            {
                arr[head+i] = *right_ptr;
                right_count +=1;
                right_ptr++;
            }
            if(right_count == right_side_length && left_count < left_side_length)
            {
                arr[head+i] = *left_ptr;
                left_count +=1;
                left_ptr++;
            }
        }
    }

    delete[] left_temp_arr;
    delete[] rigth_temp_arr;
    
}
void MergerSort(int arr[],int head,int tail)
{
    if(head < tail)
    {
        int middle = (head + tail) / 2;
        MergerSort(arr,head, middle);
        MergerSort(arr,middle + 1 , tail);
        MergeOperation(arr,middle,head,tail);
    }
}
int main(void)
{
    int arr[6] = {12, 11, 13, 5, 6, 7};
    MergerSort(arr,0,sizeof(arr)/sizeof(int) - 1);
    for(int element : arr)
    {
        cout<<element<<" ";
    }

}