/*program for reading ang writing 1/0 to each byte given memory location and length*/
#include<stdio.h>
void func(unsigned char *p,int size_in_bytes,int write_one)
{

int i=0;
while(i!=size_in_bytes)
{
*(p+i)=*(p+i)&0;
if(write_one==1)
*(p+i)=~*(p+i);
i++;
}
}

void read(unsigned char *p,int size_in_bytes)
{
int i,o;
i=o=0;
while(i!=size_in_bytes)
{
printf("\nreading %d byte:%d\n",++o,*(p+i));//giving 255 which is decimal equivalent of 11111111 or giving 0 which is decimal equivalent of 00000000
i++;
}
}
int main()
{

 int q;//taking integer having four byte
 float f;//taking float having four byte
func((unsigned char *)&q,4,1);//writing 1 to each of the four byte
read((unsigned char *)&q,4);//reading from each byte
func((unsigned char *)&q,4,0);//writing 0 to each of the four byte
read((unsigned char *)&q,4);//reading from each byte

func((unsigned char *)&f,4,1);//writing 1 to each of the four byte
read((unsigned char *)&f,4);//reading from each byte
func((unsigned char *)&f,4,0);//writing 0 to each of the four byte
read((unsigned char *)&f,4);//reading from each byte

}

