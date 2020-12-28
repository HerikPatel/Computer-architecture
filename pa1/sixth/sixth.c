#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
int no;
int count =0;
int count2=0;
char ch;
  for(int i=1;i<argc;i++)
  {
    no=strlen(argv[i]);
    ch=argv[i][0];
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
    {int j=0;
      while(j!=no)
      {
        printf("%c",argv[i][j]);
        j++;
      }
      printf("yay");
      printf(" ");
    }
    else{
      while(count!=-1)
      {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
        for(int a=count;a<no;a++)
        {
          printf("%c",argv[i][a]);
        }
        for(int b=0;b<count;b++)
        {
          printf("%c",argv[i][b]);
        }
        count =-1;
        count2=-1;
        continue;
        }
        count++;

        ch=argv[i][count];
      }
      if(count2==-1)
      {
        printf("ay");
        printf(" ");
        count2=0;
        count=0;
      }

    }

  }
  return 0;
}
