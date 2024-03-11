#include<bits/stdc++.h>
using namespace std;
#define not_take_pre1   0
#define not_take_pre2    1
#define take_both_pre       2
int next_row(int col,int row)
{
    if(row < 2)
        return 0;
    if(col == 1 or col == 2)
        return row - 1;
    else
        return row - 2;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n ; i++)
        cin>>a[i];
    vector<vector<int>> f(n + 1, vector<int> (3,0));
    vector<vector<int>> trace(n + 1,vector<int> (3,0));
    vector<vector<int>> trace_by_col(n + 1,vector<int> (3,0));
    vector<int> trace_res;
    f[1] = {a[1],a[1],0};
    f[2] = {a[2],a[1] + a[2],a[1]};
    trace[2] = {0,1,1};
    for(int i = 3 ; i <= n ; i++)
    {
        int temp = max({f[i - 2][not_take_pre1],f[i - 2][not_take_pre2],f[i - 2][take_both_pre]});
        f[i][not_take_pre1] = temp + a[i];
        trace[i][not_take_pre1] = i - 2;
        if(temp == f[i - 2][not_take_pre1])
            trace_by_col[i][not_take_pre1] = not_take_pre1;
        else if(temp == f[i - 2][not_take_pre2])
            trace_by_col[i][not_take_pre1] = not_take_pre2;
        else
            trace_by_col[i][not_take_pre1] = take_both_pre;
        temp = max({f[i - 1][not_take_pre1],f[i - 1][take_both_pre]});
        f[i][not_take_pre2] = temp + a[i];
        trace[i][not_take_pre2] = i - 1;
        if(temp == f[i - 1][not_take_pre1])
            trace_by_col[i][not_take_pre2] = not_take_pre1;
        else
            trace_by_col[i][not_take_pre2] = take_both_pre;
        f[i][take_both_pre] = f[i - 1][not_take_pre2];
        trace[i][take_both_pre] = i - 1;
        trace_by_col[i][take_both_pre] = not_take_pre2;
    }
    int res = max({f[n][0],f[n][1],f[n][2]});
    int row = n,column;
    if(res == f[n][0])
        column = 0;
    else if(res == f[n][1])
        column = 1;
    else
        column = 2;  
    // cout<<"Starter: "<<row<<" "<<column<<endl;
    int next_r_temp = next_row(column,row),next_cl_temp = trace_by_col[row][column];
    if(f[row][column] != f[next_r_temp][next_cl_temp])
        trace_res.push_back(n);
    while(next_row(column,row))
    {
        trace_res.push_back(trace[row][column]);
        int old_row = row;
        row = next_row(column,row);
        column = trace_by_col[old_row][column];
        // cout<<"Next: "<<row<<" "<<column<<endl;
    }
    cout<<res<<endl;
    reverse(trace_res.begin(),trace_res.end());
    for(auto& x : trace_res)
        cout<<x<<" ";
    
}