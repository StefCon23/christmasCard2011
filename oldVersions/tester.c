#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
**	tester.c
**
**	testing functions in christmasCard2011.c
**
**	CST, 26 May 2015
*/


int drawXmasBall( int centreX, int centreY, int radius, 
	int red, int green, int blue, int step )
{
	/*
	**	Draw Xmas Ball
	**
	**	Draws a Christmas Ball
	**
	**	Draws a circle with a centre point (centreX, centreY), 
	**		a radius described by "int radius", and colouring 
	**		described by (red, green, blue)
	**	Then draws circles of decreasing radius within that circle,
	**		the radius decreases by 
	**
	**	int centreX	==	x point for centre of circle
	**	int centreY	==	y point for centre of circle
	**	int radius	==	radius of circle
	**
	**	int red		==	red value for colour of circle
	**	int green	==	green value for colour of circle
	**	int blue	==	blue value for colour of circle
	*/
	
/*
//	OLD version, not great
	//	circle outline
	//		i.e. circle at (centreX, centreY)
	//		with radius "radius"
	//		and coloured (red, green, blue)
	printf("centre = (%d, %d)\nradius = %d\n\n", centreX, centreY, radius);
	//inner concentric circles
	//  radius - spacec = new circles radius
	int spacec = rand() % 6 + 2;

	int qtyc;
	for(qtyc= 0; qtyc< (radius); qtyc++)
	{
		//if the current circles radius
		//  is greater than (and not equal to)
		//  the circle radius change (spacec)
		if(radius > spacec)
		{
			//decreasing radius
			radius -= spacec;
		}
		//new smaller circle
		printf("space = %d\tradius = %d\tcount = %d\n", spacec, radius, qtyc);
	}
*/

	//	mode
	//		originally the radius decreased to about a third of the original
	//			size and no further
	//		another option is to decrease to a fixed size
	//		a minus value for mode represents the original version,
	//			any other value is the radius the circle decreases to
	int mode = -1;
	
	//	counter
	//		used for mode 0
	int counter = 0;
	if (mode >= 0) {	//	new style
		counter = mode;
	}
	
	//	minimum step
	//		the minimum value that the circles can decrease by
	//		step is added to this value
	int minStep = 2;
	
	//	originally step was always 6, it's a good value to use
	step = (rand() % step) + minStep;
	
	while (radius > counter) {
		circle(backBuffer, centreX, centreY, radius, 
			makecol( red, green, blue));
		radius -= step;
		
		if (mode < 0) {	//	the original style
			counter++;
		}
	}

	return 0;
}


int main( int argc, char *argv[] )
{
	int w = 640, h = 480;
	int x, y, col, rad;
	
	srand(time(NULL));
	
	x = rand() % w;
	y = rand() % h;
	col = rand() % 256;	//	colour values go from 0 to 255
	rad = rand() % 700;
	rad = 100;
	drawXmasBall(x, y, rad, col, 0, 0, 6);
	return 0;
}
