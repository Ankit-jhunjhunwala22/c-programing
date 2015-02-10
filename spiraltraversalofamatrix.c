#include<stdio.h>
int a[5][5];
int visited[5][5]={0};

void spiral(int curx,int cury,int dir)
{
    if(visited[curx][cury]==1)return;
    if(dir==0)
        {
        //increment y
        visited[curx][cury]=1;
        printf("%d ",a[curx][cury]);

                if( (cury+1 < 5) && (visited[curx][cury+1]!=1) )

                {
                spiral(curx,cury+1,dir);
                }
                else
                {
                     spiral(curx+1,cury,1);
                }

        }
    else if(dir==1)
        {
        //increment x
        visited[curx][cury]=1;
        printf("%d ",a[curx][cury]);
        if((curx+1 <5 )&& (visited[curx +1 ][cury]!=1) )
        spiral(curx+1,cury,dir);
        else
         spiral(curx,cury-1,2);
        }
    else if(dir==2)
        {
        //decrement y
        visited[curx][cury]=1;
        printf("%d ",a[curx][cury]);
        if((cury-1 >= 0)&&(visited[curx][cury-1]!=1))
        spiral(curx,cury-1,dir);
        else
        spiral(curx-1,cury,3);
        }
    else if(dir==3)
        {
        //decrement x
        visited[curx][cury]=1;
        printf("%d ",a[curx][cury]);
        if( (curx-1 >=0) && (visited[curx-1][cury]!=1) )
        spiral(curx-1,cury,dir);
        else
        spiral(curx,cury+1,0);
        }
}
int main()
{
int i=0,j;
for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {
        scanf("%d",&a[i][j]);
        visited[i][j]=0;
    }
}
spiral(0,0,0);
}
