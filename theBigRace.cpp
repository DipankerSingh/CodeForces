#include<bits/stdc++.h>
using namespace std;

class gcd
{
  int a,b;
	public:
    long long int finder(long long int c,long long int d);

}g1;
long long int gcd::finder(long long int c,long long int d)

{
	a=c;
	b=d;
	while(a!=b)

	{
		if(a>b)
		a=a-b;
		else
		b=b-a;

	}
	return a;
}


int main()
{
    long long t,w,b;
    cin>>t>>w>>b;
    long long int x=t/w;
    long long int y=t/b;
    long long int z=(t/((w*b)/(g1.finder(w,b))));
    long long int n=t-x-y+2*z;
    long long int d=t;
    long long int r=g1.finder(n,d);
    cout<<n/r<<"/"<<d/r;

}
