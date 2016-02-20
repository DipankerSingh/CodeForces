#include<bits/stdc++.h>
using namespace std;
long long int bishops[1001][1001];

int main()
{
    long long int n;
    cin>>n;

    set<pair<int,int> > present;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        bishops[x][y]=1;
        present.insert(make_pair(x,y));
    }
    set<pair<int,int> >::iterator it;
    long long int answer=0;
    for(it=present.begin();it!=present.end();it++)
    {
        int count=0;
        int x,y;
        x=it->first;
        y=it->second;
        if(bishops[x][y]!=2)
        {

            while(x!=1001 && y!=1001)
            {

                if(bishops[x][y]!=0)
                {
                    count++;
                    bishops[x][y]=2;
                }
                x=x+1;
                y=y+1;

            }

            if(count!=1)
            {
                bishops[it->first][it->second]=2;
                answer=answer+((count*(count-1))/2);
            }
        }
    }

    for(set<pair<int,int> >::reverse_iterator it1=present.rbegin();it1!=present.rend();it1++)
    {
        int count=0;
        int x,y;
        x=it1->first;
        y=it1->second;
        if(bishops[x][y]!=3)
        {

            while(x!=0 && y!=1001)
            {

                if(bishops[x][y]!=0)
                {
                    count++;
                    bishops[x][y]=3;
                }
                x=x-1;
                y=y+1;

            }
            if(count!=1)
                {
                    answer=answer+(count*(count-1))/2;
                }
        }
    }

   cout<<answer;

}
