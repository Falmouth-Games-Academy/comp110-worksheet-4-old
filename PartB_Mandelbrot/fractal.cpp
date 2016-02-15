#include "stdafx.h"
#include "fractal.h"
#include "colours.h"

Mandelbrot::Mandelbrot()
{
	minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;
}

Julia::Julia()
{
	minX = -1.5, maxX = 1.5, minY = -1.5, maxY = 1.5;
}

double Mandelbrot::getMinX()
{
	return minX;
}

double Mandelbrot::getMaxX()
{
	return maxX;
}

double Mandelbrot::getMinY()
{
	return minY;
}

double Mandelbrot::getMaxY()
{
	return maxY;
}

double Julia::getMinX()
{
	return minX;
}

double Julia::getMaxX()
{
	return maxX;
}

double Julia::getMinY()
{
	return minY;
}

double Julia::getMaxY()
{
	return maxY;
}


void Fractal::generate(CImg<unsigned char> &image)
{
	const int maxIters = 200;

	// Initialise the colour palette
	std::vector<Colour> palette = getRainbow(maxIters);

	const double minX = getMinX(), maxX = getMaxX(), minY = getMinY(), maxY = getMaxY();

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		double y0 = (static_cast<double>(pixelY) / image.height()) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			double x0 = (static_cast<double>(pixelX) / image.width()) * (maxX - minX) + minX;

			// Get the number of iterations needed to determine if it's in the set
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
		double nextX = x*x - y*y + cX;
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
	const double cX = 0.279;
	const double cY = 0;
	int i = 0;

	while (x*x + y*y < 4 && i < maxIters)
	{
		double nextX = x*x - y*y + cX;
		double nextY = (2 * x * y) + cY;

		// Used for checking this iteration and calculating the next
		x = nextX;
		y = nextY;

		// To keep track of position in sequence
		i++;
	}

	return i;
}

