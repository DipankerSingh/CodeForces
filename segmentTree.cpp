#include<bits/stdc++.h>
using namespace std;
struct SegmentTreeNode
{

    // variables to store aggregate statistics and
    // any other information required to merge these
    // aggregate statistics to form parent nodes
    void assignLeaf(T value) {
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
  }
    void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
  }
    V getValue() {
    // V is the type of the required aggregate statistic
    // return the value of required aggregate statistic
    // associated with this node
  }

};

void buildTree(T arr[],int stIndex,int lo,int hi)
{
    if(lo==hi)
    {
        nodes[stIndex].assignLeaf(arr[lo]);
        return ;
    }

    int right = 2*stIndex, right=left+1, mid=(lo+hi)/2;
    buildTree(arr,left,lo,mid);
    buildTree(arr,right,mid+1,hi);
    nodes[stIndex].merge(nodes[left],nodes[right]);
}
int getSegmentTreeSize(int N)
{
    int size=1;
    for(; size<N; size <<= 1);
    return size << 1;
}
V getValue(int lo,int hi)
{
    SegmentTreeNode result=getValue(1,0,N-1,lo,hi);
    return result.getValue();
}
SegmentTreeNode getValue(int stIndex,int left,int right,int lo,int hi)
{
    if(left==lo && right==hi)
        return nodes[stIndex];

    mid=(left+right)/2;

    if(lo>mid)
        return getValue(2*stIndex +1,mid+1,hi,)

}


int main()
{
    cout<<getSegmentTreeSize(12)<<endl;
}
