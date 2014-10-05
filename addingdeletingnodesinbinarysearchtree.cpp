//input: enter nodes 
//output: dynamically creates binary search tree
//input: enter nodes to delete
//output: delete the node maintaining search property
#include <iostream>
#include<stdio.h>
using namespace std;

struct name
{
    char value;
    struct name *llink;
    struct name *rlink;
    struct name *parentlink;
};

void add(struct name **m,char v,struct name *parent)
{
    if((*m)==NULL)
        {
             (*m)=new struct name;
             (*m)->value=v;
             (*m)->llink=NULL;
             (*m)->rlink=NULL;
            (*m)->parentlink=parent;
        }
        else
        {
            if(v > ((*m)->value))
                add(&((*m)->rlink),v,(*m));
            else
                add(&((*m)->llink),v,(*m));
        }
}
int c=5;
void preorder(struct name *t)
{
    if(t==NULL){cout<<"NULL";return ;}
    else
    { cout<<(t->value)<<"***>(";
       preorder(t->llink);cout<<",";
       preorder(t->rlink);cout<<")";
    }
}
void del(struct name **m,struct name *delnode)
{
    if(delnode->llink==NULL && delnode->rlink==NULL)
        {
            if((delnode->parentlink==NULL)){*m=NULL;}
            else if((delnode->parentlink)->llink == delnode)
                {(delnode->parentlink)->llink=NULL;}
            else
                {(delnode->parentlink)->rlink=NULL;}
            delete delnode;
            return;
        }
    else  if(delnode->llink!=NULL && delnode->rlink==NULL)
        {
            if(delnode==*m){*m=delnode->llink;}

          else if((delnode->parentlink)->llink==delnode)
            {
               (delnode->parentlink)->llink =delnode->llink;

            }
            else
            {
               (delnode->parentlink)->rlink =delnode->llink;

            }
            delete delnode;
            return;
        }
    else if(delnode->rlink!=NULL && delnode->llink==NULL)
        {
            if(delnode==*m){*m=delnode->rlink;}
            else if((delnode->parentlink)->llink==delnode)
            {
               (delnode->parentlink)->llink =delnode->rlink;

            }
            else
            {
                (delnode->parentlink)->rlink =delnode->rlink;

            }
             delete delnode;
             return;
        }
        else
        {
           struct name *predecer=NULL;
           predecer=delnode->llink;
           while(predecer->rlink!=NULL)
               predecer=predecer->rlink;
           delnode->value=predecer->value;
           del(m,predecer);
        }
}
void findanddelete(struct name **root,char ch)
{
    struct name *cur=NULL;
    cur=*root;
    while(2){
    if(cur==NULL){cout<<"not available";return;}
    else
    {
        if(ch==cur->value)
            {

                del(root,cur);
                break;

            }
        if(ch > (cur->value))
        {
          cur=cur->rlink;
        }
        else
        {
          cur=cur->llink;
        }
    }
    }
}
int main()
{
struct name *root=NULL;
int c;
char ch;
while(1)
{
    cin>>c;
    switch(c){
    case 1://to add nodes
    cin>>ch;
    add(&root,ch,NULL);
    break;
    case 2://to display the tree
    preorder(root);
    break;
    case 3://find and delete entered node maintaing search property
    cin>>ch;
    findanddelete(&root,ch);
    }
}
}
