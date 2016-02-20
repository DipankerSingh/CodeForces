#include<iostream>
using namespace std;
int main()
{
    int input[100];
    int n;
    int preCount=0;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    if(n==1)
    {
        cout<<1-input[0];
    }
    else
    {
        for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currentCount=0;
            for(int k=0;k<n;k++)
            {
                if(k>=i && k<=j)
                {

                    currentCount=currentCount+1-input[k];
                }
                else
                {
                    currentCount=currentCount+input[k];
                }

            }
            if(currentCount>=preCount)
            {
                preCount=currentCount;
            }

        }

    }
    cout<<preCount;
    }

}
