#include<stdio.h>
#include<stdlib.h>
struct  node *arr[1000];
struct node{
  int data;
  struct node *next;
};
int createht(int val){
  struct node *temp;
  struct node *prev;
  int dup;
  if(val<0)//line12
  {
    dup=val;
    val=-1*val;
  int key=val%1000;
    struct  node *ll =  malloc(sizeof(struct node));
    ll->data=dup;
    ll->next=NULL;
  if(arr[key]==NULL)
  {
        arr[key]=ll;
        printf("inserted\n" );
        return 0;
  }
  else if(arr[key]!=NULL)
  {
    temp=arr[key];
        while(temp->next!=NULL)
        {
          prev=temp;
      if(temp->data==val)
      {
        printf("duplicate\n");
        return 1;
      }
      temp=temp->next;
        }
        temp->next=ll;
        printf("inserted\n" );
        return 0;
  }
  }
else{
  int key=val%1000;
    struct  node *ll =  malloc(sizeof(struct node));
    ll->data=val;
    ll->next=NULL;
  if(arr[key]==NULL)
  {
        arr[key]=ll;
        printf("inserted\n");
  }
  else if(arr[key]!=NULL)
  {
    temp=arr[key];
        while(temp!=NULL)
        {
          prev=temp;

        if(temp->data==val)
        {
          printf("duplicate\n");
          return 1;
        }
        temp=temp->next;
      }
        prev->next=ll;
        printf("inserted\n");
  }
}

return 1;

}

int searchht(int val1)
{
  struct node *temp;
  int dup;
  int key;
  if(val1<0)
  {
    dup=val1;
    dup=-1*dup;
    key=dup%1000;
  }
  else {
    key=val1%1000;
  }

  temp=arr[key];
  while(temp->data!=val1)
  {
    if(temp->next==NULL)
    {
      printf("absent\n");
      return 1;
    }
    temp=temp->next;
  }
  printf("present\n");
return 1;
}

int main(int argc ,char** argv)
{

  int temp=0;
  char ch=' ';
FILE* fp =fopen(argv[1],"r");
if(fp==NULL)
{
  printf("error" );
  exit(0);
}
/*
int num=0;
if(fscanf(fp, "%c\t%d \n",&ch,&num)==EOF)
{
  printf("empty file\n");
  exit(0);
}*/

while(fscanf(fp,"%c\t%d\n",&ch,&temp)!=EOF)
    {

    if(ch=='i')
    {
      createht(temp);
    }
    if(ch=='s')
    {
      searchht(temp);
    }
}
  fclose(fp);


return 0;
}
