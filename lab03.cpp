#include <sstream>
#include <string>
#include <cstdlib>
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

int printf(const char* format, ...)
           const char* name = "Commander Shepard";
int year = 2154;
printf("%s was born in %d.\n", name, year);
// Commander Shepard was born in 2154.

Input read_input(istream& in, bool prompt)
{
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


size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx)
{
    size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<const char*>(items), data_size);
    return data_size;

}



Input
download(const string& address)
{
    stringstream buffer;

    {
        CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

            res = curl_easy_perform(curl);
            ;



            if (!(res == 0))
            {
                cout<< curl_easy_strerror(res);
                exit(1);
            }
            curl_easy_cleanup(curl);
        }
    }

    return read_input(buffer, false);
}




//int main(int argc, char* argv[])
//{Input input;
//    if (argc > 1)
// {for (int i=0;i<argc; i++){
// if(strcmp(argv[i] , "-generate")==0){
//   int rcount = atoi(argv[i+1];
//     if (rcount > 0)
//       for(int j = 0; j < rcount; j++)
//         cout << rand() % 5 +1 <<" ";
//       else
//         {cerr << "Incorrect input. Example: "Lab04.exe http://... -generate 10 " or "Lab04.exe  -generate `10 http://..."";
//          return 0;
//         }
// else
//    input = download(argv[i]);
// }
//
//    } else {
//        input = read_input(cin, true);
//    }
int
main(int argc, char* argv[])
{printf("n = %08x\n", 0x1234567); // 01234567
return 0;}
    Input input;
    //int rcount;
    //vector<size_t> A(rcount);

    if (argc > 1)
    {
//        for (int i=0; i<argc; i++)
//        {
//            if(strcmp(argv[i], "-generate")==0)
//            {
//                 rcount = atoi(argv[i+1]);
//           }
//            if ( rcount > 0)
//
//            { vector<size_t> A(rcount);
//                for(int j = 0; j < rcount; j++)
//                {int a = rand() % 5 +1;
//                  vector <size_t> A[j]  = a;
//                input = read_input(A, true);}
//            }
//            else
//            {
//                cerr << "Incorrect input. Example: Lab04.exe http:... -generate 10  or Lab04.exe  -generate `10 http:...";
//                return 0;
//            }
//        }else
        input = download(argv[1]);
    }
    else{

        input = read_input(cin, true);
    }





    //Ввод данных




    //Расчет гистограммы

    const auto bins = make_histogram(input);

    //Вывод данных
    show_histogram_svg( bins);
    return 0 ;
}
