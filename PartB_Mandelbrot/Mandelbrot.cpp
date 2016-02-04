// PartC_Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "colours.h"

//Find the value for the mandelbrot set
double FindValue(double cr, double ci, int maxIters)
{
	int i = 0;
	double zr = 0.0, zi = 0.0;
	while (i < maxIters && (zr * zr) + (zi * zi) <= 4.0)
	{
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
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
		//double y0 = (pixelY / image.height()) * (maxY - minY) + minY;
		

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			//double x0 = (pixelX / image.width()) * (maxX - minX) + minX;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal

			/*Xi = (Xi * Xi) - (Yi * Yi) + pixelX;
			Yi = (2 * Xi * Yi) + pixelY;
				
		    double Xi = Xi + 1 + (x0 * x0) - (y0 * y0) + pixelX;
		    double Yi = Yi + 1 + (2 * x0 * y0) + pixelY;
			*/

			//pixelX = (pixelX * pixelX) - (pixelY * pixelY) + pixelX;

			//Find the real and imaginary values for each pixel
			double cr = realValue(pixelX, image.width(), minX, maxX);
			double ci = ImaginaryValue(pixelY, image.height(), minY, maxY);

			//Get the mandelbrot value using the real and imagnary values
			int color = FindValue(cr, ci, maxIters);
			
			
			int red = color + color / 2;
			int green = color - color / 2;
			int blue = color / 2;
			Colour colour = { red, green, blue };
			//std::cout << red << green << blue << std::endl;
				

			// Write the pixel
			image(pixelX, pixelY, 0, 0) = colour.r;
			image(pixelX, pixelY, 0, 1) = colour.g;
			image(pixelX, pixelY, 0, 2) = colour.b;
				
			}
		

		// Uncomment this line to redisplay the image after each row is generated
		display.display(image);
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


