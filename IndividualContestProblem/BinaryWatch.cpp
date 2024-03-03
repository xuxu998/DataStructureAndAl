#include <bits/stdc++.h>
using namespace std;
// Links for submitting
// https://leetcode.com/problems/binary-watch/description/
string temp;
void helper(int n,int number_of_bit_1,vector<string> &storage)
{
    if(n == 0)
    {
        if(number_of_bit_1 == 0)
            storage.push_back(temp);
        return;
    }
    for(int i = 0 ; i <= 1 ; i++)
    {
        if(i == 1)
        {
            number_of_bit_1--;
        }
        temp.push_back(48+i);
        helper(n-1,number_of_bit_1,storage);
        temp.pop_back();
    }
}
void generator(int number_of_bit,int number_of_bit_1,vector<string> &possible_value)
{
        helper(number_of_bit,number_of_bit_1,possible_value);
}
bool valid_minute(int minute)
{
    return minute <= 59;
}
bool valid_hour(int hour)
{
    return hour <= 11;
}
int main(void)
{
    vector<string> hours;
    vector<string> minutes;
    vector<string> result;
    int number_of_bit_in_total;
    cin>>number_of_bit_in_total;
    for(int i = 0 ; i <= number_of_bit_in_total ; i++)
    {
        generator(4,i,hours);
        generator(6,number_of_bit_in_total-i,minutes);
        for(int j = 0 ; j < hours.size(); j ++)
        {
            for(int k = 0; k< minutes.size(); k++)
            {
                int hour = stoi(hours[j],0,2);
                int minute = stoi(minutes[k],0,2);
                if(valid_hour(hour) and valid_minute(minute))
                {
                    string s = to_string(hour) + ":" + (minute < 10 ? "0" + to_string(minute) : to_string(minute));
                    result.push_back(s);
                }
            }
        }
        temp.clear();
        hours.clear();
        minutes.clear();
    }
    for(string element : result)
    {
        cout<<element<<endl;
    }

}