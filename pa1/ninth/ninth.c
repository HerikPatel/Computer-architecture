
#include<stdio.h>
#include<stdlib.h>
struct node*ni,*left,*right;

struct node {
  int data;
  struct node *left,*right;
};
struct node * rootn = NULL;

void insertinbst(int dt){
  int t;
  int height=1;
  struct  node *ni =  malloc(sizeof(struct node));
  ni->data = dt;
  ni->left = NULL;
  ni->right = NULL;
height=1;
  if (rootn==NULL){
    rootn = ni;
   printf("inserted %d\n",height);
    return;
  }
  if(rootn->data==dt)
  {
    printf("duplicate\n" );
    return;
  }

  if(rootn->left== NULL && dt < rootn->data){
    rootn->left = ni;
    height++;
   printf("inserted %d\n",height);
    return;
  }

  if(rootn->right== NULL && dt>rootn->data){
    rootn->right = ni;
    height++;
    printf("inserted %d\n",height);
    return;
  }
  height++;

  struct node* temp =rootn;
  struct node* prev = rootn;
  while(temp!=NULL)
  {
      if (temp->data > dt) {
        prev=temp;
        temp=temp->left;
        t=0;
      }
      else if(temp->data==dt)
      {
        prev=temp;
        temp=temp->right;
        printf("duplicate\n");
        return;
      }
      else if(temp->data<dt)
      {
        prev=temp;
        temp=temp->right;
        t=1;
      }

      height++;
  }
      if(t==0)
      {
        prev->left=ni;

       printf("inserted %d\n",height-1);
      }
      if(t==1)
      {
        prev->right=ni;

        printf("inserted %d\n",height-1);
      }
      height=1;
}
int searchtrrr(int tar)
{
      int count =1;
      struct node* nii=rootn;
      if(rootn->data==tar)
      {
        printf("present %d\n",count );
        return 1;

      }
      while(nii!=NULL)
      {
        if(nii->data>tar)
        {
          nii=nii->left;
        }
        else if(nii->data==tar)
        {
          printf("present %d\n",count );
          return 1;
        }
        else{
            nii=nii->right;
        }
        count++;
      }
      printf("absent\n");
      return 0;
      }
  int searchtrrr2(int tar)
  {
    int count =1;
    struct node* nii=rootn;
    if(rootn->data==tar)
    {
    //  printf("present %d\n",count );
      return 1;

    }
    while(nii!=NULL)
    {
      if(nii->data>tar)
      {
        nii=nii->left;
      }
      else if(nii->data==tar)
      {
      //  printf("present %d\n",count );
        return 1;
      }
      else{
          nii=nii->right;
      }
      count++;
    }
    //printf("absent\n");
    return 0;
    }

void deletionbst(int tar) {
int tt;
int che=searchtrrr2(tar);
if(che==0)
{
  printf("fail\n");
  return;
}
  struct node* temp =rootn;
  struct node* prev2;
  struct node* prev = rootn;
  int checkdt=0;
   if(temp->data==tar)
  {
    if(rootn->left!=NULL)
    {
      if(rootn->right!=NULL)
      {
        if(temp->right->left==NULL)
        {
          temp->data=checkdt;

          if(temp->right->right!=NULL)
          {
            temp->right=temp->right->right;
            rootn=temp;
            printf("success\n" );
            return;
          }
          temp->right=NULL;
        }
        while(prev2->left!=NULL)
        {
          prev=prev2;
          prev2=prev2->left;
        }
        checkdt=prev2->data;
        temp->data=checkdt;
        prev->left=NULL;
        rootn=temp;
        printf("success\n" );
        return;
      }
      temp=temp->right;
      rootn=temp;
      printf("success\n" );
      return;
    }
  /*  else if(temp->right!=NULL)
    {
      prev=temp;
      temp=temp->right;
      while(temp->left!=NULL)
      {
        prev=temp;
        temp=temp->left;
      }
      if(prev->left!=NULL)
      {
        rootn->data=temp->data;
        prev->left=NULL;
        return;
      }
      rootn->data=temp->data;
      rootn->right=temp;
      printf("success\n" );
      return;
    }*/
  }
  while(temp->data!=tar)
  {
      if (temp->data > tar) {
        prev=temp;
        temp=temp->left;
        tt=0;
      }
      else if(temp->data<tar)
      {
        prev=temp;
        temp=temp->right;
        tt=1;
      }

    }
      //case -1 leaf node
        if(temp->left==NULL && temp->right==NULL)
        {
          if(tt==0)
          {
            prev->left=NULL;
            printf("success\n");
            return;

          }
          if(tt==1)
          {
              prev->right=NULL;
              printf("success\n");
              return;
          }
        }
    //  case -2
        if(temp->right==NULL)
        {
          if(tt==0)
          {
            prev->left=temp->left;
            printf("success\n");
            return;

          }
          if(tt==1)
          {
              prev->right=temp->left;
              printf("success\n");
              return;
          }
        }

       else if(temp->left==NULL)
        {
          if(tt==0)
          {
            prev->left=temp->right;
            printf("success\n");
            return;
          }
          if(tt==1)
          {
              prev->right=temp->right;
            printf("success\n");
            return;
          }
        }
        else{
          temp->right->data=checkdt;
          prev2=temp;
          prev2=prev2->right;
          prev=temp;
          if(temp->right->left==NULL)
          {
            temp->data=checkdt;
            if(temp->right->right!=NULL)
            {
              temp->right=temp->right->right;
              printf("success\n" );
              return;
            }
            temp->right=NULL;
          }
          while(prev2->left!=NULL)
          {
            prev=prev2;
            prev2=prev2->left;
          }
          checkdt=prev2->data;
          temp->data=checkdt;
          prev->left=NULL;
          printf("success\n" );
          return;
          {

          }
        }

      //case-3


        free(temp);

  }
int main(int argc ,char** argv)
{
 int temp=0;
  char ch=' ';
FILE* fp =fopen(argv[1],"r");
/* if(fp==NULL)
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

while(fscanf(fp,"%c\t%d\n",&ch,&temp)!=EOF)
    {

    if(ch=='i')
    {
      insertinbst(temp);
    }
    if(ch=='s')
    {
      searchtrrr(temp);
    }
    if(ch=='d')
    {
      deletionbst(temp);
    }
}
  fclose(fp);


/*
insertinbst(23);
insertinbst(4);
insertinbst(-5);
insertinbst(5);
insertinbst(6);
insertinbst(7);
deletionbst(4);
searchtrrr(4);
searchtrrr(6);*/


return 0;
}
