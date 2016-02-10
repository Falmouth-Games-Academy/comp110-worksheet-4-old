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
	int amplify = 0;
	while (true)
	{

			// Generate the image
			for (int pixelY = 0; pixelY < image.height(); pixelY++)
			{
				// TODO: Map the y coordinate into the range minY to maxY
				double y0 = ((maxY - minY) / image.width()) * pixelY + minY;                                                                 //y0 = (pixelY / image.height()) * (maxY - minY) + minY;


				for (int pixelX = 0; pixelX < image.width(); pixelX++)
				{
					// TODO: Map the x coordinate into the range minX to maxX
					double x0 = ((maxX - minX) / image.width()) * pixelX + minX;

					// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal

					int i = 0;
					double Xi = 0.0;
					double Yi = 0.0;

					// Find the value for the mandelbrot set
					// using the escape time algorithm
					while ((Xi * Xi) + (Yi * Yi) <= 4.0 && i < maxIters)
					{
						double temp = Xi * Xi - Yi * Yi + x0;
						Yi = 2.0 * Xi * Yi + y0;
						Xi = temp;
						i++;
						//std::cout << i << std::endl;
					}

					if (i < maxIters)
					{
						int color = i;
						int red = 30;
						int green = color;
						int blue = color;

						Colour colour = { red, green, blue };

						// Write the pixel
						image(pixelX, pixelY, 0, 0) = colour.r;
						image(pixelX, pixelY, 0, 1) = colour.g;
						image(pixelX, pixelY, 0, 2) = colour.b;
						
					}
				}

				// Uncomment this line to redisplay the image after each row is generated
				//display.display(image);
			}

		// Display the complete image
		display.display(image);
		std::cout << "Image Render Complete." << std::endl;
	}

	// Uncomment this line to save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


