#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag=0;
    cin>>n;
    vector<int> bar(n);
    for(int i=0;i<n;i++)
    {
        cin>>bar[i];
        if(bar[i]==1)
        {
            flag=1;
        }
    }

    if(flag==0)
    {
        cout<<0;
        return 0;
    }

    long long int answer=1,count=1,last1Postion=-1,last0Position=-1;

    for(int i=0;i<n;i++)
    {

        if(bar[i]==1)
        {
            if(last1Postion==-1)
            {
                last1Postion=i;
            }
            else if(last1Postion-i==1)
            {
                count=1;
                answer=answer*count;
                last1Postion=i;
            }
            else if(last1Postion!=-1)
            {
                answer=answer*count;
                count=1;
                last1Postion=i;
            }

        }

        if(bar[i]==0)
        {
            if(last0Position==-1)
                last0Position=i;

            if(last1Postion!=-1)
            {
                count=i-last1Postion+1;
            }

        }
    }

    cout<<answer<<endl;

}
