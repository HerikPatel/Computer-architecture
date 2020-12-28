#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
int i,len;
for(i=1;i<argc;i++)
{

  len =strlen(argv[i]);
 printf("%c",argv[i][len-1] );

}
return 0;

}
