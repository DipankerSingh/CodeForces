#include<bits/stdc++.h>
using namespace std;
long long int table[501][501];
int main()
{
    long long int n;
    cin>>n;
    long long int k;
    cin>>k;
    int n2=n*n;
    long long int sum=(n*(((n*(k-1)+1)*2)  + ((n-1)*(n-k+1))))/2  ;


    for(int i=0;i<k-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            table[i+1][j]=(n*i)+j;
        }
    }

    long long int start=(n*(k-1));
    for(int j=0;j<n;j++)
    {
    for(int i=k;i<=n;i++)
    {
        table[i][j+1]=start+((n-k+1)*j) + i-k+1;
    }
    }
    cout<<sum<<endl;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
