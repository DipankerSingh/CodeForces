
#include<bits/stdc++.h>
using namespace std;

void simpleSieve(int limit,vector<int> &prime)
{
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    for(int i=2;i*i<limit;i++)
    {
        if(mark[i]==true)
        {
            for(int p=i*i;p<limit;p=p+i)
            {
                mark[p]=false;
            }
        }
    }
    for(int p=2;p<limit;p++)
    {
        if(mark[p]==true)
        {
            prime.push_back(p);
        }
    }
}
void segmentedSieve(long long int a,long long int n,vector<int> &prime)
{
    int limit=floor(sqrt(n))+1;

    simpleSieve(limit,prime);

    int low=limit;
    int high=2*limit;

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
            if(mark[i-low]==true)
                prime.push_back(i);
        }

        low=low+limit;
        high=high+limit;
        if(high>=n)
            high=n;


    }

}
int main()
{
    long long int t,a,b;
    vector<int> prime;
    segmentedSieve(2,1000000000,prime); // bad TLE
    cin>>t;
    while(t--)
    {
       cin>>a>>b;
       for(int i=0;i<prime.size();i++)
       {
           if(prime[i]>=a && prime[i]<=b)
            cout<<prime[i]<<endl;
       }
       cout<<endl;
    }
}
