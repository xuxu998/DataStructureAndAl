#include <bits/stdc++.h>
using namespace std;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
void solve()
{
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int count = 0,count1 = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        if(a[i] == b[i] and c[i] != a[i])
        {
            yes
            return;
        }
        if(a[i] != b[i])
        {
            count++;
            if(c[i] == a[i] or c[i] == b[i])
                count1++;
            
        }
    }
    if(count == count1)
        no
    else
        yes
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