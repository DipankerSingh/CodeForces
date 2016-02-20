#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int nearestPowerOf26(int n)
{
    int count=0;
    while(n>26)
    {
        n=n/26;
        count++;
    }
    return count;
}

char* numericToAlphabetic(int n)
{
    int j=0;
    char toBeReturned[100000];
    int i=0;
    int nearestPower=nearestPowerOf26(n);
    while(nearestPower!=0)
    {
        toBeReturned[i]=(n/(26*nearestPower))+64;
        n=n%(26*nearestPower);
        i++;
        nearestPower--;
    }
    toBeReturned[i]=(n/(26*nearestPower))+64;
    return toBeReturned;
}



char* convertCode(char* input)
{
    int length=strlen(input);
    int end=length;
    int n=0;
    int i=0;
    while(*(input+end-1)>=48 && *(input+end-1)<=57)
    {
        n=n+((*(input+end-1))-48)*pow(10,i);
        end--;
    }

    cout<<numericToAlphabetic(n);

}
int main()
{
    int n;
    char input[100000];
    char output[100000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input;

    }
    char* converted=convertCode(input);



}
