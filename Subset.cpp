#include <bits/stdc++.h>
using namespace std;
vector<int> temp_buffer;
vector<vector<int>> buffer;
void print_buffer(vector<vector<int>> buffer)
{
    for(int i = 0 ;i < buffer.size();i++)
    {
        for(int j = 0; j < buffer[i].size(); j++)
            cout<<buffer[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void generation(int n, int len)
{
    if(n == len)
    {
        buffer.push_back(temp_buffer);
    }
    else
    {
        for(int i = 0 ; i <= 1; i++)
        {
            temp_buffer.push_back(i);
            generation(n+1,len);
            temp_buffer.pop_back();
        }
    }
}
vector<vector<int>> subsets(vector<int> &a)
{
    generation(0,a.size());
    vector<vector<int>> result;
    vector<int> temp;
    for(int i = 0; i < buffer.size(); i++)
    {
        temp.clear();
        for(int j = 0 ; j < buffer[i].size(); j++)
        {
            if(buffer[i][j] == 1)
            {
                temp.push_back(a[j]);
            }
        }
        result.push_back(temp);
    }
    sort(result.begin(),result.end());
    return result;
}
int main(void)
{
    vector<int> a = {5, 6, 6, 10, 3, 4, 6, 6, 4};
    vector<vector<int>>b = subsets(a);
    print_buffer(b);
    // subsets(a);

}