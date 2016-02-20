//choose any nondegenerate triangle. Then, for each other point,
//if it is inside the triangle, we can replace one of our three triangle points and continue.
//We only need to make a single pass through the points.
// We need to be a bit careful about collinear points in this case.
#include<bits/stdc++.h>
using namespace std;
long long int findArea(long long int x1,long long int y1,long long int x2,long long int y2,long long int x3,long long int y3)
{
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)));
}


int main()
{
    long long int n;
    cin>>n;
    long long int x[n+10],y[n+10];
    for(long long int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    long long int answer[3];
    answer[0]=n,answer[1]=n-1;answer[2]=n-2;
    double area =findArea(x[n-1],y[n-1],x[n-2],y[n-2],x[n-3],y[n-3])/2.0;

    while(area==0)
    {
        answer[2]=answer[2]-1;
        area=findArea(x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1])/2.0;
    }
    for(int i=0;i<n;i++)
    {
        double a1=findArea(x[i],y[i],x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1]);
        double a2=findArea(x[i],y[i],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1]);
        double a3=findArea(x[i],y[i],x[answer[2]-1],y[answer[2]-1],x[answer[0]-1],y[answer[0]-1]);
        if(area==(a1+a2+a3)/2.0)
        {
            if((a1!=0 && a2!=0) && a3!=0)            {
                answer[2]=i+1;
                area=findArea(x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1])/2.0;
            }
            else if(a1!=0 && a2!=0)
            {
                answer[2]=i+1;
                area=findArea(x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1])/2.0;
            }
            else if(a1!=0 && a3!=0)
            {
                answer[2]=i+1;
                area=findArea(x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1])/2.0;            }
            else if(a2!=0 && a3!=0)
            {
                answer[1]=i+1;
                area=findArea(x[answer[0]-1],y[answer[0]-1],x[answer[1]-1],y[answer[1]-1],x[answer[2]-1],y[answer[2]-1])/2.0;
            }
        }
    }
    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2];


}
