/*
 * Solution to problem 11 in Project Euler
 * copyright (c) 2017, Zeyuan Hu, ferrishu3886@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * We read in the input txt file, and generate the matrix from it.
 */
void generate_matrix(int**, FILE*);
void print_matrix(int*, int, int);

/* 
 * Calculate the greatest product of four adjacent numbers 
 * in the same direction (up, down, left, right, or diagonally) 
 * in the 20×20 grid.
 */
int get_maximum(int*);

int
main()
{
  FILE *fp;
  char* filename = "euler11_input.txt";
  fp = fopen(filename, "r");
  int numRows = 20, numCols = 20;
  int* arr = calloc(numRows * numCols, sizeof(int));
  generate_matrix(&arr, fp);
  print_matrix(arr, numRows, numCols);
  printf("\n");
  printf("The answer: %d\n", get_maximum(arr));
  free(arr);
  return 0;
}

int
get_maximum(int* matrix)
{
  int numRows = 20;
  int numCols = 20;
  int max = 0;
  int tmp = 0; // hold the temporary calculation result
  int i,j;
  for(i=0; i < numRows; i++)
  {
    for(j=0; j < numCols; j++)
    {
      if (i-3 >= 0) // top direction
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i-1)*numCols + j)) * (*(matrix + (i-2)*numCols + j)) * (*(matrix + (i-3)*numCols + j));
        if (tmp > max)
          max = tmp;
      }
      if (i+3 < numRows) // down direction
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i+1)*numCols + j)) * (*(matrix + (i+2)*numCols + j)) * (*(matrix + (i+3)*numCols + j));
        if (tmp > max)
          max = tmp;
      }
      if (j-3 >= 0) // left direction
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + i*numCols + j-1)) * (*(matrix + i*numCols + j-2)) * (*(matrix + i*numCols + j-3));
        if (tmp > max)
          max = tmp;
      }
      if (j+3 < numCols) // right direction
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + i*numCols + j+1)) * (*(matrix + i*numCols + j+2)) * (*(matrix + i*numCols + j+3));
        if (tmp > max)
          max = tmp;
      }
      if (j+3 < numCols && i-3 >= 0) // North-east diagonal
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i-1)*numCols + j+1)) * (*(matrix + (i-2)*numCols + j+2)) * (*(matrix + (i-3)*numCols + j+3));
        if (tmp > max)
          max = tmp;        
      }
      if (j-3 >= 0 && i-3 >= 0) // North-west diagonal
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i-1)*numCols + j-1)) * (*(matrix + (i-2)*numCols + j-2)) * (*(matrix + (i-3)*numCols + j-3));
        if (tmp > max)
          max = tmp;        
      }
      if (j-3 >= 0 && i+3 < numRows) // South-west diagonal
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i+1)*numCols + j-1)) * (*(matrix + (i+2)*numCols + j-2)) * (*(matrix + (i+3)*numCols + j-3));
        if (tmp > max)
          max = tmp;        
      }
      if (j+3 < numCols && i+3 < numRows) // South-east diagonal
      {
        tmp = (*(matrix + i*numCols + j)) * (*(matrix + (i+1)*numCols + j+1)) * (*(matrix + (i+2)*numCols + j+2)) * (*(matrix + (i+3)*numCols + j+3));
        if (tmp > max)
          max = tmp;        
      }            
    }
  }
  return max;
}

void
generate_matrix(int** matrix, FILE *fp)
{
  int c, i = 0;
  int row = 0, col = 0;
  int numCols = 20;
  int* buffer = malloc(2*sizeof(int));
  
  while((c = getc(fp)) != EOF)
  {
    if(c != 10 && c != 32) // '\n' has dec val 10, and ' ' has 32 in ASCII
    {
      buffer[i] = c-'0';
      i++;
    }
    if (c == 10)
    {
      row+=numCols;
      col = 0;
    }
    if(i == 2)
    {
      i = 0;
      *(*matrix+row+col) = buffer[0]*10 + buffer[1];
      col++;
    }
  }
  free(buffer);
}

void
print_matrix(int* matrix, int numRows, int numCols)
{
  int i, j;
  for(i=0; i < numRows; i++)
  {
    for(j=0; j < numCols; j++)
    {
      printf("%d,", *(matrix+i*numCols+j));
    }
    printf("\n");
  }
}

