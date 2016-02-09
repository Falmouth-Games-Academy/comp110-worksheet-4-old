// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"

double getMandelBrot(double cr, double ci, double maxIters)
{
	int i = 0;
	double zr = 0.0, zi = 0.0;
	while (i < maxIters && pow(zr,2) + pow(zi, 2) < 4.0)
	{
		double temp = pow(zr, 2) - pow(zi, 2) + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}

	return i;
}


int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Cutoff for iteration
	const int maxIters = 200;

	// Initialise the colour palette
	std::vector<Colour> palette = getRainbow(maxIters);

	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (double pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		//double y0 = (double(pixelY) / image.height()) + minY;

		int imageHeight = image.height();

		double imaginaryValue(double pixelY, double imageHeight, double minI, double maxI);
		{
			return pixelY * ((maxY - minY) / image.height()) + minY;
		}

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			//double x0 = (double(pixelX) / image.width()) + minX;

			int imageWidth = image.width();

			double realValue(double pixelX, double imageWidth, double minX, double maxX);
			{
				double range = maxX - minX;
				return pixelX * (range / imageWidth) + minX;
			}

			double cr = realValue(pixelX, imageWidth, minX, maxX);
			double ci = imaginaryValue(pixelY, imageHeight, minY, maxY);

			/*
			int i = getMandelBrot(cr, ci, maxIters);

			int r = (i % 256);
			int g = (i % 256);
			int b = (i % 256);
			*/

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			Colour colour = { 0,0,0 };

			int i = getMandelBrot(cr, ci, maxIters);
			Colour colour = palette[i];

			// Write the pixel
			image(pixelX, pixelY, 0, 0) = colour.r;
			image(pixelX, pixelY, 0, 1) = colour.g;
			image(pixelX, pixelY, 0, 2) = colour.b;
		}

		// Uncomment this line to redisplay the image after each row is generated
		//display.display(image);
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


