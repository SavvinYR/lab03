#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "histogram.h"
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    {

    } min = numbers[0];
    max = numbers[0];
    for (double number : numbers)
    {
        if (min > number)
        {
            min = number;
        }
        else if (max < number)
        {
            max = number;
        }

    }
    return;
}

void make_histogram(const size_t& bin_count, const size_t& number_count, const vector<double>& numbers,vector <size_t>& bins, double& min, double& max )
{
    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < number_count; i++)
    {
        bool found = false;
        for(size_t j = 0; j < (bin_count-1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j+1) * bin_size;
            if ((lo <= numbers[i])&& (numbers[i] < hi) )
            {
                bins[j]++;
                found = true;
            }
        }
        if(!found)
            bins[bin_count-1]++;
    }
    return;
}

void show_histogram_text(vector<size_t> bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t max_bin = bins[0];
    for(size_t bin : bins)
    {
        if(bin > max_bin)
        {
            max_bin = bin;
        }
    }

    for (size_t bin : bins)
    {
        if(max_bin > MAX_ASTERISK)   //Если масштабирование необходимо
        {
            size_t heignt = MAX_ASTERISK * (static_cast<double>(bin)/max_bin);
        }

        if(bin < 100)
        {
            cout << " ";
        }
        if(bin < 10)
        {
            cout << " ";
        }
        cout << bin <<"|";
        for(size_t i = 0; i < bin; i++)
        {
            cout << '*';
        }
        cout << endl;
    }
    return;}
