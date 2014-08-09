/*
input :given a string 
output:consider string 'aabaab' for this string output should be 11 
      logic
      aabaab is similar to itself aabaab (in similarity here we find total no of characters same to 
      the original string from initial character of original string) so here aabaab is silmilar to itself by 8
      next remove one element of aabaab that is abaab and find the similarity here is 1 since only intial character
      is same to original string aabaab ,so we stop similarly we find all the suffices ,find similarity for each
      and sum it and return it as our output*/


#include<iostream>
#include<cstdio>
using namespace std;
class key
{
    public:
    char s[100000];
    int sim(char *a,char *b)
    {
        int c=0;
        while(*b)
        {
            if(*a==*b)
           {
            c++;
            a++;
            b++;
           }
           else break;
        }
        return c;
    }
    int func()
    {


        int sum=0,i=0;
        while(s[i])
        {
            sum=sum+sim(s,s+i);
            i++;
        }
        return sum;
    }
};
int main()
{
    int i;
    key p[10];
    gets(p[0].s);
    cout<<p[0].func();
    return 0;
}
