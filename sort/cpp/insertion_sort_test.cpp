#include <iostream>
#include <vector>
#include "insertion_sort"

template <class RandomAccessIterator>
void print_array(RandomAccessIterator begin, RandomAccessIterator end)
{
    for (; begin < end; begin++)
    {
	cout << *begin << "\t";
    }

    cout << endl;
}

int main()
{
    vector<int> v_int;
    vector<float> v_float;
    vector<long> v_long;
    vector<double> v_double;

    for (int i = 10; i > 0; i--)
	v_int.push_back(i);

    for (int i = 10; i > 0; i--)
	v_long.push_back(i);

    for (int i = 10; i > 0; i--)
	v_float.push_back((float)i);

    for (int i = 10; i > 0; i--)
	v_double.push_back((double)i);

    print_array(v_int.begin(), v_int.end());
    insertion_sort(v_int.begin(), v_int.end());
    print_array(v_int.begin(), v_int.end());

    print_array(v_long.begin(), v_long.end());
    insertion_sort(v_long.begin(), v_long.end());
    print_array(v_long.begin(), v_long.end());

    print_array(v_float.begin(), v_float.end());
    insertion_sort(v_float.begin(), v_float.end());
    print_array(v_float.begin(), v_float.end());

    print_array(v_double.begin(), v_double.end());
    insertion_sort(v_double.begin(), v_double.end());
    print_array(v_double.begin(), v_double.end());
}
