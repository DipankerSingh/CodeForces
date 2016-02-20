#include<bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);

}
int main()
{
    long long int l,r,k;
    cin>>l>>r>>k;
    long long int digits2=k,count2=0;
    while(digits2!=0)
        {
            digits2=digits2/10;
            count2++;

        }
    long long int a=floor(log(l)/log(k));

    int flag=0;
    long long int ans=power(k,a);

    if(ans<l)
    {
        long long int count1=0,i=10,digits1=ans;
        while(digits1!=0)
        {
            digits1=digits1/i;
            count1++;
        }
        if(count1+count2<=19)
        ans=ans*k;
        else
            {
                cout<<-1;
                return 0;
            }
    }

    while(ans<=r)
    {
        cout<<ans<<" ";
        long long int digits=ans,i=10,count=0;
        while(digits!=0)
        {
            digits=digits/i;
            count++;
        }

        int b=count2+count;

        if(count2+count<=20)
        {
            ans=ans*k;
            flag=flag+1;
        }
        else
        {
            return 0;
        }
    }
    if(flag==0)
    {
        cout<<-1;
    }
    return 0;
}
