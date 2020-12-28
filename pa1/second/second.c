#include<stdio.h>
#include<stdlib.h>
void arrangellist();
struct node *first=NULL;
void printll();
 struct node
 {
   int data;
   struct node *next;
 };

 void createll(int val)
 {
   struct node *temp;
   struct  node *ni =  malloc(sizeof(struct node));
   ni->data=val;
   temp=first;
   if(first==NULL)
   {
                first=ni;
                first->next=NULL;

   }
   else if(first->data==val)
   {
     return;
   }
   else
    {
          if(val<first->data)
          {
            temp=ni;
            temp->next=first;
            first=temp;
              // printf("%d",first->data);
              arrangellist();
            return ;
          }
          temp=first;
        while(temp->next!=NULL)
        {
          if(temp->next->data==val)
          {
            return;
          }
          else if(temp->data==val){
            return;
          }
          temp=temp->next;
        }
        temp->next=ni;
    }
  arrangellist();
}
void arrangellist()
{
  int dup;
            struct node *ni=first;
            struct node *temp;
          while(ni->next!=NULL)
          {
            temp=first;
          while(temp->next!=NULL)
                {
                  if(temp->data > temp->next->data)
                    {

                      dup=temp->data;
                      temp->data=temp->next->data;
                      temp->next->data=dup;

                    }
                    temp=temp->next;
                }
                ni=ni->next;
            }

}


void printll()
{

int count=0;
struct node *temp=first;
if(temp==NULL)
{
  printf("%d\n",count );
}

else{count++;
  while(temp->next!=NULL)
  {count++;
  temp=temp->next;
}
printf("%d\n",count);
}
temp=first;
if(temp==NULL)
{
  printf("\n");
}
else{
  while(temp!=NULL)
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
}
return;
}

void deleteval(int trr)
{

        if(first==NULL)
        {
          return;
        }

        struct node *temp=first;
        if(temp->data==trr)
        {
         temp=temp->next;
         first=temp;
          return;
        }
        else{
        while(temp->next!=NULL )
       {  if(temp->next->data ==trr)
             {
               temp->next=temp->next->next;
               return;
            }
            temp=temp->next;
          }
          return;
        }

}

int main(int argc ,char** argv)
{
int temp=0;
  char ch=' ';
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

while(fscanf(fp,"%c\t%d",&ch,&temp)!=EOF)
    {
    if(ch=='i')
    {
      createll(temp);
    }
    if(ch=='d')
    {

     deleteval(temp);
    }
}
  fclose(fp);


printll();
//printf("%d\n",first->data );

return 0;
}
