// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"
#include "fractal.h"


/*void generate(CImg<unsigned char> &image)
{
	const int maxIters = 200;

	// Initialise the colour palette
	std::vector<Colour> palette = getRainbow(maxIters);

	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		double y0 = (double(pixelY) / image.height()) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			double x0 = (double(pixelX) / image.width()) * (maxX - minX) + minX;

			// Initialise first term of the sequence
			double memX = x0;
			double memY = y0;
			unsigned char i = 0;

			while (memX*memX + memY*memY < 4 && i < maxIters)
			{
				double nextX = pow(memX, 2) - pow(memY, 2) + x0;
				double nextY = (2 * memX * memY) + y0;

				// Used checking this iteration and calculating the next
				memX = nextX;
				memY = nextY;

				// To keep track of position in sequence
				i++;
			}

			Colour colour;

			if (i >= maxIters)
				colour = { 0, 0, 0 };
			else
				colour = palette[i];

			// Write the pixel
			image(pixelX, pixelY, 0, 0) = colour.r;
			image(pixelX, pixelY, 0, 1) = colour.g;
			image(pixelX, pixelY, 0, 2) = colour.b;
		}
	}
}*/

void generate(CImg<unsigned char> &image)
{
	const int maxIters = 200;

	// Initialise the colour palette
	std::vector<Colour> palette = getRainbow(maxIters);

	const double minX = -1.5, maxX = 1.5, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		double y0 = (double(pixelY) / image.height()) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			double x0 = (double(pixelX) / image.width()) * (maxX - minX) + minX;

			// Initialise first term of the sequence
			double memX = x0;
			double memY = y0;
			unsigned char i = 0;

			while (memX*memX + memY*memY < 4 && i < maxIters)
			{
				double nextX = pow(memX, 2) - pow(memY, 2) + 0.279;
				double nextY = (2 * memX * memY);

				// Used checking this iteration and calculating the next
				memX = nextX;
				memY = nextY;

				// To keep track of position in sequence
				i++;
			}

			Colour colour;

			if (i >= maxIters)
				colour = { 0, 0, 0 };
			else
				colour = palette[i];

			// Write the pixel
			image(pixelX, pixelY, 0, 0) = colour.r;
			image(pixelX, pixelY, 0, 1) = colour.g;
			image(pixelX, pixelY, 0, 2) = colour.b;
		}
	}
}


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


