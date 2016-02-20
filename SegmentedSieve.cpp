#include<bits/stdc++.h>
using namespace std;

void simpleSieve(int limit,vector<int> &prime)
{
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    for(int i=2;i*i<=limit;i++)
    {
        if(mark[i]==true)
        {
            for(int p=i*i;p<=limit;p=p+i)
            {
                mark[p]=false;
            }
        }
    }
    for(int p=2;p<=limit;p++)
    {
        if(mark[p]==true)
        {
            prime.push_back(p);
        }
    }
}
void segmentedSieve(long long int a,long long int n)
{
    int limit=floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(limit,prime);

    if(a<=limit)
    {
        for(int i=0;i<prime.size();i++)
        {
            if(prime[i]>=a)
                cout<<prime[i]<<endl;
        }

        int low=limit+1;
        int high=limit+low;

    while(low<n)
    {
        bool mark[limit+1];
        memset(mark,true,sizeof(mark));
        for(int i=0;i<prime.size();i++)
        {
            int loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim=loLim+prime[i];

            for(int j=loLim;j<high;j=j+prime[i])
                mark[j-low]=false;
        }

        for(int i=low;i<high;i++)
        {
            if(i>=a && mark[i-low]==true)
                cout<<i<<endl;
        }

        low=low+limit;
        high=high+limit;
        if(high>=n)
            high=n+1;


    }
    }
    else {
    int low=a;
    int high=a+limit;
    if(high>=n)
            high=n+1;

    while(low<n)
    {
        bool mark[limit+1];
        memset(mark,true,sizeof(mark));
        for(int i=0;i<prime.size();i++)
        {
            int loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim=loLim+prime[i];

            for(int j=loLim;j<high;j=j+prime[i])
                mark[j-low]=false;
        }

        for(int i=low;i<high;i++)
        {
            if(i>=a && mark[i-low]==true)
                cout<<i<<endl;
        }

        low=low+limit;
        high=high+limit;
        if(high>=n)
            high=n+1;


    }
    }

}
int main()
{
    long long int t,a,b;
    cin>>t;
    while(t--)
    {
       cin>>a>>b;
       if(a==b)
       {    int count=0;
           for(int i=1;i<=a;i++)
           {
               if(a%i==0)
                count++;
               if(count >=2)
               {
                   if(i==a)
                   {
                       cout<<a<<endl;
                   }
                   break;
               }

           }
       }
       else
        segmentedSieve(a,b);

       cout<<endl;
    }
}
