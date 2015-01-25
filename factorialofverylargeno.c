#include<stdio.h>
int main()
{
    char a[200];
    int carry;
    int noofdigits;
    int number,i,j;
    int x;
    scanf("%d",&number);
    a[0]='1';
    noofdigits=1;
    carry=0;
    for(i=1;i<=number;i++)
    {
        for(j=0;j<noofdigits;j++)
        {
           x=i*(a[j]-48)+carry;//as ascii of 0 is 48 
           a[j]=x%10 + 48;//adding the offset
           carry=x/10;
        }
        while(carry>0)
        {
            a[j]=carry%10 + 48;
            carry=carry/10;
            noofdigits++;
            j=noofdigits;
        }
    }

   for(j=(noofdigits-1);j>=0;j--)
    printf("%c",a[j]);
}
