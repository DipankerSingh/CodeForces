#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int suspect1=n-2,suspect2=n-1;
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int permutation[50]={0};
    permutation[n-1]=matrix[n-2][n-1];

    for(int i=n-2;i>=0;i--)
    {
        int flag=0;
        if(permutation[suspect2]<matrix[i][suspect2])
        {
            int temp=permutation[suspect1];
            permutation[suspect1]=permutation[suspect2];
            permutation[suspect2]=temp;
            suspect1--;
            flag++;
        }
        if(permutation[suspect2]<=matrix[i][suspect2])
        {
            if(flag==0)
            {
                permutation[i]=max(matrix[i][suspect2],matrix[i][suspect1])+1;
                suspect1=i;
            }
            else
            {
            permutation[suspect2]=matrix[i][suspect2];
            permutation[i]=matrix[i][suspect2]+1;
            }
            flag++;
        }

        if(flag==0)
        {
            permutation[i]=min(matrix[i][suspect1],matrix[i][suspect2]);
        }

    }

    for(int i=0;i<n;i++)
        cout<<permutation[i]<<" ";
}
