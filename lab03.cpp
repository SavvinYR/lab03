
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




int main(int argc, char* argv[])
{ if (argc > 1){
    CURL *curl = curl_easy_init();
if(curl) {
  CURLcode res;
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  if (!(res == 0)){
    cout<< curl_easy_strerror(res);
    exit(1);}
}
    return 0;}
curl_global_init(CURL_GLOBAL_ALL);



    //Ввод данных


    const auto input = read_input(cin, true);

    //Расчет гистограммы

    const auto bins = make_histogram(input);

    //Вывод данных
    show_histogram_svg( bins);
    return 0 ;
}
