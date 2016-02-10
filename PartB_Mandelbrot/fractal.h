#pragma once

class Fractal
{
public:
	void generate(CImg<unsigned char> &image);

private:
	virtual int getIterations(double x, double y, int maxIters) = 0;
};

class Mandelbrot : public Fractal
{
private:
	int getIterations(double x, double y, int maxIters);
};

class Julia : public Fractal
{
private:
	int getIterations(double x, double y, int maxIters);
};



