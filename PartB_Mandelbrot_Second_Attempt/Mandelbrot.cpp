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
	int black = 0x000000, white = 0xFFFFFF;
	
	// Generate the image
	for (double pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// Map the y coordinate into the range minY to maxY
		double y0 = (pixelY / image.height()) * (maxY - minY) + minY;

		for (double pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Map the x coordinate into the range minX to maxX
			double x0 = (double(pixelX) / image.width()) * (maxX - minX) + minX;

			// Get the exit iteration for a single pixel (x0, y0) of the Mandelbrot set fractal
			double x = 0, y = 0;

			int i = 0;
			while (pow(x, 2) + pow(y, 2) <= 4 && i < maxIters)
			{
				double x_new = pow(x, 2) - pow(y, 2) + y0;
				y = 2 * x*y + x0;
				x = x_new;
				i++;
			} 
			
			// Set the colour for each pixel using the palette
			Colour colour;

			if (i < maxIters) colour = palette[i];
			
			else colour = { 0,0,0 };

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


