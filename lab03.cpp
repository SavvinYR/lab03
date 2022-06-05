#include "histogram.cpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "histogram.h"
#include "svg.cpp"
using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
    size_t number_count;
};

vector<double> input_numbers(istream& in, size_t count) //функция ввода чисел
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


    //Ввод данных


    const auto input = read_input(cin);

    //Расчет гистограммы
    vector <size_t> bins (input.bin_count, 0);
    double min ;
    double max ;
    find_minmax(input.numbers, min, max);
    make_histogram(input.bin_count, input.number_count, input.numbers, bins, min, max);

    //Вывод данных
    show_histogram_svg( bins);
    return 0 ;
}
