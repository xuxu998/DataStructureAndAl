#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-digit-one/
int helper(int n,int base)
{
    if(base == 1)
    {
        return n >= 1 ? 1 : 0;
    }
    if(n < base)
    {
        return helper(n,base/10);
    }
    if(n / base == 1)
    {
        return (n-base) + 1 + helper(n - base,base/10) + n/base * helper(base -1,base / 10);
    }
    else
    {
        return base + helper(n - (n/base)*base,base / 10) + n/base * helper(base - 1,base / 10);
    }
}
int countDigitOne(int n) {
    long long temp = 1;
    while(temp*10 <= n)
    {
        temp *= 10;
    }
    return helper(n,temp);
}
int main(void)
{
    cout<<countDigitOne(100);

}