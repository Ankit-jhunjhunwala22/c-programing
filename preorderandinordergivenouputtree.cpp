//input:: preorder and inorder 
//output the resulting  tree
//not checking wrong inputs valid only for correct preorder and inorder
#include <iostream>
using namespace std;
struct tree
{
    char value;
  struct tree *leftlink;
  struct tree *rightlink;
  struct tree *parentlink;
};

void display(tree *q)
{
    if(q==NULL){cout<<"NULL";return;}
    else
    {
        cout<<" "<<q->value<<"-->(";
        display(q->leftlink);
        cout<<" , ";
        display(q->rightlink);
        cout<<") ";
    }
}

void treefind(string pre,string ino,int dir,struct tree **m)
{

struct tree *ne;
ne=new struct tree;
ne->value=pre[0];
ne->leftlink=NULL;
ne->rightlink=NULL;
if((*m)==NULL)
{
  (*m)=ne;
}
else if(dir==0){
    ne->parentlink=(*m);
    (*m)->leftlink=ne;
    }
else if(dir==1){
    ne->parentlink=(*m);
    (*m)->rightlink=ne;
                }
    if(pre.length()==1)return;
    int split,len;
    split=ino.find(pre[0]);
    treefind(pre.substr(1,split),ino.substr(0,split),0,&ne);
    treefind(pre.substr(split+1),ino.substr(split+1),1,&ne);
}
int main()
{
    struct tree *mytree=NULL;
    string pre("abcdfge");//preorder
    string ino("cbfdgae");//inorder
    treefind(pre,ino,0,&mytree);
    display(mytree);
}
