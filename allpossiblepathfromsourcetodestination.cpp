//finding all path from source to destination using depth first search
//using distance matrix
//using 999 constant if there is no path from one node to another even if it is the
//same node
#include <iostream>
using namespace std;
 int destination;
 int index=1;
void possiblepathbydepthfirstsearch(int x,int y,int n,int visited[50][50],int dmatrix[50][50],int path[])
{
if(visited[x][y]==0 &&  dmatrix[x][y]!=999)
 {
 visited[x][y]=1;
 }
 else
 return ;

 path[index++]=dmatrix[x][y];
 if(dmatrix[x][y]==destination)
    {
            for(int i=0;i<index;i++)
                cout<<path[i]<<" ";
            cout<<"\n";
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                visited[i][j]=0;
                index=1;
    }
 else
    {

            for(int i=0;i<n;i++)
            {
             possiblepathbydepthfirstsearch(dmatrix[x][y],i,n,visited,dmatrix,path);
            }
    }



}
int main()
{
   int n;
   cin>>n;
   int  dmatrix[50][50];
   int visited[50][50];
   int  path[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dmatrix[i][j];
            visited[i][j]=0;
        }
    }
    int source;
    cin>>source;
    path[0]=source;
    cin>>destination;
    for(int i=0;i<n;i++)
    possiblepathbydepthfirstsearch(source,i,n,visited,dmatrix,path);
    return 0;
}
