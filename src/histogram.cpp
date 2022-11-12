
#include "histogram.hpp"

using namespace sciplot;

void dessinerHistogrammeDegres(int nSommet, const std::vector<int> &degresInt, std::string label)
{
    // nSommet = degre maximum possible + 1

    // Create a vector with the xtic labels for the boxes
    std::vector<std::string> names(nSommet);
    int plusGrandDegre = 0;
    int plusGrandNombreSommeMemeDegre = 0;

    for(int i = 0 ; i < nSommet ; i++)
    {
        if (degresInt[i] != 0){
            plusGrandDegre = i;
            if (degresInt[i] > plusGrandNombreSommeMemeDegre)
                plusGrandNombreSommeMemeDegre = degresInt[i];
        }
    }

    for(int i = 0 ; i < plusGrandDegre ; i++)
    {
        if (plusGrandDegre < 10){
            names[i] = std::to_string(i);
        }
        else if (plusGrandDegre < 100){
            if (i%10 == 0)
                names[i] = std::to_string(i);
        }
        else if (plusGrandDegre < 1000){
            if (i%100 == 0)
                names[i] = std::to_string(i);
        }
        else {
            if (i%250 == 0)
                names[i] = std::to_string(i);
        }
        
        // else
            // names[i] = std::to_string(i);
    }
    // Create a vector with the y values for the boxes
    // std::valarray<double> lDegres(degres.data(), degres.size());
    std::vector<double> degres(degresInt.begin(), degresInt.end());
    // sciplot::Vec lDegres = degres;

    // Create a vector with the xwidth values for the boxes
    std::vector<double> experiences(nSommet, 0.7);

    // Create a Plot object
    Plot2D plot;

    // Set the legend to the top left corner of the plot
    plot.legend().atTopLeft();
    plot.fontSize(10);

    // Set the y label and its range
    plot.ylabel(label);
    plot.yrange(0.0, plusGrandNombreSommeMemeDegre);

    //resizing vector
    names.resize(plusGrandDegre);
    degres.resize(plusGrandDegre);
    experiences.resize(plusGrandDegre);

    // Plot the boxes using y values.
    plot.drawBoxes(names, degres, experiences)
        .fillSolid()
        .fillColor("pink")
        .fillIntensity(0.5)
        .borderShow()
        .labelNone();

    // plot.xtics()
    //     .show(false);
    // Adjust the relative width of the boxes
    plot.boxWidthRelative(0.75);

    plot.autoclean(false);

    // Create figure to hold plot
    Figure fig = {{plot}};
    // Create canvas to hold figure
    Canvas canvas = {{fig}};

    // canvas.size(700,700);
    // canvas
    // Show the plot in a pop-up window
    canvas.show();

    // Save the plot to a PDF file
    // canvas.save("example-boxes-ticklabels.pdf");
}