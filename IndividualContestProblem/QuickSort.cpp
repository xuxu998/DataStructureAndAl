#include <bits/stdc++.h>
using namespace std;
#define ENABLE              1
#define DISABLE             0
#define LENGTH              7

#define PIVOT_TAIL          ENABLE
#define PIVOT_HEAD          DISABLE
#define PIVOT_MIDDLE        DISABLE

#define LOMUTO_PARTITION
// #define HOARE_PARTITION
int partition(int arr[],int head,int tail)
{
    #ifdef LOMUTO_PARTITION
    /*This is Lumoto partition algorithm*/
        #if PIVOT_TAIL == ENABLE
        #elif PIVOT_HEAD == ENABLE
            swap(arr[head],arr[tail]);
        #elif PIVOT_MIDDLE == ENABLE
            swap(arr[(head+tail)/2],arr[tail]);
        #endif
        int pivot = arr[tail];
        int i = head;
        for(int j = head; j < tail; j++)
        {   
            if(arr[j] < pivot)
            {
                swap(arr[i],arr[j]);
                i++;
            }
        }
        swap(arr[i],arr[tail]);
        return i;
    #endif
    #ifdef HOARE_PARTITION
    #endif
}
void QuickSort(int arr[],int head,int tail)
{
    if(head < tail)
    {
        int i = partition(arr,head,tail);
        QuickSort(arr,head,i-1);
        QuickSort(arr,i+1,tail);
    }
}
int main(void)
{
    int arr[LENGTH] = {10,80,10,90,40,50,0};
    QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(auto element:arr){
        cout<<element<<" ";
    }
}