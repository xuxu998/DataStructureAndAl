#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x : a)
    {
        cin>>x;
    }
    sort(a.begin(),a.end());
    cout<<a.back() - a.front()<<endl;
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