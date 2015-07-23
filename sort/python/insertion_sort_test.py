import os
import sys
import insertion_sort

def read_file_in_array(filename):
    f = open(filename, 'r')
    a = []
    for line in f:
        a.append(int(line));

    return a

def main(argv):
    progname = argv[0]
    if (len(argv) != 2):
        print 'Usage: {0} <filename>'.format(argv[0])
        print 'Example: {0} random_num.txt'.format(argv[0])
        return 1

    a = read_file_in_array(argv[1]);
    print a
    insertion_sort.insertion_sort(a)
    print a
    return 0

if __name__ == "__main__":
   sys.exit(main(sys.argv)) 
