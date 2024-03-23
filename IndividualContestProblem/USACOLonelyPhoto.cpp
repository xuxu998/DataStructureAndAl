#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
// https://usaco.org/index.php?page=viewproblem2&cpid=1155
int main()
{
    for(int test_num = 1; test_num <= 11 ;test_num++)
    {
        const string input_path = "C:\\Users\\PC\\Downloads\\prob1_bronze_dec21\\" + to_string(test_num) + ".in";
        const string out_path = "C:\\Users\\PC\\Downloads\\prob1_bronze_dec21\\" + to_string(test_num) + ".out";
        ifstream input(input_path);
        ifstream res_in(out_path);
        long long int ans;
        res_in >> ans;
        int n;
        input>>n;
        string s;
        input >> s;
        s = " " + s;
        long long int res = 0;
        vector<long long int> countH_left(n + 2,0), countH_right(n + 2,0);
        countH_left[1] = (s[1] == 'H' ? 1 : 0);
        countH_right[n] = (s[n] == 'H' ? 1 : 0);
        for(int i = 1; i <= n ; i++)
        {
            if(s[i] == 'H')
                countH_left[i] = countH_left[i - 1] + 1;
        }
        for(int i = n; i >= 1 ; i--)
        {
            if(s[i] == 'H')
                countH_right[i] = countH_right[i + 1] + 1;
        }
        for(int i = 1; i <= n ; i++)
        {
            if(s[i] == 'G')
            {
                res += countH_left[i - 1] * countH_right[i + 1];
                if(countH_left[i - 1] >= 1)
                    res += countH_left[i - 1] - 1;
                if(countH_right[i + 1] >= 1)
                    res += countH_right[i + 1] - 1;
            }
        }
        vector<long long int> countG_left(n + 2,0), countG_right(n + 2,0);
        countG_left[1] = (s[1] == 'G' ? 1 : 0);
        countG_left[n] = (s[n] == 'G' ? 1 : 0);
        for(int i = 1; i <= n ; i++)
        {
            if(s[i] == 'G')
                countG_left[i] = countG_left[i - 1] + 1;
        }
        for(int i = n; i >= 1 ; i--)
        {
            if(s[i] == 'G')
                countG_right[i] = countG_right[i + 1] + 1;
        }
        for(int i = 1; i <= n ; i++)
        {
            if(s[i] == 'H')
            {
                res += countG_left[i - 1] * countG_right[i + 1];
                if(countG_left[i - 1] >= 1)
                    res += countG_left[i - 1] - 1;
                if(countG_right[i + 1] >= 1)
                    res += countG_right[i + 1] - 1;
            }
        }
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