#!/usr/bin/python

def insertion_sort(array):
    size = len(array);
    if (size < 2):
        return

    for i in range(1, size):
        j = i
        while ((j > 0) and (array[j] < array[j-1])):
            if (array[j] < array[j-1]):
                tmp = array[j]
                array[j] = array[j-1]
                array[j-1] = tmp
            j = j-1
