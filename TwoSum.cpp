#include <bits/stdc++.h>
// https://leetcode.com/problems/two-sum/
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> map_;
        vector<int> result;
        for(int i = 0 ; i < nums.size() ;i++)
        {
            map_[nums[i]].push_back(i);
        }
        for(auto a : map_)
        {
            for(auto element : a.second)
            {
                cout<<element<<" ";
            }
        }
        for(int i = 0 ; i < nums.size();i++)
        {
            result.push_back(i);
            int temp = map_[nums[i]].back();
            map_[nums[i]].pop_back();
            if(map_.find(target - nums[i]) != map_.end())
            {
                if(!map_[target - nums[i]].empty())
                {
                    result.push_back(map_[target - nums[i]].back());
                    break;
                }

            }
            map_[nums[i]].push_back(temp);
            result.pop_back();
        }
        return result;
    }
int main()
{
    vector<int> a = {3,3};
    twoSum(a,6);
}