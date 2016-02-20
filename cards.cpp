#include<bits/stdc++.h>
using namespace std;
char input[201];
int main()
{
    long long int n;
    cin>>n;
    cin>>input;
    int len = strlen(input);
    int R=0,B=0,G=0;
    for(int i=0;i<len;i++)
    {
            if(input[i]=='R')
            R++;
            if(input[i]=='B')
            B++;
            if(input[i]=='G')
            G++;

    }
    if(R!=0 && (B!=0 && G!=0))
        cout<<"BGR"<<endl;
    else if(R!=0 && (B==0 && G==0))
        cout<<'R'<<endl;
        else if(B!=0 && (R==0 && G==0))
        cout<<'B'<<endl;
        else if((G!=0 && (B==0 && R==0)))
        cout<<'G'<<endl;
        else if(G==0)
        {
            if(B==1 && R==1)
            {
                cout<<'G'<<endl;
            }
            else if(B>=2 && R>=2)
            {
                cout<<"BGR"<<endl;
            }
            else if(B==2 && R==1)
            cout<<"GR"<<endl;
            else
            cout<<"BG"<<endl;
        }
        else if(B==0)
        {
            if(G==1 && R==1)
            {
                cout<<'B'<<endl;
            }
            else if(G>=2 && R>=2)
            {
                cout<<"BGR"<<endl;
            }
            else if(G==2 && R==1)
            cout<<"BR"<<endl;
            else
            cout<<"BG"<<endl;
        }
        else if(R==0)
        {
            if(B==1 && G==1)
            {
                cout<<'R'<<endl;
            }
            else if(B>=2 && G>=2)
            {
                cout<<"BGR"<<endl;
            }
            else if(B==2 && G==1)
            cout<<"GR"<<endl;
            else
            cout<<"BR"<<endl;
        }

}
