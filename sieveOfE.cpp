#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int check[100010];
int floorSqrt(int x)
{

    if (x == 0 || x == 1)
       return x;


    int i = 1, result = 1;
    while (result < x)
    {
       if (result == x)
          return result;
       i++;
       result = i*i;
    }
    return i-1;
}
int main()
{
    int t,a,b;

    cin>>t;
    while(t)
    {
        cin>>a>>b;

        memset(check,0,sizeof(check));

       //int p=floorSqrt(b);
        for(int i=2;i*i<=b;i++)
        {
            if(check[i]==0)
            {
                for(int j=i*i;j<=b;j=j+i)
                {
                    check[j]=1;
                }
            }
        }
        for(int i=a;i<=b;i++)
        {
            if(check[i]==0&&i!=1)

                cout<<i<<endl;
        }
        t--;
        cout<<endl;
    }
}
