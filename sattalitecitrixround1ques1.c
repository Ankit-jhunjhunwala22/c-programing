/*given a two city a ,b .city a scientist devlop a sattalite to find no of soldier of city b,but there is a flaw 
in the lens of the sattalite,so as  programmers we have to help city a in finding exact no of soldiers of city b
assumption given:1)given a image matrix,containing 0 and 1
                 2)each 1 represent a soldier(ideally)
                 3)since there is flaw in lens cell having set to 1 with all the adjacent cell(side by side or diagonally)
                 is one soldier.
                 4)first line of input is m*m image matrix
                 5)followed by image matrix
                 6)output is number of soldiers
sample input: 3 
              0 0 0 1 0 1
              0 0 1 0 0 1
              1 1 1 0 0 1
ouput:2

*/ 

#include<iostream>
using namespace std;
int arr[100][100];
int visit[100][100];
void visited(int i,int j)
{
    if(i==-1||j==-1)
    return;
    if(arr[i][j]==0)
    return;
    if(arr[i][j]==1&&visit[i][j]==0)
    {

        visit[i][j]=1;
        cout<<i<<j<<"\n";
        visited(i-1,j);
        visited(i-1,j+1);
        visited(i,j+1);
        visited(i+1,j+1);
        visited(i+1,j);
        visited(i+1,j-1);
        visited(i,j-1);
        visited(i-1,j-1);
    }

}
void f(int n)
{
    int i,j;
    int count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                if(!visit[i][j])
                {
                  count++;
                  visited(i,j);
                }
            }
        }
    }
    cout<<count<<"\n";
}
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            visit[i][j]=0;
        }
    }
    f(n);
}
