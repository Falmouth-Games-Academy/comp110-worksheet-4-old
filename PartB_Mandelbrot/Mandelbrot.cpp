// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"

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
		double y0 = (pixelY / image.height())*(maxY - minY) + minY;


		for (double pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / image.width())*(maxX - minX) + minX;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			double x = 0.0;
			double y = 0.0;
			int iteration = 0.0;
			while (x*x + y*y <= 4.0 && iteration < maxIters)
			{
				double colourX = x*x - y*y + x0;
				double colourY = 2.0 * x*y + y0;
				x = colourX;
				y = colourY;
				iteration++;
			}
		
			if (iteration < maxIters)
			{
				int red = 30;
				int green = iteration;
				int blue = iteration;
				Colour colour = { red,green,blue };

				// Write the pixel
				image(pixelX, pixelY, 0, 0) = colour.r;
				image(pixelX, pixelY, 0, 1) = colour.g;
				image(pixelX, pixelY, 0, 2) = colour.b;
				//std::cout << green << std::endl;
			}
				
			}
			/*
			else
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			*/


		// Uncomment this line to redisplay the image after each row is generated
		//display.display(image);
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


