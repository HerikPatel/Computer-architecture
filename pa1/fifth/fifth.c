#include<stdio.h>
#include<stdlib.h>

/*int add_matrix(int** matrix, int s){

  int sum,count  = 0;
  int sum2=0;
  int sum3=0;
  for(int i=0; i< s; i++){
    for(int j=0; j < s; j++){
      sum = sum + matrix[i][j];
      sum3=sum2;
      sum2=sum;
      count++;
      if(count>1&&sum2!=sum3)
      {
        printf("not magic");
        return 0;
      }
    }
    printf("magic");
   //sum=0;

  return 1;
  }
}*/

int main(int argc, char** argv){
//int sum=0;
int size,val;
int** matrix
FILE* fp =fopen(argv[1],"r");
fscanf(fp,"%d]\n",&size);
  while(fscanf(fp,"%d\t",&val)!=EOF)
      {

        matrix = malloc(size * sizeof(int*));
        for(int i = 0; i< size; i++){
        matrix[i] = malloc(size * sizeof(int));

              for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                  matrix[i][j] = val;
                }
              }
  }
}
int sum,count  = 0;
int sum2=0;
int sum3=0;
for(int i=0; i< size; i++){
  for(int j=0; j < size; j++){
    sum = sum + matrix[i][j];
    sum3=sum2;
    sum2=sum;
    count++;
    if(count>1&&sum2!=sum3)
    {
      printf("not magic");
      exit(0);
    }
  }
  printf("magic");
 //sum=0;
exit(0);
}
fclose(fp);

  return 0;

}
