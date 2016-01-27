// Cimg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	CImg<unsigned char> myImage(500, 400, 1, 3);

	CImgDisplay myDisplay(myImage, "Hello");
	myDisplay.show();

	int t = 0;

	while (!myDisplay.is_closed())
	{
		for (int x = 0; x < myImage.width(); x++)
		{
			for (int y = 0; y < myImage.height(); y++)
			{
				myImage(x, y, 0, 0) = x * y + t;
				myImage(x, y, 0, 1) = y * x - t;
				myImage(x, y, 0, 2) = rand() + x - y * t;
			}

		}
		myDisplay.display(myImage);

		t++;
	}
	//CImgDisplay myDisplay(myImage, "Hello");
	//myDisplay.show();

	//while (!myDisplay.is_closed())
	{
		myDisplay.wait();
	}

    return 0;
}

