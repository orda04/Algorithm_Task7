#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#define SIZE 20

   // using namespace std;


void quickSort(int *numbers, int left, int right)
{
  int pivot; // resolving element
  int l_hold = left; //left border
  int r_hold = right; // right border
  pivot = numbers[left];
  while (left < right) // till left will  tocuh right
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // moving right border
    if (left != right) // if we still in process
    {
      numbers[left] = numbers[right]; // moving right element on resolving position element
      left++; // move right border into left
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // same as above but with left border
    if (left != right) // if we still in process
    {
      numbers[right] = numbers[left]; // moving right element on resolving position right element
      right--; // move left border into right
    }
  }
  numbers[left] = pivot; // resolving element in place
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // recursing function fo fixing other parts of massive
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

void originalSort(int *mass, int n)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (mass[i] % 2 == 0 && mass[j] % 2 == 0 && mass[i] > mass[j])
            {
                tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
               // swap(mass[i], mass[j]);
            }
        }
    }

}

int main() {
    int n;
    int* arr;
    printf("Enter an array size:\n");
    printf( "n = ");
    scanf("%d",&n);//cin >> n;
    arr = (int*)malloc(n * sizeof(int));//int* arr = new int[n];
     
    
    printf("Enter an array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    originalSort(arr,n);
    printf("Output of the program:\n");
    for (int i = 0; i < n; i++) {
    printf(" %d ",arr[i]);    
    }

    printf("\n**************************Second task************************ \n");

    int a[SIZE];
      // filling in massive with random numbers
      for (int i = 0; i<SIZE; i++)
        a[i] = rand() % 201 - 100;

      for (int i = 0; i<SIZE; i++)
        printf("%4d ", a[i]);
      printf("\n");
      quickSort(a, 0, SIZE-1); // sort
      // printing elements before sorting
      for (int i = 0; i<SIZE; i++)
      printf("%4d ", a[i]);
      printf("\n");
    //  getchar();

    return 0;
}
