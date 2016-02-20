#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    long long int n,x,d,current=0,next=0;
    scanf("%lld %lld %lld",&n,&x,&d);
    vector<long long int> stones(100001);
    for(int i=1;i<=n;i++)
    {
        long long int c;
        scanf("%lld",&c);
        for(int j=0;j<c;j++)
        {
            long long int island;
            scanf("%lld",&island);
            stones[island]=i;
        }
    }

    while(true)
    {
        int flag=0,min=1000000;
        for(int i=((current+d)>=x?x:current+d);i>current;i--)
        {
            if((stones[current]>=stones[i] && stones[i]>0) || (i==x))
            {
                stones[i]=stones[current];
                current=i;
                next=current;
                if(current==x)
                {
                    printf("%lld",stones[current]);
                    return 0;
                }
                flag=1;
                break;
            }
            else if(stones[i]<min && stones[i]>0)
            {
                min=stones[i];
                next=i;
                flag=1;
            }
        }
        current = next;

        if(flag==0)
        {
            printf("-1");
            return 0;
        }

    }
    }
}
