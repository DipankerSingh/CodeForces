#include<bits/stdc++.h>
using namespace std;
char gogol[1000000];
char apple[1000000];
int main()
{


    cin>>gogol>>apple;
    int count=0;

    long long int alength = strlen(apple);
    long long int i=0,j=0;
    int start=i;
    while(start!=glength)
    {

        i=start;
        bool goToMainLoop = false;
        while(j!=alength && goToMainLoop==false)
        {
            if(gogol[i]==apple[j])
            {
                if(j==alength-1)
                {

                    count++;
                    goToMainLoop=true;
                }
                i++;
                if(i==glength)
                {
                    cout<<count;
                    return 0;
                }
                j++;
            }
            {
                start++;
                goToMainLoop=true;
            }

        }
    }


}