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
void searchtrrr(int tar)
{
      int count =1;
    //  int tpdata =rootn->data;
      struct node* nii=rootn;
      if(rootn->data==tar)
      {
        printf("present %d\n",count );
        return;

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
          return;
        }
        else{
            nii=nii->right;
        }
        count++;
      }
      printf("absent\n");
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
}
do{

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
}
  fclose(fp);


/*insertinbst(23);
insertinbst(4);
insertinbst(-5);
searchtrrr(8);
insertinbst(13);
insertinbst(13);
searchtrrr(13);*/

return 0;
}
