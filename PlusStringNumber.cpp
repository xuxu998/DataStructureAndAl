#include <bits/stdc++.h>
using namespace std;
int charplus1(char a, char b)
{
    return (a - '0' + b - '0');
}
string PlusNumber(string number_1, string number_2)
{
    int carry = 0;
    string result;
    if(number_1.length() < number_2.length())
    {
        swap(number_1,number_2);
    }
    size_t size_difference = (number_1.length() - number_2.length());
    for(size_t i = 1; i <= size_difference; i++)
    {
        number_2.insert(0,"0");
    }
    for(int i = number_1.length() - 1 ; i >= 0; i--)
    {
            int temp_result = (carry + charplus1(number_1[i],number_2[i]));
            carry = temp_result / 10;
            temp_result = temp_result % 10;
            result.insert(0,to_string(temp_result));
    }
    if(carry)
        result.insert(0,"1");
    return result;
}
int main(void)
{
    string a = "89";
    string b = "20";
    cout<<PlusNumber(a,b);
    // cout<<charplus1('3','4');
}