class Solution {
public:
    int helper(vector<int>& nums, int& target, int current,int count,vector<vector<int>>& f)
    {
        if(current == target)
            return 1;
        if(f[current][count] != -1)
            return f[current][count];
        f[current][count] = 0;
        for(int i  = 0 ; i < nums.size() ; i++)
        {
            if(current + nums[i] <= target)
            {
                f[current][count] += helper(nums,target, current + nums[i],count + 1,f);
            }
        }
        return f[current][count];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int min_ = nums[0];
        for(auto val : nums)
            min_ = min(val,min_);
        vector<vector<int>> f(target + 1,vector<int> (target / min_ + 1 , -1));
        return helper(nums,target,0,0,f);
        
    }
};


    int combinationSum4(vector<int>& nums, int target) {
        int min_ = nums[0];
        for(auto val : nums)
            min_ = min(val,min_);
        vector<vector<int>> f(target + 1,vector<int> (target / min_ + 1 , 0));
        int res = 0;
        f[0][0] = 1;
        cout<<target / min_ + 1<<endl;
        for(int i = 1 ; i <= target ; i++)
        {
            for(int j = 1 ; j < f[i].size() ; j++)
            {
                for(int k = 0 ; k < nums.size() ; k++)
                {
                    if(i >= nums[k])
                        f[i][j] += f[i - nums[k]][j - 1];
                }
            }
        }
        // for(auto i : f)
        // {
        //     for(auto j : i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int i = 0 ; i < f[target].size() ; i++)
            res += f[target][i];
        return res;
        // return helper(nums,target,0,0,f);
        
    }
};