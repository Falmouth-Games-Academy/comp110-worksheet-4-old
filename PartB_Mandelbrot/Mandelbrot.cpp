// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"
#include "fractal.h"


Fractal* getFractal()
{
	while (true)
	{
		std::cout << "\nWould you like to generate a Mandelbrot Fractal or Julia Fractal? (M / J)" << std::endl;
		std::string choice;
		std::getline(std::cin, choice);

		if (choice == "M")
		{
			Fractal* fractal = new Mandelbrot;
			return fractal;
		}
		else if (choice == "J")
		{
			Fractal* fractal = new Julia;
			return fractal;
		}
		else
			std::cout << "Please enter 'M' or 'J'" << std::endl;
	}
}


int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Get the user's choice of fractal
	Fractal* fractal = getFractal();

	// Generate the image
	(*fractal).generate(image);

	// Display the complete image
	display.display(image);

	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


