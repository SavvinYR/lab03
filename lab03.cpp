#include "histogram.cpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "histogram.h"
#include "svg.cpp"
using namespace std;

vector<double> input_numbers(istream& in, size_t count) //������� ����� �����
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}






int main()
{


    //���� ������
    size_t number_count;


    cerr << "Enter number count:";
    cin >> number_count;

    const auto numbers = input_numbers(cin, number_count);

    size_t bin_count;
    cerr << " Enter bin count:";
    cin >> bin_count;

    //������ �����������
    vector <size_t> bins (bin_count, 0);
    double min ;
    double max ;
    find_minmax(numbers, min, max);
    make_histogram(bin_count, number_count, numbers, bins, min, max);

    //����� ������
    show_histogram_svg( bins);
    return 0 ;
}
