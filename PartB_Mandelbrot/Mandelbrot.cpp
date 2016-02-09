// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"

// Find the value for the mandelbrot set
// using the escape time algorithm
double FindValue(double cr, double ci, int maxIters)
{
	int i = 0;
	double Xi = 0.0, Yi = 0.0;
	while ((Xi * Xi) + (Yi * Yi) <= 2.0 && i < maxIters)
	{
		double temp = Xi * Xi - Yi * Yi + cr;
		Yi = 2.0 * Xi * Yi + ci;
		Xi = temp;
		i++;
	}
	return i;
}

double realValue(int pixelX, int imageWidth, double minReal, double maxReal)
{
	double range = maxReal - minReal;
	return pixelX * (range / imageWidth) + minReal;
}

double ImaginaryValue(int pixelY, int imageHeight, double minImaginary, double maxImaginary)
{
	double range = maxImaginary - minImaginary;
	return pixelY * (range / imageHeight) + minImaginary;
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
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		double y0 = (pixelY / image.height()) * (maxY - minY) + minY;
		

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / image.width()) * (maxX - minX) + minX;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal

			// Find the real and imaginary values for each pixel using the 
			double cReal = realValue(pixelX, image.width(), minX, maxX);
			double cImaginary = ImaginaryValue(pixelY, image.height(), minY, maxY);

			// Get the mandelbrot value using the real and imagnary values
			int color = FindValue(cReal, cImaginary, maxIters);
			
			int red = color;
			int green = color;
			int blue = color;
			Colour colour = { red, green, blue };

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
	std::cout << "Image Render Complete." << std::endl;
	

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}


