#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int calc_frequency(FILE*f, int frequency[])
{
  int c;
  while((c=fgetc(f))!= EOF)
    {
      if( isalpha(c))
	{ c=tolower(c);
	  c-='a';
	  frequency[c]++;}
    }
}

int calc_key(int frequency[])
{
  int i , max = 0 ,key=0;
  for ( i=0;i<26;i++ )
    {
      if (frequency[i] > max )
	{ max =i; }
    }

      if(max>= 4)
	{key = max - 4;
	 
	}
      if (max<4)
	{key = 4 - max;
	}
      return key;
}
  
int main(int argc, char** argv ){
  if(argc!=2)
    {
      fprintf(stderr,"wrong number of arguments");
      return  EXIT_FAILURE;
    }
  FILE*f =fopen(argv[1],"r");
  if( f== NULL )
    {
      perror("file is not valid \n");
     return EXIT_FAILURE;
    }
  int frequency[26] = {0};
  calc_frequency(f,frequency);

  int key = calc_key(frequency);

  printf("%d \n",key);

  if(fclose(f)!=0)
    {perror("failed to close the file \n");
      return EXIT_FAILURE;
    }
}
