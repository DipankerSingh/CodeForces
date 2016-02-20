// i am solving this using layer by layer method
//where layers are along the y axis;
#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n ;
    cin>>n;
    set <pair<pair<long long int,long long int> ,long long int > > coordinates;
    for(int i=0;i<n;i++)
    {
        //cout<<"Enter Coordinates"<<endl;
        pair<long long int,long long int> p;
        cin>>p.first>>p.second;
        pair< pair<long long int,long long int> ,long long int > input;
        input.first=p;
        input.second=i+1;
        coordinates.insert(input);

    }


    int flag=0;
    set <pair<pair<long long int,long long int>,long long int > >::iterator it1=coordinates.end();
    set <pair<pair<long long int,long long int>,long long int > >::iterator it2=coordinates.end();
    set <pair<pair<long long int,long long int>,long long int > >::iterator it3=coordinates.end();
    for(set <pair<pair<long long int,long long int> ,long long int > >::iterator it=coordinates.begin();it!=coordinates.end();it++)
    {

        if(it1==coordinates.end())
        {
            it1=it;
        }
        else if((--it)->first.first == (++it)->first.first && flag==0)
        {

            if(it2==coordinates.end())
            {
                it2=it;
                flag=1;
            }
            else if(it3==coordinates.end())
            {
                it3=it;
                break;
            }
        }
        else
        {
            if(it2==coordinates.end())
            {
                it2=it;
            }
            else if(flag==1 && (--it)->first.first != (++it)->first.first )
            {
                it3=it;
                break;
            }
            else if((--it)->first.first != (++it)->first.first)
            {
                double slope=(((double)it2->first.second)-((double)it1->first.second))/(((double)it2->first.first)-((double)it1->first.first));
                if((((double)it->first.second)-((double)it2->first.second))/(((double)it->first.first)-((double)it2->first.first))!=slope)
                {
                    it3=it;
                    break;
                }
            }
        }
    }
    cout<<(*it1).second<<" "<<(*it2).second<<" "<<(*it3).second;


}
