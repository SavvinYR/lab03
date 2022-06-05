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

Input read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;
    data.number_count = number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    size_t bin_count;
    cerr << " Enter bin count:";
    cin >> bin_count;
    data.bin_count = bin_count;

    // ...

    return data;
}




int main()
{


    //���� ������


    const auto input = read_input(cin);

    //������ �����������

    const auto bins = make_histogram(input);

    //����� ������
    show_histogram_svg( bins);
    return 0 ;
}
