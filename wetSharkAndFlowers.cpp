#include<bits/stdc++.h>
using namespace std;
long long int nonDivisible(long long int l,long long int r,long long int p)
{
    long long int a=((r/p)-((l-1)/p));
    return a;

}
int main()
{

    int n,p;
    cin>>n>>p;

    double l[n],r[n],a[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        a[i]=nonDivisible(l[i],r[i],p);

    }
    double probability=0;
    for(int i=0;i<n;i++)
    {
        probability=probability+ (1.0000000000000000-((((r[i]-l[i]+1-a[i])*(1.0000000000000000))/((r[i]-l[i]+1))*((r[(i+1)%n]-l[(i+1)%n]+1-a[(i+1)%n]*(1.0000000000000000)))/(r[(i+1)%n]-l[(i+1)%n]+1))));

    }


    cout<<setprecision(9)<<fixed<<probability*2000;




}
