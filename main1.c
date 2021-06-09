#include <stdlib.h>
#include <stdio.h>



#define SZ 10  // for blocks arr


void bucketSort(int ar[],int x,int ar1[][10]);

int main() 
{
        //***********************************************
      // Sort by bucket
       int array[SZ]={5,8,19,120,97,3,351,23,77,950}; // what we have to sort
       int array1[SZ][SZ]={0}; // temp arr
       bucketSort(array,SZ,array1);
       // Sort by bucket
      //***********************************************




    return 0;
}

void bucketSort(int ar[],int x,int ar1[][10])
{
    // t - index where to move  from block back into original
   int t=0;
   // d -
   int d=1;
        // have to run 3 times, becasue maximum is 100 (xxx)  ||for future have to find out maximum and quantity of inmteration should depends from max
        // 1-ый for d=1,2- for d=10, 3 for d=100
        for(int z=0;z<3;z++)
        {
           t=0;  // temp counter
           for(int i=0;i<x;i++)
           {
        // copying elements from ar1 into ar2 where ar2 places calculatuin by formula (ar[1](ar[i]/d)%10[i]=arr[i])
             ar1[(ar[i]/d)%10][i]=ar[i];
           }
        // returne back our elements  with positions which we received after previous iteration
           for(int i=0;i<x;i++)
           {
              for(int j=0;j<x;j++)
                if(ar1[i][j]!=0)
                {
                   ar[t]=ar1[i][j];
                   t++;
                }
           }
        // printing arr for debug
        printf ( "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9 \n\n");

           for(int i=0;i<x;i++)
           {
              printf("%d\t",i);
              for(int j=0;j<x;j++)
                 printf("%d\t",ar1[i][j]) ;
              printf("\n");
           }
           printf("\n\n  array[10] = ");
           for(int i=0;i<x;i++)
               printf("%d,",ar[i]);
           printf("\n\n");
        // mass ar2 reseted into "0"
           for(int i=0;i<x;i++)
              for(int j=0;j<x;j++)
                 ar1[i][j]=0;
        // making next stage
           d*=10;
        }
}

