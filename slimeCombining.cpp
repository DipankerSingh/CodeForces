#include<bits/stdc++.h>
using namespace std;
int getNearestPower(int n)
{
    int power=1,count=0;
    for(;power<n;power<<=1)
    {
        count++;
    }

    if(power>n)
    {
        cout<<count<<" ";
        return power/2;
    }
    else
    {
        cout<<count+1<<" ";
        return power;
    }
}

int main()
{
    long long int n;
    cin>>n;
    while(n!=1 && n!=0)
    {
    n=n-getNearestPower(n);
    }
    if(n==1)
    {
        cout<<1;
    }

}
