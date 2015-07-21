#include "insertion_sort.h"

#define compare(type)						\
	static int compare_##type(type a, type b)		\
{								\
    if (a < b)							\
    {								\
	return -1;						\
    }								\
								\
    return 1;							\
}

compare(double);
compare(float);
compare(long);
compare(int);

#define insertion_sort(type) 					\
    void insertion_sort_##type(type array[], int count)		\
{								\
    int i = 0, j = 0, tmp = 0;					\
    for (i = 1; i < count; i++)					\
    {								\
	j = i;							\
	do							\
	{							\
	    if (compare_##type(array[j], array[j-1]) < 0)	\
	    {							\
		tmp = array[j];					\
		array[j] = array[j-1];				\
		array[j-1] = tmp;				\
	    }							\
	    j--;						\
	} while ((j > 0) && (array[j] < array[j-1]));		\
    }								\
}

insertion_sort(double);
insertion_sort(float);
insertion_sort(long);
insertion_sort(int);

