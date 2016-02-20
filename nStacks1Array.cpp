#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int arr[MAX];
int cnt[MAX], n, p;

void push(int s)
{
    if(cnt[s]>MAX/n)
        cout<<"STACK OVERFLOW"<<endl;
    else
    {
        cin>>p;
        arr[(MAX/n)*(s-1) + cnt[s]] = p;
        cnt[s]++;
    }
}

void pop(int s)
{
    if(cnt[s] == 0)
        cout<<"STACK UNDERFLOW"<<endl;
    else
    {
        arr[(MAX/n)*(s-1) + cnt[s]-1] = -1;
        cnt[s]--;
    }
}

void top(int s)
{
    if (arr[(MAX/n)*(s-1) + cnt[s]-1]==-1)
        cout<<"STACK EMPTY"<<endl;
    else
        cout<<arr[(MAX/n)*(s-1) + cnt[s]-1]<<endl;
}

void display(int s)
{
    if(cnt[s] == 0)
        cout<<"STACK EMPTY"<<endl;
    else
    {
        for(int i = cnt[s]-1; i >= 0;i--)
            cout<<arr[(MAX/n)*(s-1) + cnt[s]-1-i]<<" ";
        cout<<endl;
    }
}
int main()
{
    cout<<"ENTER N:"<<endl;
    cin>>n;
    memset(arr,-1,sizeof(arr));
    memset(cnt,0,sizeof(cnt));
    int t, s;
    cout<<"1 FOR PUSH\n2 FOR POP\n3 FOR TOP\n4 FOR DISPLAY"<<endl;
    while(1)
    {
        cout<<"ENTER STACK NUM:"<<endl;
        cin>>s;
        cout<<"ENTER OPERATION:"<<endl;
        cin>>t;
        switch (t)
        {
        case 1:
            push(s);break;
        case 2:
            pop(s);break;
        case 3:
            top(s);break;
        case 4:
            display(s);break;
        }
    }
    return 0;
}
