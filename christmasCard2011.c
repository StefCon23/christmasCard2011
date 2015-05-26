#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>	//	allegro 4.4.2

/*
**	christmasCard2011.c
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
**		drawXmasBalls		xmcc, 	cc2, 	ct
**		drawSnow			xmcc, 	cc2, 	ct
**		drawTrees			cc2
**		drawTrees2			cc2
**		drawSpots			ct
*/


BITMAP *backBuffer;


int drawXmasBall( int centreX, int centreY, int radius, int step,
	int red, int green, int blue )
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
	**	int step	==	how much the circle decreases by at
	**					each step
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
	circle(backBuffer, centreX, centreY, radius, makecol(red, green, blue));
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
		circle(backBuffer, centreX, centreY, radius, makecol( red, green, blue));
	}
	*/

	//	mode
	//		originally the radius decreased to about a third of
	//			the original size and no further
	//		another option is to decrease to a fixed size
	//		a minus value for mode represents the original
	//			version, any other value is the radius the
	//			circle decreases to
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


void drawSnowFlake(int x, int y, int radius, 
	int red, int green, int blue)
{
	/*
	**	Draw Snow Flake
	**
	**	draws a snow flake at (x, y) of size "radius" and coloured
	**		with (red, green, blue)
	**	there's a 75 per cent chance of getting a more diamond shaped
	**		snow flake and a 25 per cent chance of a more cross
	**		shaped one
	**
	**	int x		==	x point of centre of snow flake
	**	int y		==	y point of centre of snow flake
	**	int radius	==	radius of snow flake
	**	int red		==	red value for colour of snow flake
	**	int green	==	green value for colour of snow flake
	**	int blue	==	blue value for colour of snow flake
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




int main( int argc, char *argv[] )
{

	/*
	**	Variables
	**		The main variables used in the program
	*/
	
	int col;	//	colour value for xmas balls
	int rad;	//	radius value for xmas balls
	int x;		//	centre point x value for xmas balls
	int y;		//	centre point y value for xmas balls
	
	int r;		//	used for random colours
	int g;		//		red, green, and blue values
	int b;
	
	int i;		//	counter
	
	
	
	/*
	**	Allegro Set Up
	*/
	
	//	initialise allegro, ends program if unsuccessful
	if (allegro_init()) {
		fprintf(stderr, "Couldn't initialise Allegro\n"
			"Check that Allegro version 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	//	screen width and height
	int w = 640;
	int h = 480;
	
	//	pixel format to be used
	set_color_depth(desktop_color_depth());
	
	//	set graphics / screen style (windowed, or fullscreen)
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, w, h, 0, 0)) {
		fprintf(stderr, "Couldn't set graphics mode\n"
			"Check that Allegro version 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	//	create the back buffer
	//		the back buffer is a bitmap image
	//		all graphics get written to the back buffer, and then
	//			on to the screen, this avoids flickering
	backBuffer = create_bitmap(w, h);

	//	set up the keyboard
	if (install_keyboard()) {
		fprintf(stderr, "Couldn't install the keyboard\n"
			"Check that Allegro version 4.4.2 is installed\n");
		return EXIT_FAILURE;
	}
	
	//	random seed based on time
	srand(time(NULL));
	
	
	//	main loop
	while (1) {
	
		//	end game if the escape key or q key is pressed
		if ((key[KEY_ESC]) || (key[KEY_Q])) {
			break;
		}
		
		//	set the background colour to black each frame,
		//		the screen gets written at the end of the
		//		loop, each frame
		clear_to_color(backBuffer, makecol(0, 0, 0));
		
		
		//	Christmas Balls
		x = rand() % w;
		y = rand() % h;
		col = rand() % 256;	//	colour values go from 0 to 255
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
		
		//	Snow
		x = rand() % w;
		y = rand() % h;
		rad = (rand() % 15) + 2;	//	original rad value
		drawSnowFlake(x, y, rad, 255, 255, 255);
		x = rand() % w;
		y = rand() % h;
		rad = (rand() % 10) + 2;	//	original rad value
		drawSnowFlake(x, y, rad, 255, 255, 255);
		x = rand() % w;
		y = rand() % h;
		rad = (rand() % 10) + 2;	//	original rad value
		drawSnowFlake(x, y, rad, 255, 255, 255);
		x = rand() % w;
		y = rand() % h;
		rad = (rand() % 5) + 2;		//	original rad value
		drawSnowFlake(x, y, rad, 255, 255, 255);

		
		/*
		**	input keys
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
		
		
		
		
		
		//	writes the back buffer to the screen
		blit(backBuffer, screen, 0, 0, 0, 0, w, h);
	}
	
	free(backBuffer);
	
	return EXIT_SUCCESS;
}
//	end allegro
END_OF_MAIN()
