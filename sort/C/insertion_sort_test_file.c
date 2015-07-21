#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "insertion_sort.h"

#define INITIAL_ARRAY_SIZE	16
#define read_arg(type, fp, fmt_str, p_count)				\
    type * read_arg_##type (FILE* fp, char *fmt_str, int* p_count)	\
{									\
    int count = 0;							\
    type arg;								\
    int array_size = 0;							\
    type *array = malloc (sizeof (type) * INITIAL_ARRAY_SIZE);		\
    if (array == NULL)							\
    {									\
	printf ("Failed to allocate memory for %zd bytes.\n",		\
		INITIAL_ARRAY_SIZE * sizeof (type));			\
	return NULL;							\
    }									\
    array_size = INITIAL_ARRAY_SIZE;					\
    while (fscanf(fp, fmt_str, &arg) == 1) 				\
    {									\
	if (array_size == count)					\
	{								\
	    array_size *= 2;						\
	    array = realloc (array, array_size * sizeof (type));	\
	}								\
	array[count++] = arg;						\
    }									\
    									\
    *p_count = count;							\
    return array;							\
}

read_arg(double, fp, fmt_str, ptr);
read_arg(float, fp, fmt_str, ptr);
read_arg(long, fp, fmt_str, ptr);
read_arg(int, fp, fmt_str, ptr);

#define print_array(type, array, fmt_str, size)				\
	void print_array_##type(type* array, char *fmt_str, int size)	\
{									\
									\
    int i = 0;								\
    for (i = 0; i < size; i++)						\
    {									\
	printf (fmt_str, array[i]);					\
    }									\
}									\

print_array(int, array, fmt_str, size);
print_array(long, array, fmt_str, size);
print_array(double, array, fmt_str, size);
print_array(float, array, fmt_str, size);

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    int array_size = 0;
    time_t rawtime = {0,};
    const char *arg_type = NULL;

    if (argc != 3)
    {
	printf ("Usage: %s <type> <file-name>\n", argv[0]);
	printf ("Example: %s int random_int.txt\n", argv[0]);
	return 1;
    }

    time (&rawtime);
    arg_type = argv[1];
    fp = fopen (argv[2], "r");
    if (fp == NULL)
    {
	printf ("Failed to open file %s for reading. err = %d(%s)\n", argv[2],
		errno, strerror(errno));
	return 1;
    }

    if (strcmp(arg_type, "int") == 0) {
	printf("time before reading file: %s\n", (time(&rawtime),asctime(localtime(&rawtime))));
	int *int_array = read_arg_int(fp, "%d", &array_size);
	printf("time after reading file: %s\n", (time(&rawtime),asctime(localtime(&rawtime))));
	if (int_array)
	{
	    insertion_sort_int(int_array, array_size);
	    printf("time after sorting file: %s\n", (time(&rawtime),asctime(localtime(&rawtime))));
	    //print_array_int(int_array, "%d\n", array_size);
	    free (int_array);
	}
    }
    else if (strcmp(arg_type, "long") == 0) {
	long *long_array = read_arg_long(fp, "%ld", &array_size);
	if (long_array)
	{
	    insertion_sort_long(long_array, array_size);
	    print_array_long(long_array, "%ld\n", array_size);
	    free (long_array);
	}
    }
    else if (strcmp(arg_type, "float") == 0) {
	float *float_array = read_arg_float(fp, "%f", &array_size);
	if (float_array)
	{
	    insertion_sort_float(float_array, array_size);
	    print_array_float(float_array, "%f\n", array_size);
	    free (float_array);
	}
    }
    else if (strcmp(arg_type, "double") == 0) {
	double *double_array = read_arg_double(fp, "%lf", &array_size);
	if (double_array)
	{
	    insertion_sort_double(double_array, array_size);
	    print_array_double(double_array, "%lf\n", array_size);
	    free (double_array);
	}
    }

    fclose (fp);

    return 0;
}
