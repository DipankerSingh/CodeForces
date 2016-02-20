#include<iostream>
using namespace std;
int main()
{
    long long int a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        {
            int count =0;
            for(int j=1;j<=i;j++)
            {
                if(i%j==0)
                    count++;
                if(count>=2)
                {
                    if(j==i)
                        {
                            cout<<i<<endl;
                        }
                    break;
                }
            }

        }
        cout<<endl;
    }
}
