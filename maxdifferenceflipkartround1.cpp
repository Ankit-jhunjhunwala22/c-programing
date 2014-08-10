/*
find the maximum difference between largest number and smallest number in an integer array 
constraint that the largest number should have position greater than smallest number
if not so find the next smaller number
if (largest,smallest) pair satisfying the constraint is not found return -1
*/


#include<iostream>
using namespace std;
struct node
{
    int data;
    int pos;
};
int max(int *a,int n)
{
    int i,j,tem1,tem2;
    struct node np[100];
    for(i=0;i<n;i++)
    {
        np[i].data=*(a+i);
        np[i].pos=i;
    }
    for(i=0;i<n;i++)
    {
       tem1=np[i].data;
        for(j=i+1;j<n;j++)
        {
            if(tem1<=np[j].data)
            {
                tem1=np[j].data;
                tem2=np[j].pos;
                np[j].data=np[i].data;
                np[j].pos=np[i].pos;
                np[i].data=tem1;
                np[i].pos=tem2;
            }
        }
    }

cout<<"\n";
    for(i=n-1;i>=0;i--)
    {
                if(np[0].data>np[i].data)
        {
            if(np[0].pos>np[i].pos)
            {
                return (np[0].data-np[i].data);
            }
        }
    }
    return -1;
}
int main()
{
    int a[]={7,9,2,5,6};
    cout<<max(a,5);
}
