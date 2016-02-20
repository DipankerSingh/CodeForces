#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int count100=0,count200=0,sum=0;
for(int i=0;i<n;i++)
{
    int a;
    cin>>a;
    sum=sum+a;

    if(a==100)
    {
    count100++;
    }
    else
    {
    count200++;
    }
}


if((sum/100)%2!=0)
    {
    cout<<"NO";
    return 0;
    }
    else
    {
        if(count100%2==0&&count200%2==0)
        {
            cout<<"YES";
        }
        else
        {

            if(count100==0&&(count200)%2!=0)
            {
                cout<<"NO";
            }
            else
            {
                cout<<"YES";
            }

        }
    }

}
