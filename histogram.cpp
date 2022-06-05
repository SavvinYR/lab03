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
