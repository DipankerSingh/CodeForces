#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n ;
    int input[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    sort(input,input+n);
    long long int difference[5001]={0};
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            difference[input[j]-input[i]]++;
        }
    }
    int minDifference=0;
    for(int i=0;i<5001;i++)
    {
        if(difference[i]>=1)
        {
            minDifference=i;
            break;
        }

    }
    long long int count=0;
    for(int i=0;i<)

}
