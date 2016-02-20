#include<bits/stdc++.h>
using namespace std;
int main()
{
    int minA=1000,minB=1000;
    int b[8]={0},w[8]={0};
    int b1[8]={0},w1[8]={0};
    for(int i=1;i<=8;i++)
    {
        for(int j=0;j<8;j++)
        {
            char a;
            cin>>a;
            if(a=='B')
            {
                b[j]=i;
                if(b1[j]==0)
                {
                    b1[j]=i;
                }

            }
            if(a=='W')
            {
                w1[j]=i;
                if(w[j]==0)
                {
                    w[j]=i;
                }
            }

        }
    }

    for(int i=0;i<8;i++)
    {

        if(w[i]==0 && b[i]!=0 )
        {

            int a=8-b[i];
                if(a<minB)
                {
                    minB=a;
                }
            }
            if(b[i]==0 &&w [i]!=0)
            {
                int b=w[i]-1;
                if(b<minA)
                {
                    minA=b;
                }
            }
            if(b[i]!=0 && w[i]!=0)
            {
                if(b[i]>w[i])
                {
                    if(w1[i]<b[i])
                    {
                        int a=8-b[i];
                        if(a<minB)
                        {
                            minB=a;
                        }
                    }
                    if(b1[i]>w[i])
                    {
                        int b=w[i]-1;
                        if(b<minA)
                        {
                            minA=b;
                        }
                    }
                }

        }
    }
    if(minA<=minB)
    cout<<"A";
    else
    cout<<"B";
}
