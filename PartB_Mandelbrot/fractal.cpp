#include "stdafx.h"
#include "fractal.h"
#include "colours.h"


void Fractal::generate(CImg<unsigned char> &image)
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

			int iterations = getIterations(x0, y0, maxIters);

			Colour colour;

			if (iterations >= maxIters)
				colour = { 0, 0, 0 };
			else
				colour = palette[iterations];

			// Write the pixel
			image(pixelX, pixelY, 0, 0) = colour.r;
			image(pixelX, pixelY, 0, 1) = colour.g;
			image(pixelX, pixelY, 0, 2) = colour.b;
		}
	}
}


int Mandelbrot::getIterations(double x, double y, int maxIters)
{
	double cX = x;
	double cY = y;	
	int i = 0;

	while (x*x + y*y < 4 && i < maxIters)
	{
		double nextX = pow(x, 2) - pow(y, 2) + cX;
		double nextY = (2 * x * y) + cY;

		// Used for checking this iteration and calculating the next
		x = nextX;
		y = nextY;

		// To keep track of position in sequence
		i++;
	}

	return i;
}


int Julia::getIterations(double x, double y, int maxIters)
{
	int i = 0;

	while (x*x + y*y < 4 && i < maxIters)
	{
		double nextX = pow(x, 2) - pow(y, 2) + 0.279;
		double nextY = (2 * x * y);

		// Used for checking this iteration and calculating the next
		x = nextX;
		y = nextY;

		// To keep track of position in sequence
		i++;
	}

	return i;
}

