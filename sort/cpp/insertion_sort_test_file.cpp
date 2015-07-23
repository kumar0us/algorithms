#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "insertion_sort"

using namespace std;

template <class RandomAccessIterator>
void print_vector(RandomAccessIterator begin, RandomAccessIterator end)
{
    cout << "***************************************" << endl;
    for (;begin < end; begin++)
    {
	cout << *begin << endl;
    }
    cout << "***************************************" << endl;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
	cout << "Usage: " << argv[0] << " <type> <file-name>" << endl;
	cout << "Example: " << argv[0] << " int random_num_int.txt" << endl;
	return 1;
    }

    string type = argv[1];

    std::ifstream is;
    is.open(argv[2], ios::in);

    if (is.is_open())
    {
	if (type.compare("int") == 0)
	{
	    int data;
	    vector<int> v_int;
	    while (is >> data)
		v_int.push_back(data);

	    print_vector(v_int.begin(), v_int.end());
	    insertion_sort(v_int.begin(), v_int.end());
	    print_vector(v_int.begin(), v_int.end());
	}	    
	else if (type.compare("long") == 0)
	{
	    long data;
	    vector<long> v_long;
	    while (is >> data)
		v_long.push_back(data);
	    print_vector(v_long.begin(), v_long.end());
	    insertion_sort(v_long.begin(), v_long.end());
	    print_vector(v_long.begin(), v_long.end());
	}
	else if (type.compare("float") == 0)
	{
	    float data;
	    vector<float> v_float;
	    while (is >> data)
		v_float.push_back(data);
	    print_vector(v_float.begin(), v_float.end());
	    insertion_sort(v_float.begin(), v_float.end());
	    print_vector(v_float.begin(), v_float.end());
	}
	else if (type.compare("double") == 0)
	{
	    double data;
	    vector<double> v_double;
	    while (is >> data)
		v_double.push_back(data);
	    print_vector(v_double.begin(), v_double.end());
	    insertion_sort(v_double.begin(), v_double.end());
	    print_vector(v_double.begin(), v_double.end());
	}
    }

    is.close();

    return 0;
}
