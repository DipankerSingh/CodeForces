#include<bits/stdc++.h>
using namespace std;


int main(){
    long long int count=0;
    long long int n,a,b,c;
    cin>>n>>a>>b>>c;
    if((b-c)<=a && n>=b)
    {
        count=(n-c)/(b-c);
        n=n-count*(b-c);

        if(n>=a)
        {
            count=count+n/a;
        }
    }
    else
    {
        count=n/a;
    }

    cout<<count<<endl;
}
