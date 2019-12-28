/**
  *	author:        Gastón Rial Saibene
  *	description:   This is an example implementation of merge sort for testing the NIM lang
  *	               and compiler against an equivalent C implementation compiled with gcc (GNU C compiler).
  *	date:          27/12/2019
  *
*/
#include <stdio.h>
#include <stdlib.h>

// Function that merges two lists into one and returns the resulting list
int merge(const int l1[],const int l2[],const int s1, const int s2,int* r[])
{

  int index = 0, index1 = 0, index2 = 0;
  int len = s1 + s2;
  *r = (int*) calloc(len,sizeof(int));
  for( ; index1+index2 < len ; index ++ )
  {
    
    if( index1 < s1 && index2 < s2 )
    {
      if( l1[index1] > l2[index2] )
      {
        r[0][index] = l2[index2];
        index2++;
      }
      else
      { 
        r[0][index] = l1[index1];
        index1++;
      }
    }
    else if ( index1 < s1 )
    {
      r[0][index] = l1[index1];
      index1++;
    }
    else
    {
      r[0][index] = l2[index2];
      index2++;
    }
      
  }
  return len;
}

// Merge sort function implementation
int mergeSort(int l[], int s, int* r[])
{
 
  if( s < 2 )
  {
    *r = l;
    return s;
  }
  else
  {
    int ri_len = (s/2), le_len = (s - s/2);
    int* ri_half = malloc(sizeof(int)*ri_len);
    int* le_half = malloc(sizeof(int)*le_len);

    int index = 0;
    for(int i = 0; i < ri_len; i++)
    {  
      ri_half[i] = l[index];
      index++;
    }

    for(int j = 0; j < le_len; j++)
    {  
      le_half[j] = l[index];
      index++;
    }

    int* ri_sorted;
    int* le_sorted;
    if( mergeSort(ri_half,ri_len,&ri_sorted) != ri_len )
	perror("somerhing went wrong!");
    if( mergeSort(le_half,le_len,&le_sorted) != le_len )
        perror("something went wrong!");

    merge(ri_sorted,le_sorted,ri_len,le_len,r);

    free(ri_half);
    free(le_half);
    return s;
  } 

}

void printList(const int l[], int s)
{

  printf("[");
  for ( int i = 0; i < s; i++)
    printf("%i ",l[i]);
  printf("]\n");

}

// Read file to memory
int readList(char* path, int* a[])
{

  FILE* fp = fopen(path,"r");
  if(!fp)
  {
    perror("Error opening the file");
    exit(-1);
  }
  *a = (int*)malloc(sizeof(int));
  char digit;
  char number[100001];
  int counter = 0;
  int size = 0;
  while((digit = fgetc(fp)) != EOF)
  {

    if(digit != ',')
    {
      number[counter] = digit;
      counter++;
    } else {
      number[counter] = '\0';
      a[0][size] = atoi(number);
      counter = 0;
      size++;
      *a = (int*)realloc(*a,sizeof(int)*(size+1));
    }
   
  }

  number[counter] = '\0';
  a[0][size] = atoi(number);

  if(fclose(fp) != 0)
  {
    perror("Error closing the file");
    exit(-1);
  }
  
  return size+1;
}

int main(int argc, char** argv)
{

  // Testing with big array
  int* a;
  int* r;
  int size_unsorted = readList("./random_list.txt", &a);
  int size = mergeSort(a, size_unsorted, &r);
  printList(r,size);
  free(a);
  free(r);
  exit(0);

}
