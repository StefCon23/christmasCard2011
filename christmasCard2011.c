#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>	//	allegro 4.4.2
#include <math.h>

/*
**	christmasCared2011.c
**
**
**
**	Conor Stefanini, 26 May 2015
**
**
*/

/*
**	functions
**		drawXmas			xmcc, 	cc2
**		drawXmasBalls			xmcc, 	cc2, 	ct
**		drawSnow			xmcc, 	cc2, 	ct
**		drawTrees			cc2
**		drawTrees2			cc2
**		drawSpots			ct
**		drawCars			ct
*/


BITMAP *backBuffer;

#define PI 3.1415

int drawXmasBall( int centreX, int centreY, int radius, int step,
	int red, int green, int blue )
{
	/*
	**	Draw Xmas ball
	**
	**	Draws a Christmas ball
	**
	**	Draws a circle with a centre point (centreX, centreY), 
	**		a radius described by "int radius", and 
	**		colouring described by (red, green, blue)
	**	Then draws circles of decreasing radius within that 
	**		circle, the radius decreases by 
	**
	**	int centreX	==	x point for centre of circle
	**	int centreY	==	y point for centre of circle
	**	int radius	==	radius of circle
	**	int step	==	how much the circle decreases by
	**					at each step
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
	circle(backBuffer, centreX, centreY, radius, 
		makecol(red, green, blue));
	//inner concentric circles
	//  radius - spacec = new circles radius
	int spacec = rand() % 6 + 2;

	float qtyc;
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
		circle(backBuffer, centreX, centreY, radius, makecol( 
			red, green, blue));
	}
	*/

	//	mode
	//		originally the radius decreased to about a 
	//			third of the original size and no 
	//			further
	//		another option is to decrease to a fixed size
	//		a minus value for mode represents the original
	//			version, any other value is the radius
	//			the circle decreases to
	int mode = -1;
	
	//	counter
	//		used for mode 0
	int counter = 0;
	if (mode >= 0) {	//	new style
		counter = mode;
	}
	
	//	minimum step
	//		the minimum value that the circles can decrease
	//		by step is added to this value
	int minStep = 2;
	//int minStep = 80;
	//int minStep = (rand() % 10) + 2;
	
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


void drawSnowFlake( int x, int y, int radius, 
	int red, int green, int blue )
{
	/*
	**	Draw Snow Flake
	**
	**	draws a snow flake at (x, y) of size "radius" and 
	**		coloured with (red, green, blue)
	**	there's a 75 per cent chance of getting a more diamond 
	**		shaped snow flake and a 25 per cent chance of a
	**		more cross shaped one
	**
	**	int x		==	x point of centre of snow flake
	**	int y		==	y point of centre of snow flake
	**	int radius	==	radius of snow flake
	**	int red		==	red value for colour of snow 
	**					flake
	**	int green	==	green value for colour of snow 
	**					flake
	**	int blue	==	blue value for colour of snow 
	**					flake
	*/
	
	
	int diCr;	//	diamond or cross style snow flakes
	
	int i;
	for (i = 0; i < 2; ++i) {
	
		if ((rand() % 4) != 3) {
			diCr = 1;
		} else {
			diCr = 0;
		}
		
		//	|
		line(backBuffer, x, (y - (radius * (diCr ? 0.75 : 1))),
			x, (y + (radius * (diCr ? 0.75 : 1))),
			makecol(red, green, blue));
		//	/
		line(backBuffer, (x + (radius / 2)), (y - (radius / 2)),
			(x - (radius / 2)), (y + (radius / 2)),
			makecol(red, green, blue));
		//	-
		line(backBuffer, (x - (radius * (diCr ? 0.75 : 1))), y,
			(x + (radius * (diCr ? 0.75 : 1))), y,
			makecol(red, green, blue));
		//	\'
		line(backBuffer, (x + (radius / 2)), (y + (radius / 2)),
			(x - (radius / 2)), (y - (radius / 2)),
			makecol(red, green, blue));
	}
}


int drawXmas( int x, int y, int size, int red, int green, int blue )
{
	/*
	**	Merry X-Mas
	**
	**	Writes "MERRY XMAS" with lines
	**	Writes it at (x, y), at a size defined by 'size', 
	**		and colouring defined by (red, green, blue)
	**
	**	The 'M' of Merry starts at (x + size, y + size)
	**
	**	int x		==	x point of top left of "MERRY 
	**					XMAS"
	**	int y		==	y point of top left of "MERRY 
	**					XMAS"
	**	int size	==	size of "MERRY XMAS" (not exact 
	**					match with pixels)
	**	int red		==	red value for colour of "MERRY 
	**					XMAS"
	**	int green	==	red value for colour of "MERRY 
	**					XMAS"
	**	int blue	==	red value for colour of "MERRY 
	**					XMAS"
	*/
	
	//	'M'
	line(backBuffer, x + size, y + (6 * size), 
		x + size, y + size, 
		makecol(red, green, blue));
	line(backBuffer, x + size, y + size, 
		x + (2.5 * size), y + (3 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (2.5 * size), y + (3 * size), 
		x + (4 * size), y + size, 
		makecol(red, green, blue));
	line(backBuffer, x + (4 * size), y + size, 
		x + (4 * size), y + (6 * size), 
		makecol(red, green, blue));
	//	'E'
	line(backBuffer, x + (5 * size), y + (3 * size), 
		x + (5 * size), y + (6 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (5 * size), y + (3 * size), 
		x + (7 * size), y + (3 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (5 * size), y + (5 * size), 
		x + (6 * size), y + (5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (5 * size), y + (6 * size), 
		x + (7 * size), y + (6 * size), 
		makecol(red, green, blue));
	//	'R'
	line(backBuffer, x + (8 * size), y + (3 * size), 
		x + (8 * size), y + (6 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (8 * size), y + (3 * size), 
		x + (10 * size), y + (3.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (8 * size), y + (5 * size), 
		x + (10 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (10 * size), y + (3.5 * size), 
		x + (10 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (8 * size), y + (5 * size), 
		x + (9.5 * size), y + (5.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (9.5 * size), y + (5.5 * size), 
		x + (10 * size), y + (6 * size), 
		makecol(red, green, blue));
	//	'R'
	line(backBuffer, x + (11 * size), y + (3 * size), 
		x + (11 * size), y + (6 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (11 * size), y + (3 * size), 
		x + (13 * size), y + (3.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (11 * size), y + (5 * size), 
		x + (13 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (13 * size), y + (3.5 * size), 
		x + (13 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (11 * size), y + (5 * size), 
		x + (12.5 * size), y + (5.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (12.5 * size), y + (5.5 * size), 
		x + (13 * size), y + (6 * size), 
		makecol(red, green, blue));
	//	'Y'
	line(backBuffer, x + (14 * size), y + (3 * size), 
		x + (15 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (16 * size), y + (3 * size), 
		x + (15 * size), y + (4.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (15 * size), y + (4.5 * size), 
		x + (15 * size), y + (6 * size), 
		makecol(red, green, blue));

	//	'X'
	line(backBuffer, x + size, y + (7 * size), 
		x + (7 * size), y + (12 * size), 
		makecol(red, green, blue));
	line( backBuffer, x + size, y + (12 * size), 
		x + (7 * size), y + (7 * size), 
		makecol(red, green, blue));
	//	'M'
	line(backBuffer, x + (8 * size), y + (9 * size), 
		x + (8 * size), y + (12 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (8 * size), y + (9 * size), 
		x + (9 * size), y + (10.5 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (9 * size), y + (10.5 * size), 
		x + (10 * size), y + (9 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (10 * size), y + (9 * size), 
		x + (10 * size), y + (12 * size), 
		makecol(red, green, blue));
	//	'A'
	line(backBuffer, x + (11 * size), y + (12 * size), 
		x + (12 * size), y + (9 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (13 * size), y + (12 * size), 
		x + (12 * size), y + (9 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (11.5 * size), y + (11 * size), 
		x + (12.5 * size), y + (11 * size), 
		makecol(red, green, blue));
	//	'S'
	line(backBuffer, x + (14 * size), y + (11 * size), 
		x + (15 * size), y + (12 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (16 * size), y + (11 * size), 
		x + (15 * size), y + (12 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (14 * size), y + (10 * size), 
		x + (16 * size), y + (11 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (14 * size), y + (10 * size), 
		x + (15 * size), y + (9 * size), 
		makecol(red, green, blue));
	line(backBuffer, x + (16 * size), y + (10 * size), 
		x + (15 * size), y + (9 * size), 
		makecol(red, green, blue));
	
	return 0;
}

int trimCol( int colourValue )
{
	/*
	**	trim colour
	**
	**	this function is used to keep numbers between 0, and 255
	**	values from 0 to 255 are used as red, green, or blue 
	**		values to make colours
	**	this function is mostly used by the drawTree function 
	**		below
	**	the function takes in the possible colour value, and 
	**		returns the new appropriate colour value
	**
	**	the function checks if the passed number is below zero 
	**		or above 255, if it is below zero, for example 
	**		'-50' then the new colour is 205 (-50 + 255, or 
	**		255 - 50), if the number is above 255, for 
	**		example 300, then the new number is 45, 
	**		(300 - 255)	
	**	it also works for ridiculously big numbers (just in 
	**		case)
	*/
	
	if (colourValue > 255) {
		colourValue = colourValue % 255;
	} else if (colourValue < 0) {
		while (colourValue < 0) {
			colourValue += 255;
		}
	}
	return colourValue;
}


int drawTree( int x, int y, int radius, int red, int green, int blue )
{
	/*
	**	Draw Tree
	**
	**	Draws a Christmas Tree at (x, y) of size 'size' and 
	**		colouring (red, green, blue)
	**	The tree is drawn with two triangles (for the 
	**		leaves / top) and a rectangle for the trunk
	**	The colouring is a bit weird, basically, if a dark green
	**		(34, 139, 34) is passed through (red, green, 
	**		blue), then the resulting trunk colour is brown
	*/
	
	//	the trunk colours are odd, if the passed (red, green, 
	//		blue) are (34, 139, 34) (dark green), then the 
	//		trunk is brown
	//	trimCol makes sure the numbers are between 0, and 255
	int trunkRed = trimCol(red + 105);
	int trunkGreen = trimCol(green - 70);
	int trunkBlue = trimCol(blue - 15);

	//	top triangle / leaves
	triangle(backBuffer, x, y - (radius / 4), 
		x - (radius / 4), y + (radius / 8), 
		x + (radius / 4), y + (radius / 8), 
		makecol(red, green, blue));
	//	mid triangle / leaves
	triangle(backBuffer, x, y, 
		//	wider leaves
		//x - (radius / (2 + (2/3))), y + (radius / 2), 
		//	tighter leaves
		x - ((3 * radius) / 8), y + (radius / 2), 
		//	wider leaves
		//x + (radius / (2 + (2/3))), y + (radius / 2), 
		//	tighter leaves
		x + ((3 * radius) / 8), y + (radius / 2), 
		makecol(red, green, blue));
	//	trunk
	rectfill(backBuffer, x - (radius / 16), y + (radius / 2) + 1, 
		x + (radius / 16), y + ((2 * radius) / 3), 
		//	longer tree trunk (unrealistically long)
		//x + (radius / 16), y + (radius / (1 + (1 / 2))), 
		makecol(trunkRed, trunkGreen, trunkBlue));
	
	return 0;
}


int drawCar( int x, int y, int red, int green, int blue )
{
	/*
	**	draws a little car
	**
	**	not very christmassy
	*/
	
	line(backBuffer, (x), (y + 7), (x + 50), (y + 7), 
		makecol(red, green, blue));
	line(backBuffer, (x), (y + 7), (x), (y + 15), 
		makecol(red, green, blue));
	line(backBuffer, (x), (y + 15), (x + 50), (y + 15), 
		makecol(red, green, blue));
	line(backBuffer, (x + 50), (y + 15), (x + 50), (y + 7), 
		makecol(red, green, blue));
	line(backBuffer, (x + 30), (y + 7), (x + 30), (y), 
		makecol(red, green, blue));
	line(backBuffer, (x + 30), (y), (x + 35), (y + 7), 
		makecol(red, green, blue));
	//	wheels
	circle(backBuffer, (x + 10), (y + 15), 5, 
		makecol(red, green, blue));
	circle(backBuffer, (x + 35), (y + 15), 5, 
		makecol(red, green, blue));
	
	return 0;
}








int main( int argc, char *argv[] )
{

	/*
	**	Variables
	**		The main variables used in the program
	*/
	
	//	screen width and height
	int w = 640;
	int h = 480;
	
	int col;	//	colour value for xmas balls
	int rad;	//	radius value for xmas balls
	int x;		//	centre point x value for xmas balls
	int y;		//	centre point y value for xmas balls
	
	int r;		//	used for random colours
	int g;		//		red, green, and blue values
	int b;
	
	int i, j;	//	counters
	
	float angle = 0;
	
	int mode = 3;	//	mode for running (will be explained
			//		later)
	
	int keyFlag = 0;//	for keyboard pressing (one instance)
	
	
	
	/*
	**	Allegro Set Up
	*/
	
	//	initialise allegro, ends program if unsuccessful
	if (allegro_init()) {
		fprintf(stderr, "Couldn't initialise Allegro\n"
			"Check that Allegro 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	
	
	//	pixel format to be used
	set_color_depth(desktop_color_depth());
	
	//	set graphics / screen style (windowed, or fullscreen)
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0)) {
		fprintf(stderr, "Couldn't set graphics mode\n"
			"Check that Allegro 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	//	create the back buffer
	//		the back buffer is a bitmap image
	//		all graphics get written to the back buffer, and
	//			then on to the screen, this avoids 
	//			flickering
	backBuffer = create_bitmap(w, h);

	//	set up the keyboared
	if (install_keyboard()) {
		fprintf(stderr, "Couldn't install the keyboared\n"
			"Check that Allegro 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	//	random seed bluesed on time
	srand(time(NULL));
	
	
	//	main loop
	while (1) {
	
		//	end game if the escape key or q key is pressed
		if ((key[KEY_ESC]) || (key[KEY_Q])) {
			break;
		}
		
		//	set the background colour to black each frame,
		//		the screen gets written at the end of
		//		the loop, each frame
		clear_to_color(backBuffer, makecol(0, 0, 0));
		
		
		//	idea for feature implementation
		//		treat it like a binary interpretation of
		//		a decimal, like chmod settings, i.e.:
		//		0000 0 	==	nothing
		//		0001 1	==	xmas balls
		//		0011 3	==	xmas balls and snow
		//		0111 7	==	xmas balls, snow, XMAS
		//					string
		//		0101 5	==	xmas balls and XMAS 
		//					string
		
		
		//	cars	land	trees	XMAS	snow	balls
		//	c	l	t	x	s	b
		//	0	0	0	0	0	0
		//	000000
		
		//	000000	0	==	nothing
		//	000001	1	==	b
		//	000010	2	==	s
		//	000011	3	==	sb
		//	000100	4	==	x
		//	000101	5	==	xb
		//	000110	6	==	xs
		//	000111	7	==	xsb
		//	001000	8	==	
		//	001001	9	==	
		//	001010	10	==	
		//	001011	11	==	
		//	001100	12	==	
		//	001101	13	==	
		//	001110	14	==	
		//	001111	15	==	
		//	010000	16	==	
		//	010001	17	==	
		//	010010	18	==	
		//	010011	19	==	
		//	010100	20	==	
		//	010101	21	==	
		//	010110	22	==	
		//	010111	23	==	
		//	011000	24	==	
		//	011001	25	==	
		//	011010	26	==	
		//	011011	27	==	
		
		/*
		**	FEATURES LIST
		**		Xmas Balls 	3 blue, and green balls
		**		
		**		Snow big	4 snowflakes of varying 
		**					size
		**		Snow small	smaller snowflakes for
		**					landscape
		**		XMAS big	big version of MERRY 
		**					XMAS string
		**		XMAS small	mini version for 
		**					landscape shot
		**		Trees small	small trees on the land-
		**					scape
		**		Blue sky	2 big blue balls
		**
		**		Land		white rectangle on 
		**					bottom
		**		Cars		to be configured
		*/
		
		if (mode & 1) {
			/*
			**	Christmas balls
			*/
			
			x = rand() % w;
			y = rand() % h;
			//	colour values go from 0 to 255
			col = rand() % 256;
			rad = rand() % 700;
			drawXmasBall(x, y, rad, 6, col, 0, 0);
			
			x = rand() % w;
			y = rand() % h;
			col = rand() % 256;
			rad = rand() % 700;
			drawXmasBall(x, y, rad, 6, 0, col, 0);
			
			//	the original did 3
			x = rand() % w;
			y = rand() % h;
			col = rand() % 256;
			rad = rand() % 700;
			drawXmasBall(x, y, rad, 6, col, 0, 0);
		}
		
		if (mode & 2) {
			/*
			**	Snow (Big)
			*/
			
			x = rand() % w;
			y = rand() % h;
			//	value for rad taken from original source
			//		code
			rad = (rand() % 15) + 2;	
			drawSnowFlake(x, y, rad, 255, 255, 255);
			
			x = rand() % w;
			y = rand() % h;
			//	value for rad taken from original source
			//		code
			rad = (rand() % 10) + 2;
			drawSnowFlake(x, y, rad, 255, 255, 255);
			
			x = rand() % w;
			y = rand() % h;
			//	value for rad taken from original source
			//		code
			rad = (rand() % 10) + 2;
			drawSnowFlake(x, y, rad, 255, 255, 255);
			
			x = rand() % w;
			y = rand() % h;
			rad = (rand() % 5) + 2;
			drawSnowFlake(x, y, rad, 255, 255, 255);
		}
		
		if (mode & 4) {
			/*
			**	XMAS String (big)
			*/
			
			x = w / 2;
			y = h / 2;
			rad = 100;
			r = rand() % 256;
			g = rand() % 256;
			b = rand() % 256;
			drawXmas(x, y, rad, r, g, b);
		}
		
		if (mode & 8) {
			/*
			**	Blue Sky
			*/
		}
		
		if (mode & 16) {
			/*
			**	Land
			*/

			rectfill(backBuffer, 0, 300, w, h, 
				makecol(255, 255, 255));
		}
		
		if (mode & 32) {
			/*
			**	Snow (Small)
			*/
			
			int randx = rand() % 641;
			int randy = rand() % 481;
			int randrad = rand() % 3 + 1;
			drawSnowFlake(randx, randy, randrad, 255, 255, 255);
			int i = 0;

			while(i<=randx)
			{
				int randx1 = rand() % 641;
				int randy1 = rand() % 481;
				int randrad1 = rand() % 3 + 1;
				drawSnowFlake(randx1, randy1, randrad1, 255, 255, 255);
				i++;
			}
		}
		
		
		if (mode & 64) {
			/*
			**	XMAS String (Small)
			*/
		}
		
		if (mode & 128) {
			/*
			**	Trees (Small)
			*/
		}
		
		if (mode & 256) {
			/*
			**	Cars
			*/
		}

		
		/*
		**	Input Keys
		*/
		
		//	freeze screen
		if (key[KEY_Z]) {
			//col = rand() % 256;
			r = rand() % 256;
			g = rand() % 256;
			b = rand() % 256;
			for (i = 0; i <= 10000000; ++i) {
				x = rand() % w;
				y = rand() % h;
				putpixel(backBuffer, x, y,
					//makecol(col, col, col));
					makecol(r, g, b));
			}
		}
		
		//	blue sky (2 big blue balls)
		if (key[KEY_A]) {
			for (i = 0; i < 2; ++i) {
				x = rand() % w;
				y = rand() % h;
				//	big radius to cover the whole 
				//		screen
				rad = rand() % 1000;
				//	fill circles right down to 
				//		centre, 2000 from 
				//		original program
				for (j = 0; j < 2000; ++j) {
					//	random blue values, 
					//		gives a darker 
					//		overall colour
					rad = rand() % 1000;
					b = rand() % 256;
					//	circles of decreasing 
					//		radius
					circle(backBuffer, x, y, rad, 
						makecol(0, 0, b));
				}
			}
		}
		
		//	big MERRY XMAS
		if (key[KEY_S]) {
			x = 50;
			y = 50;
			rad = 30;	//	31?
			int bigRad = 20;
			float endX = cos(angle);
			float endY = sin(angle);
			i = 0;
			while (i <= bigRad) {
				r = rand() % 256;
				g = rand() % 256;
				b = rand() % 256;
				drawXmas(x, y, rad, r, g, b);
				x += endX;
				y += endY;
				
				i++;
				
			}
			
			if (angle < 2 * PI) {
				angle += 0.05;
			} else {
				angle = 0;
			}
		}
		
		
		if (key[KEY_MINUS]) {
			if ((mode > 0) && (!keyFlag)) {
				keyFlag = 1;
				mode--;
			}
		}
		if (key[KEY_EQUALS]) {
			if (!keyFlag) {
				keyFlag = 1;
				mode++;
			}
		}
		
		if ((!key[KEY_MINUS]) && (!key[KEY_EQUALS])) {
			keyFlag = 0;
		}
		
		
		//	debug
		textprintf_centre_ex(backBuffer, font, 
			w / 2, h / 2, makecol(255, 255, 255), 
			-1, "mode %d", mode);
		
		
		//	writes the back buffer to the screen
		blit(backBuffer, screen, 0, 0, 0, 0, w, h);
	}
	
	free(backBuffer);
	
	return EXIT_SUCCESS;
}
//	end allegro
END_OF_MAIN()
