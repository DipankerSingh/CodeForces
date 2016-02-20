#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
    set<long long int> s;
    long long int n,x,d,current=0,time=0,flag=0;;
    scanf("%lld %lld %lld",&n,&x,&d);

    s.insert(0);
    s.insert(x);
    set<long long int>::iterator it;
    it=s.find(current);
    for(long long int i=1;i<=n;i++)
    {
        long long int c;
        scanf("%lld",&c);
        for(long long int j=0;j<c;j++)
        {
            long long int island;
            scanf("%lld",&island);
            if(flag!=2)
            s.insert(island);
        }

        if(flag!=2)
        {
            it=s.find(current);
        while(true)
        {

            flag=0;
            if((*it)==x)
            {
                time=i;
                flag=2;
                break;
            }

            if(*(++it)-*(--it)<=d)
            {
                current=(*(++it));
                flag=1;
            }
            if(flag==0)
                break;
        }
        }
    }
    if(flag!=2)
        time=-1;
    if(time==1 && x>=d)
        time=0;
    printf("%lld",time);
    }
}
