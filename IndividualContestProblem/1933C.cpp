#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,l;
    cin>>a>>b>>l;
    int count_ = 0;
    vector<int> powa;
    vector<int> powb;
    int powa_ = 1,powb_ = 1;
    for(int i = 1; powa_ <= l ; i++)
    {
        powa.push_back(powa_);
        powa_ *= a;
    }
    for(int i = 1; powb_ <= l ; i++)
    {
        powb.push_back(powb_);
        powb_ *= b;
    }
    map<long long,int> mark;
    for(int i = 0 ; i < powa.size(); i++)
    {
        for(int j = 0 ; j < powb.size() ; j++)
        {
            if(1ll*l % (1ll*powa[i] * powb[j]) == 0 and mark.find(powa[i] * powb[j]) == mark.end())
            {
                count_++;
                mark[powa[i] * powb[j]] = 1;
            }
        }
    }
    cout<<count_<<endl;
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