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

	// Set min and max values for the mandelbrot set
	double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	
		// Generate the image
		for (int pixelY = 0; pixelY < image.height(); pixelY++)
		{
			double y0 = ((maxY - minY) / image.width()) * pixelY + minY;
			for (int pixelX = 0; pixelX < image.width(); pixelX++)
			{
				double x0 = ((maxX - minX) / image.width()) * pixelX + minX;

				//Initialize variables for the algorithm
				int i = 0;
				double Xi = 0.0;
				double Yi = 0.0;
				
				// Find the value for the mandelbrot set..
				// ..using the escape time algorithm
				while ((Xi * Xi) + (Yi * Yi) <= 4.0 && i < maxIters)
				{
					double temp = Xi * Xi - Yi * Yi + x0;
					Yi = 2.0 * Xi * Yi + y0;
					Xi = temp;
					i++;
				}
				
				// Writes the pixel colour with the value of i
				if (i < maxIters)
				{
					
					int red = i;
					int green = i * 2;  // multiplying by 2 to give it a colour
					int blue = i * 2;

					// TODO: Use the colour palette to draw the correct colours
					Colour colour = { red, green, blue };

					image(pixelX, pixelY, 0, 0) = colour.r;
					image(pixelX, pixelY, 0, 1) = colour.g;
					image(pixelX, pixelY, 0, 2) = colour.b;
				}
			}
		}

	// Display the complete image
	display.display(image);
	std::cout << "Image Render Complete." << std::endl;

	// Save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


