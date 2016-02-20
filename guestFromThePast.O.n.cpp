#include<bits/stdc++.h>
using namespace std;


int main(){
    long long int count=0;
    long long int n,a,b,c;
    cin>>n>>a>>b>>c;
    while(n>=a || n>=b)
    {
        if(b-c<a)
        {
           if(n>=b)
           {
               count++;
               n=n-b;
               n=n+c;
           }
           else
           {
               if(n>=a)
               {
                    count++;
                    n=n-a;
               }
           }

        }
        else
        {
           count++;
           n=n-a;
        }

    }
    cout<<count<<endl;


}
