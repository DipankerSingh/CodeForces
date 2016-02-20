#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int minOdd=1000000000;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        long long int a;
        cin>>a;
        sum=sum+a;
        if(a%2!=0 && a<minOdd)
            minOdd=a;
    }

    if(sum%2==0)
        cout<<sum;
    else
        cout<<sum-minOdd;

}
