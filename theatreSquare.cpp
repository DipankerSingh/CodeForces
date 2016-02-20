#include<iostream>
using namespace std;

long long numberOfFlagstones(long long m,long long n,long long a)
{
    long long numberOfRows;
    long long numberOfColumns;
    if(m%a==0)
        numberOfRows=m/a;
    else
        numberOfRows=(m/a)+1;

    if(n%a==0)
        numberOfColumns=n/a;
    else
        numberOfColumns=(n/a)+1;
        return numberOfRows*numberOfColumns;
}
int main()
{
    long long m,n,a;
    cin>>m>>n>>a;
    cout<<numberOfFlagstones(m,n,a);
    return 0;
}
