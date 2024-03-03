// https://leetcode.com/problems/number-of-zero-filled-subarrays/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        vector<int> table;
        table.resize(nums.size(),0);
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                if(i > 0)
                {
                    if(nums[i - 1] == 0)
                    {
                        table[i] = table[i - 1] + 1;
                    }
                    else
                    {
                        table[i] = 1;
                    }
                }
                else
                table[i] = 1;
            }
        }
        for(int  i = 0 ; i < table.size() ; i++)
        {
            result = result + table[i];
        }
        return result;
    }
};