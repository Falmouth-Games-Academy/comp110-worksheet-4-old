#pragma once

class Fractal
{
public:
	void generate(CImg<unsigned char> &image);

private:
	virtual int getIterations(double x, double y, int maxIters) = 0;
	virtual double getMinX() = 0;
	virtual double getMaxX() = 0;
	virtual double getMinY() = 0;
	virtual double getMaxY() = 0;
};

class Mandelbrot : public Fractal
{
public:
	Mandelbrot();

private:
	int getIterations(double x, double y, int maxIters);

	double minX, maxX, minY, maxY;
	double getMinX();
	double getMaxX();
	double getMinY();
	double getMaxY();
};

class Julia : public Fractal
{
public:
	Julia();

private:
	int getIterations(double x, double y, int maxIters);

	double minX, maxX, minY, maxY;
	double getMinX();
	double getMaxX();
	double getMinY();
	double getMaxY();
};



