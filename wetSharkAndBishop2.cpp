#include<bits/stdc++.h>
using namespace std;
long long int present[1001][1001];
long long int sendRaysRD(int x,int y)
{
    int count=0;
    while(x!=1001 && y!=1001)
    {
        if(present[x][y]==1)
        {
            count++;
        }
        x=x+1;
        y=y+1;
    }
    if(count!=1)
    {
        return (count*(count-1))/2;
    }
    return 0;
}

long long int sendRayRU(int x,int y)
{
    int count=0;
    while(y!=1001 && x!=0)
    {
        if(present[x][y]==1)
        {
            count++;
        }
        x=x-1;
        y=y+1;
    }
    if(count!=1)
    {
        return (count*(count-1))/2;
    }

    return 0;
}
int main()
{
    long long int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        present[x][y]=1;
    }
    long long int answer=0;
    for(int i=1;i<1001;i++)
    {
          answer=answer+sendRaysRD(1,i);
          answer=answer+sendRaysRD(i,1);
          answer=answer+sendRayRU(1000,i);
          answer=answer+sendRayRU(i,1);
    }
    answer=answer-sendRaysRD(1,1);
    answer=answer-sendRayRU(1000,1);

    cout<<answer<<endl;
}
