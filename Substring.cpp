#include <bits/stdc++.h>
using namespace std;
bool helper(string S, int starting_index, int s1_length, int s2_length)
{
    string s1 = S.substr(starting_index,s1_length);
    string s2 = S.substr(starting_index + s1_length, s2_length);
    int sum = stoi(s1) + stoi(s2);
    string s3 = to_string(sum);
    if(s3 == S.substr(starting_index + s1_length + s2_length, s3.size()))
    {
        if(starting_index + s1_length + s2_length + s3.length() == S.size())
        {
            return true;
        }
        else
        {
            return helper(S,starting_index + s1_length,s2_length,s3.size());
        }

    }
    else
    {
        return false;
    }
}
int isSumString(string S)
{
    for(int i = 1; i < S.size(); i++)
    {
        for(int j = 1; j + i < S.size(); j++)
        {
            if(helper(S,0,i,j))
            {
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    // vector<int> temp_buffer;
    // SubstringSolved("112233",0,temp_buffer);
    cout<<isSumString("02243660");
}