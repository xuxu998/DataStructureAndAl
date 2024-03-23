#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
// https://usaco.org/index.php?page=viewproblem2&cpid=1156
int main()
{
    for(int test_num = 1; test_num <= 10 ;test_num++)
    {
        const string input_path = "C:\\Users\\PC\\Downloads\\prob2_bronze_dec21\\" + to_string(test_num) + ".in";
        const string out_path = "C:\\Users\\PC\\Downloads\\prob2_bronze_dec21\\" + to_string(test_num) + ".out";
        ifstream input(input_path);
        long long int num;
        ifstream res_in(out_path);
        long long int ans,res = 0;
        res_in >> ans;
        input >> num;
        vector<int> p(num),n(num);
        for(int i = 0 ; i < num ; i++)
            input >> p[i];
        for(int i = 0 ; i < num ; i++)
            input >> n[i];
        // implementation begins
        vector<vector<int>> part(1);
        part.back().push_back(0);
        part.back().push_back(abs(p[0] - n[0]));
        for(int i = 1 ; i < num ; i++)
        {
            if((p[i] - n[i]) * (p[i - 1] - n[i - 1]) < 0)
            {
                part.back().push_back(0);
                part.push_back({0});
            }
            part.back().push_back(abs(p[i] - n[i]));
        }
        part.back().push_back(0);
        // for(auto& segment : part)
        // {
        //     for(auto& x : segment)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        for(auto& segment : part)
        {
            int pre_min = 0, pre_max = segment[1];
            int current_min = 0;
            for(int i = 1 ; i < segment.size() - 1; i++)
            {
                if(segment[i] > segment[i + 1])
                {
                    if(current_min <= pre_max)
                        res += segment[i] - current_min;
                    if(current_min > pre_max)
                        res += segment[i] - pre_max;
                    // cout<<current_min<<" "<<pre_min<<" "<<pre_max<<" "<<res<<endl;
                    pre_min = current_min;
                    current_min = segment[i + 1];
                    pre_max = segment[i];
                }
            }
        }
        // implementation ends
        if(ans == res)
        {
            cout<<"PASSED at " << test_num <<" Your ans: "<<res<<" Expected: "<<ans<< endl;
        }
        else
        {
            cout<<"FAILED at " << test_num <<" Your ans: "<<res<<" Expected: "<<ans<< endl;
        }
    }
}