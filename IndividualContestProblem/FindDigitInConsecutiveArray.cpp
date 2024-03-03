#include <bits/stdc++.h>
using namespace std;
// #define OLD
#define NEW
int FindDigit(int index)
{
    int starter = 1;
    int count_digit = 1;
    long multiplier = 9;
    while(index > multiplier * count_digit)
    {
        index = index - multiplier * count_digit;
        multiplier = multiplier * 10;
        starter = starter * 10;
        count_digit++;
    }
    int number_contain_digit = starter + index / count_digit - (index % count_digit ? 0:1);
    string s = to_string(number_contain_digit);
    if(index % count_digit == 0 )
    {
        return s[count_digit -1] - 48;
    }
    else
    {
        return s[index % count_digit - 1] -48;
    }
    return number_contain_digit;
    
}
int main(void)
{
        cout<<FindDigit(1000001);
}