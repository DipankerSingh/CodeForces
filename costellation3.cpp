//choose an arbitrary point. Then, sort all other points by angle about this point.
//Then, we can just choose any two other points that have different angles,
// breaking ties by distance to the chosen point. (or breaking ties by two adjacent angles).
#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> getSlope(long long int x,long long int y)
{
    long long int g=__gcd(abs(x),abs(y));
    x=x/g;
    y=y/g;
    if(x<0 || (x==0 && y<0))
    {
        x=-x;
        y=-y;
    }
    pair<long long int,long long int> toBeReturned;
    toBeReturned.first=x;
    toBeReturned.second=y;
    return toBeReturned;
}
int main()
{
    map<pair<long long int,long long int>,pair<long long int,int> > slopes;
    long long int n;
    cin>>n;    long long int x[n],y[n];
    cin>>x[0]>>y[0];
    int answer[3];
    answer[0]=1;
    for(int i=1;i<n;i++)
    {
        cin>>x[i]>>y[i];
        pair<long long int,long long int> p=getSlope(x[i]-x[0],y[i]-y[0]);

        long long int distance=((x[i]-x[0])*(x[i]-x[0]))+((y[i]-y[0])*(y[i]-y[0]));
        if( slopes.find(p)==slopes.end() ||(slopes.find(p)!=slopes.end() && (slopes.find(p))->second.first > distance) )
        {
            pair<long long int,int> q;
            q.first=distance;
            q.second=i+1;
            slopes[p]=q;
        }

    }
    map<pair<long long int,long long int>,pair<long long int,int> > ::iterator it=slopes.begin();    map<pair<long long int,long long int>,pair<long long int,int> > ::iterator it1;

  //  for(;it!=slopes.end();it++)
    //    cout<< it->second.first <<" "<< it->second.second <<endl;

    long long int distance=9000000000000000000;

    for(it=slopes.begin();it!=slopes.end();it++)
    {
        if(it->second.first < distance)
        {            it1=it;
            answer[1]=it->second.second;
            distance=it->second.first;
        }
    }
    slopes.erase(it1);


    //for(it=slopes.begin();it!=slopes.end();it++)
      //  cout<<it->second.second<<" " << it->second.first<<endl;



    distance=9000000000000000000;

    for(it=slopes.begin();it!=slopes.end();it++)
    {


        if(it->second.first <= distance)
        {
            answer[2]=it->second.second ;
            distance=it->second.first;
        }
    }

    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2];

}
