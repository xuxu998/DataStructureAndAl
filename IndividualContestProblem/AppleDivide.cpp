#include <bits/stdc++.h>
using namespace std;
int ans = 0;
#define NUMBER_OF_BUCKETS   5
int buckets[NUMBER_OF_BUCKETS + 1] = {0};
void print_bucket()
{
    for(int i = 1 ; i <= NUMBER_OF_BUCKETS; i++)
    {
        cout<<buckets[i]<<" ";
    }
    cout<<endl;
    return;
}
void AppleDivisor(int bucket_number,int number_of_apples_left,int total_of_buckets)
{
    if(bucket_number == total_of_buckets)
    {
        ans++;
        buckets[bucket_number] = number_of_apples_left;
        print_bucket();
        return;
    }
    for(int i = 0; i <= number_of_apples_left ; i++)
    {
        if(bucket_number < total_of_buckets)
        {
            int temp = number_of_apples_left;
            temp =  (temp > i) ? temp - i : 0;
            buckets[bucket_number] = number_of_apples_left - temp;
            AppleDivisor(bucket_number + 1, temp,total_of_buckets);
        }
    }
}
int main(void)
{
    int number_of_apples;
    int number_of_buckets;
    cin>>number_of_apples>>number_of_buckets;
    AppleDivisor(1,number_of_apples-number_of_buckets,number_of_buckets);
    cout<<ans;
}