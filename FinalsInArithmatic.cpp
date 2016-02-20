/*  .___.__                     __
  __| _/|__|__________    ____ |  | __ ___________
 / __ | |  \____ \__  \  /    \|  |/ // __ \_  __ \
/ /_/ | |  |  |_> > __ \|   |  \    <\  ___/|  | \/
\____ | |__|   __(____  /___|  /__|_ \\___  >__|
     \/    |__|       \/     \/     \/    \/
============================================================================================================================*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char input[100005];
    int n[100005];
    cin>>input;
    int len=strlen(input);

    for(int i=0;i<len;i++)n[i]=input[i]-'0';

    //here our answer can be of length n or n-1
    //depending upon the leftMost Digit of the given n
    //weather it was a carry or not
    //Since it is pretty clear that maximum carry over can be 1;
    //So we can easily determine answer length (n or n-1)
    //I have also maintained a sum array to store sum of each significant place.
    int sum[len];
    memset(sum,0,sizeof(sum));    int flag=0;
    //I have used variable flag to denote to mark 2 different cases
    //flag=1 ---> answer of length n
    //flag=2 ---> answer of length n-1
    //flag=3 ---> not sure of answer Length (only one case,think!)
    if(n[0]==1 && n[len-1]!=1)
    {
        //then answer will be of length n-1 for sure
        //as the leftmost digit is carry .

        flag=2;
    }
    else if(n[0]==1 && n[len-1]==1)
        flag=3; // we dont know the answer length in this case
    else
        flag=1;

    // now first solving for the case of flag=3;
    //when I can not decide the length of answer

    if(flag==3)
    {
        //solving assuming that the answer length is n;
        // ie. first digit is not a carry
        // ie. sum of the first and the  last digit is equal to 1
        int carryL=0; // currently 0 since we assumed sum is 1 not 11.
        int carryR=0; // currently 0 since both leftMost digit and the RightMost digit are equal;
        int L=0,R=len-1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
        sum[R+1]=1;
        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }

                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
                else
                {

                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
            }
            else if(n[L]<n[R] )
            {
                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<"0"<<endl;
                    return 0;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
                else
                {

                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                    //cout<<"Answer is of length n-1"<<endl;
                    flag=2;
                    carryR=0;
                    carryL=1;
                    memset(sum,0,sizeof(sum));
                    break;
                    }

                }
            }
            else // n[L]>n[R]
            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                }
                else if(carryL==1)
                {
                     if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                    //cout<<"Answer of length n was not possible"<<endl;
                    flag=2;
                    carryR=0;
                    carryL=1;
                    memset(sum,0,sizeof(sum));
                    break;
                    }

                }

            }
        }
    }
    // now we are sure about Flag 3; if answer was present it would have been printed
    // now if answer is possible it will be from flag=2;
    if(flag==2)
    {
        // this is the case when answer will be of length n-1;
        int L=1;
        int R=len-1;

        int carryL=1;
        int carryR;
        if(n[L]==n[R])
            {
                carryR=0;
                sum[R]=10+n[L];
            }
        else if (n[L]>n[R])
            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else
                {
                    carryR=1;
                    sum[R]=10+n[R];
                    if(n[L]-n[R]>1)
                {
                    cout<<"0";
                    return 0;
                }
                }
            }
        else
        {
            cout<<0<<endl;
            return 0;
        }
        if(++L == R)
        {
            if(carryL==carryR)
                L--;
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }

        R--;        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {

                        sum[R]=n[R];
                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
                else
                {
                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
            }
            else if(n[L]<n[R])
            {
                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<0<<endl;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
                else
                {
                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }
            }
            else // n[L]>n[R]
            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                }
                else if(carryL==1)
                {
                     if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }

            }
        }


    }
    else if(flag==1)
    {
      // this is the case when the answer is surely of length n;
      int carryL=0;
      int carryR;
      int L=0;
      int R=len-1;
      if(n[L]==n[R])
      {
        carryR=0;
        sum[R]=n[L];
      }
      else if(n[L]>n[R])
      {
        if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
            {
                cout<<"0"<<endl;
                return 0;
            }
        carryR=1;
        sum[R]=n[R];

      }
      else
      {
        cout<<'0'<<endl;
        return 0;
      }
        if(++L == R)
        {
            if(carryL==carryR)
                L--;
            else
            {
                cout<<0<<endl;
                return 0;
            }
        }

      R--;
        while(L<=R)
        {
            if(n[L]==n[R])
            {
                if(carryL==0)
                {
                   if(carryR==0)
                    {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+10;

                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
                else
                {

                    if(carryR==0)
                    {
                        if(n[R]==0)
                        {
                        cout<<0<<endl;
                        return 0;
                        }
                        sum[R]=n[R]-1;
                        carryR=1;
                        carryL=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                   else
                    {
                        sum[R]=n[R]+9;
                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                }
            }
            else if(n[L]<n[R])
            {
                if(n[R]-n[L]>1 && !(n[R]-n[L]==9 && carryR==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==1)
                {
                    if(carryR==0)
                    {
                        sum[R]=n[L];

                        carryL=0;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                    }
                    else if(carryR==1)
                    {
                        sum[R]=n[L]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }
                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                }
                else
                {
                    //this is wrong, forgot the case of n[L]=0, n[R]=9;
                    // first i thought that n[L] will be less than n[R] only in the case
                    // when n[L] didn't get carry but n[R] got carry
                    // but there can be a case when n[L] got carry but n[R] does not,
                    // i.e sum [L]=9; and sum[R]=9;
                    if(n[R]-n[L]==9 && carryR==1)
                    {
                        sum[R]=9;

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }
            }
            else // n[L]>n[R]
            {
                if(n[L]-n[R]>1 && !(n[L]-n[R]==9 && carryL==1))
                {
                    cout<<0<<endl;
                    return 0;
                }
                else if(carryL==0)
                {
                   if(carryR==0)
                   {
                        sum[R]=n[R];

                        carryL=0;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                   else
                   {
                        sum[R]=n[R]+10;
                        if(sum[R]>18)
                        {
                            cout<<0<<endl;
                            return 0;
                        }

                        carryL=1;
                        carryR=1;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;
                   }
                }
                else if(carryL==1)
                {
                   if(n[L]-n[R]==9 )
                    {
                        sum[R]=9;

                        carryL=1;
                        carryR=0;
                        if(++L == R)
                        {
                            if(carryL==carryR)
                                L--;
                            else
                            {
                                cout<<0<<endl;
                                return 0;
                            }
                        }
                        R--;

                    }
                    else
                    {
                        cout<<'0'<<endl;
                        return 0;
                    }
                }

            }
        }
    }


    // now we have successfully generated
    // sum array containing the sum of
    // digits of each significant digit
    if(flag==1 || flag==3)
    {
        int aLength=len;
        int L=0;
        int R=len-1;
        //for(int i=0;i<len;i++)
        //{
        //    cout<<sum[i]<<endl;
        //}
        if(aLength%2!=0 && sum[int(aLength/2)]%2!=0)
            {
                cout<<'0'<<endl;
                return 0;
            }
        int answer[len];
        while(L<=R)
        {
            sum[L]=sum[R];
            if(sum[L]%2==0)
                answer[L]=answer[R]=sum[L]/2;
            else
            {
                answer[R]=sum[L]/2;
                answer[L]=answer[R]+1;
            }
            L++;
            R--;
        }
        for(int i=0;i<len;i++)
            cout<<answer[i];



    }
    else
    {
        int aLength=len-1;
        int L=1;
        int R=aLength;
        if(aLength%2!=0 && sum[(aLength+1)/2]%2!=0)
           {
            cout<<'0'<<endl;
            return 0;
           }
        int answer[len];
        while(L<=R)
        {
            sum[L]=sum[R];
            if(sum[L]%2==0)
                answer[L]=answer[R]=sum[L]/2;
            else
            {
                answer[R]=sum[L]/2;
                answer[L]=answer[R]+1;
            }
            L++;
            R--;
        }

        for(int i=1;i<len;i++)
            cout<<answer[i];


    }




}
