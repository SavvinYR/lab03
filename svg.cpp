#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='"<< baseline << "'>'"<< text <<"'</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black"){
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>\n";

}

void
show_histogram_svg(const vector<size_t>& bins)
{ double check;
size_t text1;
size_t text2;
    const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    size_t max_height;
    double MAX = (IMAGE_WIDTH - TEXT_WIDTH)/BLOCK_WIDTH;//Масштабирование
    size_t max_bin = bins[0];
    for(size_t bin : bins)
    {
        if(bin > max_bin)
        {
            max_bin = bin;
        }
    }



    for (size_t bin : bins)
    {double height = bin;
    check = max_height;
    text1 = 0;
    text2 = 0;

        if(max_bin > MAX)   //Если масштабирование необходимо
        {
             height = MAX * (static_cast<double>(bin)/max_bin);
        }
        while (check > height)
        {
            ;
            check = check - 1;
            text1 = text1 + 1;


        }
        const double bin_width = BLOCK_WIDTH * height;
        const double max_bin_width = BLOCK_WIDTH * max_height;




        svg_rect(IMAGE_WIDTH - bin_width - TEXT_WIDTH , top,bin_width, BIN_HEIGHT, "#CD5C5C", "#CD5C5C");
        svg_text (IMAGE_WIDTH - TEXT_LEFT , top + TEXT_BASELINE, to_string(bin));

        top += BIN_HEIGHT;
    }
    svg_end();
}
