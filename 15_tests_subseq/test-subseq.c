#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(){
  int a[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  int b[] = {1 ,1,1,1,1,1,1,1,1,1};
  int c[]={0};
  int d[]={1,2,-1,18,-3};
  int e[]={4,5,-5,-4 };
  int f[]={0,1,3,38 ,4};
  int g[]={25,26,27,15};
  int h[]={12,7,25};
  if (maxSeq(a,10)!=4){ return EXIT_FAILURE;}
  if (maxSeq(b,10)!=1) { return EXIT_FAILURE;}
  if (maxSeq(c,1)!=1) {return EXIT_FAILURE; }
  if (maxSeq(d,5)!=2) {return EXIT_FAILURE;}
 if (maxSeq(e,4)!=2) {return EXIT_FAILURE;}
 if (maxSeq(f,5)!=4) {return EXIT_FAILURE;}
 if (maxSeq(g,4)!=3) {return EXIT_FAILURE;}
 if (maxSeq(f,3)!=3) {return EXIT_FAILURE;}

  return EXIT_SUCCESS;
}
