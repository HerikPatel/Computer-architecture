#include<stdio.h>
#include<stdlib.h>
void checkrtb(int no);


int main(int argc ,char** argv)
{
int num,temp;
  FILE* fp =fopen(argv[1],"r");
  /*  if(fp==NULL)
  {
    printf("doesnt exist" );
    exit(0);
  }
  int num=0;
  if(fscanf(fp, "%c\t%d \n",&ch,&num)==EOF)
  {
    printf("empty file\n");
    exit(0);
  }*/
  fscanf(fp,"%d",&num);
if(num>0)
{
  while(fscanf(fp,"%d",&temp)!=EOF)
      {
      checkrtb(temp);
       }
    fclose(fp);
  }
  else
  {
    exit(0);
  }


	return 0;

}
void checkrtb(int no)
{
  int rem;
while(no!=0)
{
  rem=no%10;
  if(rem%2!=0)
  {
    no=no/10;
  }
  else{
    printf("no\n");
    return;
      }
}
printf("yes\n");
}
