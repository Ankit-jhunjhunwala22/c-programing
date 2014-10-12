/*program to find bfs ,using adjacency list*/
/*
ouput:
enter no of nodes5
3 1 3 4
2 0 2
3 1 3 4
3 0 2 4
2 0 2
enter starting root
3

At label 0::
3
At label 1::
0 2 4
At label 2::
1
*/
#include<iostream>
using namespace std;
int visited[20];
int rear=0;
int first=0;
struct q{
int value;
int label;
}que[20];
int main()
{
visited[0]=0;//array partially initialized ,get zero in all it's position
int n,i,j,adjacent,l=0,k;
cout<<"enter no of nodes";
cin>>n;
int *list[n],*linked;
for(i=0;i<n;i++)
{
    cin>>adjacent;
    linked=new int[adjacent+1];
    for(j=0;j<adjacent;j++)
    {
      cin>>linked[j];
    }
    linked[j]=9999;
    list[i]=linked;
}
cout<<"enter starting root\n";
cin>>que[first].value;
que[first].label=l++;
visited[que[first++].value]=1;
while(first!=n)
{
    k=0;
    while(list[que[rear].value][k]!=9999)
        {
            if(visited[list[que[rear].value][k]]==0)
            {
                visited[list[que[rear].value][k]]=1;
                que[first].value=list[que[rear].value][k];
                que[first++].label=l;
            }
            k++;
        }
        l++;
        rear++;
}
int pre=-1;
for(i=0;i<n;i++)
{
    if(pre!=que[i].label)
    {
        cout<<"\nAt label "<<que[i].label<<":: \n";
    }
    pre=que[i].label;
    cout<<que[i].value<<" ";
}
}
