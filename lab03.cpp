
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
using namespace std;

vector<double> input_numbers(istream& in, size_t count) //функция ввода чисел
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}

Input read_input(istream& in, bool prompt) {
    Input data;

    if (prompt)
        cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;
    data.number_count = number_count;

    if (prompt)
        cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    size_t bin_count;
    if (prompt)
        cerr << " Enter bin count:";
    cin >> bin_count;
    data.bin_count = bin_count;

    // ...

    return data;
}




int main()
{
    curl_global_init(CURL_GLOBAL_ALL);



    //Ввод данных


    const auto input = read_input(cin, true);

    //Расчет гистограммы

    const auto bins = make_histogram(input);

    //Вывод данных
    show_histogram_svg( bins);
    return 0 ;
}
