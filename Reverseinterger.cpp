#include <bits/stdc++.h>
using namespace std;
// Link for submission
// https://leetcode.com/problems/reverse-integer/submissions/913713685/
int reverse(int x)
{
    string temp = to_string(x);
    int start = 0;
    int end = temp.size()-1;
    while(start < end)
    {
        swap(temp[start++],temp[end--]);
    }
    cout<<temp<<endl;
    if(x < 0)
    {
        temp.pop_back();
        try
        {
            return -stoi(temp);
        }
        catch(exception e)
        {
            return 0;
        }
    }
    else
    try{

        return stoi(temp);
    }
    catch(exception e)
    {
        return 0;
    }
  
}
int main(void)
{
    cout<<reverse(1534236469);
}