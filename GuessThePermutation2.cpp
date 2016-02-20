#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int input[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
    }
    int permutation[n];
    for(int i=0;i<n;i++)
    {
        permutation[i]=*max_element(*(input+i),*(input+i)+n);
    }
    for(int i=0;i<n;i++)
    {
        if(permutation[i]==n-1)
        {
            permutation[i]++;
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<permutation[i]<<" ";
    }


}
