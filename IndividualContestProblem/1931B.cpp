#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum = 0;
    for(int& x : a)
    {
        cin>>x;
        sum += x;
    }
    long long remain = 0;
    long long ave = sum / n;
    for(int i = n - 1; i >= 0 ; i--)
    {
        if(a[i] > ave)
        {
            if(a[i] - ave > remain)
            {
                cout<<"no"<<endl;
                return;
            }
            else
            {
                remain -= (a[i] - ave);
            }
        }
        else
        {
            remain += ave - a[i];
        }
    }
    cout<<"yes"<<endl;
    
}
int main()
{
    int ntest;
    cin>>ntest;
    while(ntest--)
    {
        solve();
    }
}