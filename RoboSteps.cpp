#include<bits/stdc++.h>
using namespace std;
char input[201];
int main()
{
    long long int n;
    cin>>n;
    cin>>input;
    int count=0 ;

    for(int i=0;i<n;i++)
    {
        int l=0,r=0,u=0,d=0;
        int sum=0;
            if(input[i]=='U')
            u++;
            else if(input[i]=='D')
            d++;
            else if(input[i]=='L')
            l++;
            else if(input[i]=='R')
            r++;



        for(int j=i+1;j<n;j++)
        {
            if(input[j]=='U')
            u++;
            else if(input[j]=='D')
            d++;
            else if(input[j]=='L')
            l++;
            else if(input[j]=='R')
            r++;


            if(l==r && u==d)
                count++;

        }
    }
    cout<<count<<endl;


}
