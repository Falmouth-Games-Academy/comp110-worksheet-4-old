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
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// Maps the y coordinate into the range minY to maxY
		double y0 = (static_cast<double>(pixelY)/static_cast<double>(image.height())) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Maps the x coordinate into the range minX to maxX
			double x0 = (static_cast<double>(pixelX)/ static_cast<double>(image.width())) * (maxX - minX) + minX;
			int i = 0; //For use in the while loop
			double currentX = x0;
			double currentY = y0;
			Colour colour;
			
			while (i < maxIters && (std::pow(currentX, 2) + std::pow(currentY, 2))<=4)
			{
				double nextX = std::pow(currentX, 2) - std::pow(currentY, 2) +x0;
				double nextY = (2 * currentX * currentY) + y0;

				currentX = nextX;
				currentY = nextY;
				
				i++;
			}
			
			// Select the pixel colour
			if (i < maxIters)
			{
				colour = palette[i];
			}
			else
			{
				colour = { 0,0,0 };
				//black
			}
			
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


