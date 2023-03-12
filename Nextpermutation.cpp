#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>& arr, int start_position, int end_position)
{
    while (start_position < end_position)
    {
        swap(arr[start_position++],arr[end_position--]);
    }
    return;
}
void nextPermutation(vector<int>& nums) {
    // finding pivot
    int pivot;
    for(int i = nums.size()-1 ; i > 0; i--)
    {
        if(nums[i] > nums[i-1])
        {   
            pivot = i - 1;
            break;
        }
    }
    cout<<pivot<<endl;
    // swap pivot with the first greater value
    // encounters 
    for(int i = nums.size()-1 ; i > 0; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i],nums[pivot]);
            break;
        }
    }
    for(int element : nums)
    {
        cout<<element;
    }
    // Reverse from pivot + 1
    reverse(nums,pivot+1,nums.size()-1);

} 
int main(void)
{
    vector<int> arr = {1,3,2};
    nextPermutation(arr);
    for(int element : arr)
    {
        cout<<element;
    }
}