#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    map<long long int,int> xPLUSy;
    map<long long int,int> xMINUSy;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(xPLUSy.find(x+y)!=xPLUSy.end())
        xPLUSy[x+y]++;
        else
        {
            xPLUSy[x+y]=1;
        }
        if(xMINUSy.find(x-y)!=xMINUSy.end())
        {
            xMINUSy[x-y]++;
        }
        else
            xMINUSy[x-y]=1;
    }
    map<long long int,int> :: iterator it1=xPLUSy.begin();
    map<long long int,int> :: iterator it2=xMINUSy.begin();
    long long int answer=0;
    for(;it1!=xPLUSy.end();it1++)
    {
        if(it1->second!=1)
        {
            answer=answer+((it1->second)*(it1->second -1))/2;
        }
    }
    for(;it2!=xMINUSy.end();it2++)
    {
        if(it2->second!=1)
        {
            answer=answer+((it2->second)*(it2->second -1))/2;
        }
    }
    cout<<answer;
}
