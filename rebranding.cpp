#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char input[n];
    cin>>input;
    map<char,char> key;
    for(int i=0;i<26;i++)
    {
        key[i+97]=i+97;
    }
    for(int i=0;i<m;i++)
    {
        char a,b;
        cin>>a>>b;
        char temp=a;
        while(key[temp]!=a)
        {
            temp=key[temp];
        }

        char temp2=b;
        while(key[temp2]!=b)
        {
            temp2=key[temp2];
        }
        key[temp]=b;
        key[temp2]=a;
        for(int i=0;i<26;i++)
        {
            cout<<key[i+97]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        input[i]=key[input[i]];
    }
    cout<<input<<endl;

}
