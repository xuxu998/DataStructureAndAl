#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++)
    {
        int length;
        cin>>length;
        vector<int> arr(length,0);
        long long sum = 0;
        for(int k = 0 ; k < length ; k++)
        {
            cin>>arr[k];
            sum += arr[k];
        }
        long long res = sum;
        long long change = -arr[0] - arr[1];
        res = max(res,sum + 2 * change);
        for(int j = 2 ; j < length ; j++)
        {
            change = change + arr[j - 2] - arr[j];
            res = max(res,sum + 2 * change);
        }
        cout<<res<<endl; 
    }
    return 0;
}