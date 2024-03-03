#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++)
    {
        long long n,k;
        cin>>n>>k;
        if(n % 2 == 0 || k == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            long long a = n - n % k;
            if((n - a - k) % 2 == 0 || (n - a - 2*k) % 2 == 0)
                cout<<"YES";
            else
                cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}