#include <bits/stdc++.h>
using namespace std;
bool in_range(int start, int end, int index)
{ 
    if(index <= end and index >= start)
    {
        return true;
    }
    else
        return false;
}
int ArrayRotation(int query[][2], int number_of_queries, int index)
{
    for(int i = number_of_queries - 1; i >= 0 ; i--)
    {
        if(in_range(query[i][0],query[i][1],index))
        {
            if(index  == query[i][0])
            {
                index = query[i][1];
            }
            else
            {
                index -=1;
            }
        }
    }
    return index;
}
int main(void)
{
    int queries[2][2] = { {0, 3}, {3, 4} };
    int arr[5] = {1,2,3,4,5};
    cout<<"Value of index: "<<1<<" after "<<sizeof(queries)/sizeof(queries[0])<<" rotations is: "<<arr[ArrayRotation(queries,sizeof(queries)/sizeof(queries[0]),1)];
}