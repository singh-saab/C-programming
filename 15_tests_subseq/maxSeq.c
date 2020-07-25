#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{ size_t x=1;
 size_t largest_length =0;
 size_t current_largest_length =0;
  for(int i=0;i<n;i++){
    if (array[i+1] == '\0'){
      break;
    }
    if (array[i] < array[i+1]){
      x++;
    current_largest_length=x;}
    else
      {
	if(current_largest_length >= largest_length)
	  {largest_length = current_largest_length;
	    x = 1;
	  }
      }
 
  }
     return largest_length ;
}
