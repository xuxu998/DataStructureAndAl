#include <bits/stdc++.h>
// https://leetcode.com/problems/remove-element/
using namespace std;
int removeElement(vector<int>& nums, int val) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
}
int main(void)
{
    vector<int> a = {4,5};
     removeElement(a,5);
     for(auto element:a)
     {
        cout<<element<<" ";
     }
}