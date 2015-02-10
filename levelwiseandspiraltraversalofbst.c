#include <stdio.h>
#include <stdlib.h>

struct node *tr=NULL;

struct node {
int data;
struct node *llink;
struct node *rlink;
};

int findheight(struct node *r)
{
    int lh=0;
    int rh=0;
if(r==NULL)
 return 0;
else
{   lh = findheight(r->llink);
    rh= findheight(r->rlink);
    if(lh>rh)

        return lh+1;
        else
        return rh+1;



}
}

void print_level(struct node *r,int level,int direction)
{
if(r==NULL)
    return;
if(level==1)
    printf("%d ",r->data);
else if(level>1)
{
    if(direction==0)
    {
        print_level(r->rlink,level-1,direction);
        print_level(r->llink,level-1,direction);
    }
    else
    {
        print_level(r->llink,level-1,direction);
        print_level(r->rlink,level-1,direction);

    }

}
}

void print_levelwise(struct node *r)
{
int h=findheight(r);
int i;
for(i=1;i<=h;i++)
{
    print_level(r,i,1);
}
}
void  print_spiral(struct node *r)
{
  int height,i,dir;
  height=findheight(r);
  dir=0;
  for(i=1;i<=height;i++)
  {
      print_level(r,i,dir);
      if(dir==0)
        dir=1;
      else if(dir==1)
        dir=0;
  }
}
void add(struct node **r,int d)
{

    struct node *cur=NULL;
    if(*(r)==NULL)
    {
    cur=(struct node *)malloc(sizeof(struct node));
    cur->data=d;
    cur->llink=NULL;
    cur->rlink=NULL;
        *(r)=cur;
    }
    else
    {
      if((*r)->data > d )
        add(&((*r)->llink),d);
      else
       add(&((*r)->rlink),d);
    }
}
void display(struct node *root)
{
    if(root==NULL)return;
    else
    {
        printf("%d ",root->data);
        display(root->llink);
        display(root->rlink);
    }
}
int main()
{
struct node *root=NULL;
add(&root,4);
add(&root,15);
add(&root,20);
add(&root,2);
add(&root,3);
print_spiral(root);
printf("\n");
print_levelwise(root);
}

