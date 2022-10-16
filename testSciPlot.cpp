#include <sciplot/sciplot.hpp>
#include <vector>
#include <iostream>


using namespace sciplot;

int main(int argc, char** argv)
{
    // Create a vector with the xtic labels for the boxes
    int degreMaximum = 4;
    std::vector<std::string> names(4);
    for(int i = 0 ; i < degreMaximum ; i++)
    {
        std::cout << i << std::endl;
        names[i] = std::to_string(i);
    }
    for(std::string name : names)
    {
        std::cout << name << std::endl;
    }

    // Create a vector with the y values for the boxes
    std::vector<double> ages = {44, 27, 35, 20};

    // Create a vector with the xwidth values for the boxes
    Vec experiences = {0.5, 0.5, 0.5, 0.5};

    // Create a Plot object
    Plot2D plot;

    // Set the legend to the top left corner of the plot
    plot.legend().atTopLeft();

    // Set the y label and its range
    plot.ylabel("Age");
    plot.yrange(0.0, 50);

    // Plot the boxes using y values.
    plot.drawBoxes(names, ages, experiences)
        .fillSolid()
        .fillColor("pink")
        .fillIntensity(0.5)
        .borderShow()
        .labelNone();

    // Adjust the relative width of the boxes
    plot.boxWidthRelative(0.75);

    plot.autoclean(false);

    // Create figure to hold plot
    Figure fig = {{plot}};
    // Create canvas to hold figure
    Canvas canvas = {{fig}};

    // Show the plot in a pop-up window
    canvas.show();

    // Save the plot to a PDF file
    canvas.save("example-boxes-ticklabels.pdf");
}