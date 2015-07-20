#include "insertion_sort.h"

void print_array (int array[], int count)
{
    int i = 0;

    for (i = 0; i < count; i++)
    {
	printf ("%d\t ", array[i]);
    }
    printf("\n");
}

int main()
{
    int a[]= {3, 5,4,3, 3,2,1,0};
    int count = sizeof(a, sizeof(a[0]));

    print_array(a, count);
    insertion_sort_int(a, count);
    print_array(a, count);

    return 0;
}
