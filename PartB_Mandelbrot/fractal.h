#pragma once

class Fractal
{
public:
	void generate(CImg<unsigned char> &image);

protected:
	double minX, maxX, minY, maxY;

private:
	virtual int getIterations(double x, double y, int maxIters) = 0;
};

class Mandelbrot : public Fractal
{
public:
	Mandelbrot();

private:
	int getIterations(double x, double y, int maxIters);
};

class Julia : public Fractal
{
public:
	Julia();

private:
	int getIterations(double x, double y, int maxIters);
};



