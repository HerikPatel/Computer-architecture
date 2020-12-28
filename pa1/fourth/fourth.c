#include<stdio.h>
#include<stdlib.h>
int ansr;
int ansc;
int** allocate_matrix(int rows, int cols){
  int** ret_val = malloc(rows * sizeof(int*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(int));
  }
  return ret_val;
}

int** ans_matrix(int rows, int cols){
  int** ret_val2 = malloc(rows * sizeof(int*));
  for(int i = 0; i< rows; i++){
    ret_val2[i] = malloc(cols * sizeof(int));
  }
  return ret_val2;
}


/*void initialize_matrix(int** matrix, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      matrix[i][j] = rand();
    }
  }
}
void initialize_matrix2(int** matrix2, int rows, int cols){
  for(int x = 0; x < rows; x++){
    for(int y = 0; y < cols; y++){
      matrix2[x][y] = rand();
    }
  }
}*/
/*
int** add_matrix(int** matrix2 ,int** matrix, int rows, int cols){
  ansr=1;
  ansc=1;
  int sum = 0;
  int i=0;int tp=0;
  for(int x=0; x< rows; x++){
    for(int j=0; j < cols; j++){
      while(i!=cols)
      {
        ans=matrix[x][i]*matrix2[j][i]+ans;
      }
      while(tp<ansr)
      {
        while(tp2<ansc)
        {
        ans_matrix[ansr][ansc]=ans;
         ansc++;
       }
       ansr++;
      }
      i=0;
    }
  }

  return ans_matrix;
}*/

int main(int argc, char** argv){
int** matrixx;
int** matrixx2;
int r,c,val,r2,c2;
int te1=0;int te2=0;
int count=1;
int ct=0;
FILE* fp =fopen(argv[1],"r");

while(fscanf(fp,"%d\t%d",&r,&c)!=EOF)
    {
      if(count==1)
      { te1=r;
        te2=c;
        r2=c;
        while(ct!=r)
       {

      matrixx=allocate_matrix(r,c);
      for(int i=0;i<r;i++)
      {
        for(int j=0;j<c;j++)
      {
      fscanf(fp,"%d\t",&val);
        matrixx[i][j]=val;

      }
      ct++;
      }

      count ++;
    }
      ct=0;

    }


else{
  while(ct!=r)
 {

matrixx2=allocate_matrix(r,c);
for(int i=0;i<r;i++)
{
  for(int j=0;j<c;j++)
{
  fscanf(fp,"%d\t",&val);
  matrixx2[i][j]=val;
}
ct++;
}
count ++;
}
    }

    c2=r;
    }
    fclose(fp);
    printf("%d",r2+c2);
    printf("%d",te2+te1);
    printf("\n");
    printf("\n");
    printf("\n");
    for (  int g=0;g<te1;g++) {
      for(int h=0;h<te2;h++)
      {
        printf("%d\t",matrixx[g][h]);
      }
      printf("\n");
    }

printf("\n");printf("\n");printf("\n");
    for (  int g=0;g<r;g++) {
      for(int h=0;h<c;h++)
      {
        printf("%d\t",matrixx2[g][h]);
      }
      printf("\n");
    }
    return 0;

}



  /*
  }*/
  /*int add_matrix(int** anmatrix,int** matrix2 ,int** matrix, int row1, int col2,int ansr,int ansc){
  int sum=0;

  for (int i = 0; i < col2; i++) {
          for(int j=0;j<row1;j++)
          {
            sum=sum+(matrix[i][j]*matrix2[j][i]);
          }
  }

    return ans_matrix;
  }*/
