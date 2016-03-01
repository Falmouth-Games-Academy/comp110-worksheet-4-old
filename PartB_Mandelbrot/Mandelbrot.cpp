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
		double initialY = (static_cast<double>(pixelY)/static_cast<double>(image.height())) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Maps the x coordinate into the range minX to maxX
			double initialX = (static_cast<double>(pixelX)/ static_cast<double>(image.width())) * (maxX - minX) + minX;
			int i = 0; // Used to count iterations of the while loop and the pixel colour
			double currentX = initialX;
			double currentY = initialY;
			Colour colour;
			
			while (i < maxIters && (std::pow(currentX, 2) + std::pow(currentY, 2)) <= 4)
			{
				// Calculate the next X and Y values
				double nextX = std::pow(currentX, 2) - std::pow(currentY, 2) + initialX;
				double nextY = (2 * currentX * currentY) + initialY;

				//Set the currentX and currentY values to equal the nextX and nextY
				currentX = nextX;
				currentY = nextY;
				
				i++;
			}
			
			// Select the pixel colour
			if (i < maxIters)
			{
				colour = palette[i];
				// If the number of iterations (i) is below maxIters (200) set the pixel colour to the current value of i
			}
			else
			{
				colour = { 0,0,0 };
				// If the numer of iteration (i) is equal to or greater than maxIters set the pixel colour to black
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


