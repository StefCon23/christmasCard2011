
#include <allegro.h>
#include <stdio.h>
//#include <conio.h>

BITMAP * backBuffer;

void drawXmas(float xa, float ya, float rada, int ra, int ga, int ba)
{
	//Merry xmas
	//'M'
	line( backBuffer, xa + (1 * rada), ya + (6 * rada), xa + (1 * rada), ya + (1 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (1 * rada), ya + (1 * rada), xa + (2.5 * rada), ya + (3 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (2.5 * rada), ya + (3 * rada), xa + (4 * rada), ya + (1 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (4 * rada), ya + (1 * rada), xa + (4 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	//'E'
	line( backBuffer, xa + (5 * rada), ya + (3 * rada), xa + (5 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (5 * rada), ya + (3 * rada), xa + (7 * rada), ya + (3 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (5 * rada), ya + (5 * rada), xa + (6 * rada), ya + (5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (5 * rada), ya + (6 * rada), xa + (7 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	//'R'
	line( backBuffer, xa + (8 * rada), ya + (3 * rada), xa + (8 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (8 * rada), ya + (3 * rada), xa + (10 * rada), ya + (3.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (8 * rada), ya + (5 * rada), xa + (10 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (10 * rada), ya + (3.5 * rada), xa + (10 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (8 * rada), ya + (5 * rada), xa + (9.5 * rada), ya + (5.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (9.5 * rada), ya + (5.5 * rada), xa + (10 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	//'R'
	line( backBuffer, xa + (11 * rada), ya + (3 * rada), xa + (11 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (11 * rada), ya + (3 * rada), xa + (13 * rada), ya + (3.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (11 * rada), ya + (5 * rada), xa + (13 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (13 * rada), ya + (3.5 * rada), xa + (13 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (11 * rada), ya + (5 * rada), xa + (12.5 * rada), ya + (5.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (12.5 * rada), ya + (5.5 * rada), xa + (13 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	//'Y'
	line( backBuffer, xa + (14 * rada), ya + (3 * rada), xa + (15 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (16 * rada), ya + (3 * rada), xa + (15 * rada), ya + (4.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (15 * rada), ya + (4.5 * rada), xa + (15 * rada), ya + (6 * rada), makecol(ra, ga, ba));
	//'X'
	line( backBuffer, xa + (1 * rada), ya + (7 * rada), xa + (7 * rada), ya + (12 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (1 * rada), ya + (12 * rada), xa + (7 * rada), ya + (7 * rada), makecol(ra, ga, ba));
	//'M'
	line( backBuffer, xa + (8 * rada), ya + (9 * rada), xa + (8 * rada), ya + (12 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (8 * rada), ya + (9 * rada), xa + (9 * rada), ya + (10.5 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (9 * rada), ya + (10.5 * rada), xa + (10 * rada), ya + (9 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (10 * rada), ya + (9 * rada), xa + (10 * rada), ya + (12 * rada), makecol(ra, ga, ba));
	//'A'
	line( backBuffer, xa + (11 * rada), ya + (12 * rada), xa + (12 * rada), ya + (9 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (13 * rada), ya + (12 * rada), xa + (12 * rada), ya + (9 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (11.5 * rada), ya + (11 * rada), xa + (12.5 * rada), ya + (11 * rada), makecol(ra, ga, ba));
	//'S'
	line( backBuffer, xa + (14 * rada), ya + (11 * rada), xa + (15 * rada), ya + (12 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (16 * rada), ya + (11 * rada), xa + (15 * rada), ya + (12 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (14 * rada), ya + (10 * rada), xa + (16 * rada), ya + (11 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (14 * rada), ya + (10 * rada), xa + (15 * rada), ya + (9 * rada), makecol(ra, ga, ba));
	line( backBuffer, xa + (16 * rada), ya + (10 * rada), xa + (15 * rada), ya + (9 * rada), makecol(ra, ga, ba));
}


void drawSnow(int xb, int yb, int radb, int rb, int gb, int bb)

{

	for(int qtyb= 0; qtyb<=1; qtyb++)
	{

		//switch between cross and diamond shaped snow
		int styleb1 = rand() % 100 + 1;
		bool styleb2;
		if(styleb1<76)
		{
			styleb2 = true;
		}
		else
		{
			styleb2 = false;
		}
		//coordinates
		float xb1;
		int xb2 = xb - (radb/2);
		int xb3 = xb;
		int xb4 = xb + (radb/2);
		float xb5;
		
		float yb1;
		int yb2 = yb - (radb/2);
		int yb3 = yb;
		int yb4 = yb + (radb/2);
		float yb5;

		switch(styleb2)
		{
		case true:
			xb1 = xb - radb;
			xb5 = xb + radb;

			yb1 = yb - radb;
			yb5 = yb + radb;

		case false:
			xb1 = xb - ((radb/4)*3);
			xb5 = xb + ((radb/4)*3);

			yb1 = yb - ((radb/4)*3);
			yb5 = yb + ((radb/4)*3);
		}

		//   |
		line(backBuffer, xb3, yb1, xb3, yb5, makecol(rb, gb, bb));
		//   /
		line(backBuffer, xb4, yb2, xb2, yb4, makecol(rb, gb, bb));
		//   -
		line(backBuffer, xb1, yb3, xb5, yb3, makecol(rb, gb, bb));
		//   '\'
		line(backBuffer, xb4, yb4, xb2, yb2, makecol(rb, gb, bb));
	
	}
}

void drawXmasballs( int xc, int yc, int radc, int rc, int gc, int bc)
{
	/********
	drawXmasballs
	draws circles of decreasing sized radius(es?)
	xc, yc      =  centre point
	radc        =  radius of outer (original) circle
	rc, gc, bc  =  colours
	spacec      =  decrease in size of circles(es) radius
	*/

	//circle outline
	//   i.e. circle at (xc, yc)
	//        with radius radc
	//        and coloured (rc, gc, bc)
	circle(backBuffer, xc, yc, radc, makecol(rc, gc, bc));
	//inner concentric circles
	//  radius - spacec = new circles radius
	int spacec = rand() % 6 + 2;

	for(float qtyc= 0; qtyc< (radc); qtyc++)
	{
		//if the current circles radius
		//  is greater than (and not equal to)
		//  the circle radius change (spacec)
		if(radc > spacec)
		{
			//decreasing radius
			radc -= spacec;
		}
		//new smaller circle
		circle(backBuffer, xc, yc, radc, makecol( rc, gc, bc));
	}

}

int main()
{
        if (allegro_init() != 0)
        {
			return 1;
        }
        set_color_depth(desktop_color_depth());
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
        {
			return 1;
        }
        backBuffer = create_bitmap(640, 480);
        
        install_keyboard();
        bool done = false;        
        while (! done)
        {
			 if (key[KEY_ESC])
                {
                        done = true;
                        break;                                
                }
                clear_to_color(backBuffer, makecol(0, 0, 0));

				int width = 640;
				int height = 480;
				
				//xmas colours red and green
				int rx = rand() % 256;
				int gx = rand() % 256;

				int x1 = rand() % 642 + 1;
				int y1 = rand() % 482 + 1;
				int rad1 = rand() % 700;
				int space1 = rand() % 5 + 2;

				int x2 = rand() % 642 + 1;
				int y2 = rand() % 482 + 1;
				int rad2 = rand() % 700;
				int space2 = 3;

				int x3 = rand() % 642 + 1;
				int y3 = rand() % 482 + 1;
				int rad3 = rand() % 700;
				int space3 = rand() % 5 + 2;
				

				drawXmasballs( x1, y1, rad1, rx, 0, 0);
				
				drawXmasballs( x2, y2, rad2, 0, gx, 0);
				
				drawXmasballs( x3, y3, rad3, rx, 0, 0);
				
				//snow
				
				int x4 = rand() % 642 + 1;
				int y4 = rand() % 482 + 1;
				int rad4 = rand() % 15 + 2;

				int x5 = rand() % 642 + 1;
				int y5 = rand() % 482 + 1;
				int rad5 = rand() % 10 + 2;

				int x6 = rand() % 642 + 1;
				int y6 = rand() % 482 + 1;
				int rad6 = rand() % 10 + 2;

				int x7 = rand() % 642 + 1;
				int y7 = rand() % 482 + 1;
				int rad7 = rand() % 5 + 2;

				drawSnow(x4, y4, rad4, 255, 255, 255);
				
				drawSnow(x5, y5, rad5, 255, 255, 255);

				drawSnow(x6, y6, rad6, 255, 255, 255);

				drawSnow(x7, y7, rad7, 255, 255, 255);
				

				//freeze
				if (key[KEY_Z])
                {

					int r8 = rand() % 256;
					int g8 = rand() % 256;
					int b8 = rand() % 256;

					for(int qty8= 0; qty8<= 10000000; qty8++)
					{
						int x8 = rand() % 642 + 1;
						int y8 = rand() % 482 + 1;
						putpixel(backBuffer, x8, y8, makecol(r8, g8, b8));
					}
				}
				if (key[KEY_Q])
				{

					//waving blue background
					int circles9 = 0;
					int x9 = rand() % 641;
					int y9 = rand() % 481;
					while(circles9<=2000)
					{
						int rad9 = rand() % 1000;
						int b9 = rand() % 256;
						circle(backBuffer, x9, y9 ,rad9, makecol(0, 0, b9));
						circles9++;
					}
					int circles10 = 0;
					int x10 = rand() % 641;
					int y10 = rand() % 481;
					while(circles10<=2000)
					{
						int rad10 = rand() % 1000;
						int b10 = rand() % 256;
						circle(backBuffer, x10, y10 ,rad10, makecol(0, 0, b10));
						circles10++;
					}

					//snow
					int x11 = rand() % 641;
					int y11 = rand() % 481;
					int rad11 = rand() % 3 + 1;
					drawSnow(x11, y11, rad11, 255, 255, 255);
					for(int qty11= 0; qty11<= x11; qty11++)
					{
						int x12 = rand() % 641;
						int y12 = rand() % 481;
						int rad12 = rand() % 5 + 1;
						drawSnow(x12, y12, rad12, 255, 255, 255);
					}

					//merry xmas
					int x13 = 65;
					int y13 = 45;
					while(x13<= 80)
					{
						int r13 = rand() % 256 + 100;
						int g13 = rand() % 256 + 100;
						drawXmas(x13, y13, 30, r13, g13, 0);
						x13+=2;
						y13+=1;
					}
				}

				//warm party theme
				//background
				if (key[KEY_A])
				{

					int x17 = (width/2) - 50;
					int y17 = (height/2);
					int rad17 = 0;

					int r17 = rand() % 256;
					int g17 = rand() % 256;
					while(rad17<=500)
					{
						circle(backBuffer, x17, y17, rad17, makecol(r17, g17, 0));
						for(int z17 = 0; z17 <= 20; z17++)
						{
							x17 + 2;
							y17 + 1;
						}
						rad17++;
					}					
				}

				//streamers
				if(key[KEY_S])
				{
					for(int x14= 0; x14< 100; x14++)
					{
						bool y14 = false;
						int z14 = rand() % 100;
						if (z14>50)
					    {
							y14 = true;
						}
						if (!y14)
						{
							int x15 = rand() % 641;
							int y15 = rand() % 481;
							int rad15 = rand() % 100;
							int col15 = rand() % 256 + 150;
							circle(backBuffer, x15, y15, rad15, makecol(col15, 0, 0));
						}
						else
						{
							int x16 = rand() % 641;
							int y16 = rand() % 481;
							int rad16 = rand() % 100;
							int col16 = rand() % 256 + 150;
							circle(backBuffer, x16, y16, rad16, makecol(0, col16, 0));
						}
					}
				}

                blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);

        }
}
END_OF_MAIN()


	/*
	**Christmas Card Assignment
	**C11443118 - DT211 - Computing - First Year
	**Bryan Duggan
	**
	**17/11/11
	**Conor Stefanini
	*/
