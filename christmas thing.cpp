
#include <allegro.h>
#include <stdio.h>
BITMAP * backBuffer;
// Create your function here!!
//
void drawCars(int xc, int yc, int rc, int gc, int bc)
{
	line(backBuffer, (xc), (yc + 7), (xc + 50), (yc + 7), makecol(rc, gc, bc));
	line(backBuffer, (xc), (yc + 7), (xc), (yc + 15), makecol(rc, gc, bc));
	line(backBuffer, (xc), (yc + 15), (xc + 50), (yc + 15), makecol(rc, gc, bc));
	line(backBuffer, (xc + 50), (yc + 15), (xc + 50), (yc + 7), makecol(rc, gc, bc));
	line(backBuffer, (xc + 30), (yc + 7), (xc + 30), (yc), makecol(rc, gc, bc));
	line(backBuffer, (xc + 30), (yc), (xc + 35), (yc + 7), makecol(rc, gc, bc));

	circle(backBuffer, (xc + 10), (yc + 15), 5, makecol(rc, gc, bc));
	circle(backBuffer, (xc + 35), (yc + 15), 5, makecol(rc, gc, bc));
}
void drawSpots(int xs1, int ys1, int amounts, int rs, int gs, int bs)
{
	int tickers = 0;
	while(tickers<=amounts)
	{
	putpixel(backBuffer, xs1, ys1, makecol(rs, gs, bs));
	tickers+=1;
	}
}
void drawSnow(int xl, int yl, int radl, int amount, int rl, int gl, int bl)
//radl is 1/2 length of lines
{
	int ticker = 0;
	while(ticker<=amount)
	{
	int xl1 = xl - radl;
	int xl2 = xl - (radl/2);
	int xl3 = xl;
	int xl4 = xl + (radl/2);
	int xl5 = xl + radl;
	
	int yl1 = yl - radl;
	int yl2 = yl - (radl/2);
	int yl3 = yl;
	int yl4 = yl + (radl/2);
	int yl5 = yl + radl;

	line(backBuffer, xl3, yl1, xl3, yl5, makecol(rl, gl, bl));
	line(backBuffer, xl4, yl2, xl2, yl4, makecol(rl, gl, bl));
	line(backBuffer, xl1, yl3, xl5, yl3, makecol(rl, gl, bl));
	line(backBuffer, xl4, yl4, xl2, yl2, makecol(rl, gl, bl));
	ticker += 1;
	}
}

void drawXmasballs( float xb, float yb, float radb, int rb, int gb, int bb)
{
	//xb, yb centre point of large circle, radb radius, random colours
	circle(backBuffer, xb, yb, radb, makecol(rb, gb, bb));
	float circles = 0;
	//inner concentric circles
	while (circles<= radb)
	{
		circles += 1;
		if(radb > 3)
		{
			radb -= 3;
		}
		circle(backBuffer, xb, yb, radb, makecol( rb, gb, bb));
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
                // Call your function from here!!
				
				//xmas colours red and green
				int rx = rand() % 256;
				int gx = rand() % 256;
				int bx = 0;
				int r1 = rand() % 256;
				int g1 = rand() % 256;
				int b1 = rand() % 256;
				int x1 = rand() % 642 + 1;
				int y1 = rand() % 482 + 1;
				int x2 = rand() % 642 + 1;
				int y2 = rand() % 482 + 1;
				int x7 = rand() % 700;
				int y7 = rand() % 700;
				drawXmasballs( x1, y1, x7, rx, 0, 0);
				drawXmasballs( x2, y2, y7, 0, gx, 0);
				drawXmasballs( x1, y2, x7, rx, 0, bx);
				
				int x3 = rand() % 641;
				int y3 = rand() % 481;
				int xtits = rand() % 641;
				int ytits = rand() % 481;
				int xpoo = rand() % 641;
				int ypoo = rand() % 481;
				int x4 = rand() % 641;
				int y4 = rand() % 481;
				int x8 = rand() % 20;
				int y8 = rand() % 20;
				drawSnow(x3, y3, x8, y8, 255, 255, 255);
				drawSnow(xtits, ytits, 3, 0, 255, 255, 255);
				drawSnow(xpoo, ypoo, 3, 5, 255, 255, 255);
				drawSnow(xtits, y3, 3, 5, 255, 255, 255);
				
				int x5 = rand() % 641;
				int y5 = rand() % 481;
				int x6 = rand() % 641;
				int y6 = rand() % 481;
				int rs = rand() % 256;
				int gs = rand() % 256;
				int bs = rand() % 256;
				drawSpots(x5, y5, x6, rs, gs, bs);
				drawSpots(x6, y6, x5, rs, gs, bs);

				int circles = 0;
					while(circles<=50)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int x2 = rand() % 500;
						int y2 = rand() % 481;
						int rad = rand() % 500;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x2, x2 ,rad, makecol(r, 0, b));
						circles+=1;
						/*using same random value for x and y gives cool
						*lens flare kinda effect
						*straight line of circles
						*study mathematical functions to give different patterns?
						*/
					}
					int circles2 = 0;
					while(circles2<=20)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int x2 = rand() % 500;
						int y2 = rand() % 481;
						int rad = rand() % 500;
						int r = rand() % 100;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 0, x2 ,rad, makecol(r, g, 0));
						circles2+=1;
					}


				if (key[KEY_A])
                {
					int pixels = 0;
					while(pixels<=5000000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						putpixel(backBuffer, x, y, makecol(r, g, b));
						pixels+=1;
					}
                }
				if (key[KEY_S])
                {
					int pixels = 0;
					while(pixels<=50000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						putpixel(backBuffer, x, y, makecol(r, g, b));
						pixels+=1;
					}
                }
				if (key[KEY_D])
                {
					int lines = 0;
					while(lines<=50)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(r, g, b));
						lines+=1;
					}
                }
				if (key[KEY_F])
                {
					int lines = 0;
					while(lines<=50)
					{
						int x1;
						int y1;
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 0, y, 640, y, makecol(0, 0, b));
						lines+=1;
					}
                }
				if (key[KEY_G])
                {
					int circles = 0;
					while(circles<=1000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x, y ,rad, makecol(r, g, b));
						circles+=1;
					}
                }
				if (key[KEY_H])
                {
					int circles = 0;
					while(circles<=1000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 320, 240 ,rad, makecol(r, g, b));
						circles+=1;
					}
                }
				if (key[KEY_Z])
                {
					int lines = 0;
					while(lines<=1000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 320, 240, x, 480, makecol(r, g, b));
						lines+=1;
					}
                }
				if (key[KEY_X])
                {
					int lines = 0;
					while(lines<=250)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 320, 240, x, 480, makecol(0, 255, 0));
						lines+=1;
					}
                }
				if (key[KEY_C])
                {
					int lines = 0;
					while(lines<=5000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(r, g, b));
						lines+=1;
					}
                }
				if (key[KEY_V])
                {
					int lines = 0;
					while(lines<=1000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 641;
						int y = rand() % 481;
						int r = rand() % 256;
						int g = rand() % 150;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(r, g, 0));
						lines+=1;
					}
                }
				if (key[KEY_B])
                {
					int circles = 0;
					while(circles<=1000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 300, 100 ,rad, makecol(r, g, b));
						circles+=1;
					}
                }
				if (key[KEY_N])
                {
					int words = 0;
					while(words<=1)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						printf("MERRYCHRISTMAS");
						words+=1;
					}
                }
				if (key[KEY_M])
                {
					int cars = 0;
					while(cars<=1)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						drawCars(x, y , r, g, b);
						cars+=1;
					}
                }
				if (key[KEY_J])
                {
					int cars = 0;
					while(cars<=500)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						drawCars(x, y , r, g, b);
						cars+=1;
					}
                }
				if (key[KEY_K])
                {
					int circles = 0;
					while(circles<=1000)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 320, 240 ,rad, makecol(0, g, b));
						circles+=1;
					}
                }
				if (key[KEY_L])
                {
					int circles = 0;
					while(circles<=200)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 120, 40 ,rad, makecol(165, 165, 0));
						circles+=1;
					}
                }
				if (key[KEY_P])
                {
					float y = 340;
					int lines = 0;
					while(lines<=500)
					{
						int x = rand() % 641;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 0, y, 360000, y, makecol(0, r, 0));
						lines+=1;
						y+=1;
					}
                }
				if (key[KEY_O])
                {
					
					int pixels = 0;
					while(pixels<=50000)
					{
						int y = rand() % 450;
						int x = rand() % 641;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						putpixel(backBuffer, x, y ,makecol(255, 255, b));
						pixels+=1;
						y+=1;
					}
                }
				if (key[KEY_Q])
                {
					int circles1 = 0;
					int x1 = rand() % 641;
					int y1 = rand() % 481;
					while(circles1<=2000)
					{
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x1, y1 ,rad, makecol(0, 0, b));
						circles1+=1;
					}
					int circles2 = 0;
					int x2 = rand() % 641;
					int y2 = rand() % 481;
					while(circles2<=2000)
					{
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x2, y2 ,rad, makecol(0, 0, b));
						circles2+=1;
					}
                }
				if (key[KEY_W])
                {
					int circles = 0;
					while(circles<=200)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 50;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 120, 40 ,rad, makecol(255, 255, 255));
						circles+=1;
					}
                }
				if (key[KEY_E])
                {
					float y = 400;
					int lines = 0;
					while(lines<=500)
					{
						int x = rand() % 641;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 0, y, 360000, y, makecol(r, 255, 255));
						lines+=1;
						y+=1;
					}
					int lines2 = 0;
					while(lines2<=500)
					{
						int xr1 = rand() % 700;
						int xr2 = xr1 - 60;
						int yr1 = 400;
						int yr2 = 480;
						int b = rand() % 256;
						line(backBuffer, xr1, yr1, xr2, yr2, makecol(0, 0, b));
						lines2+=1;
					}
                }
				if (key[KEY_R])
                {
					float y = 400;
					int stars = 0;
					while(stars<=500)
					{
						int x = rand() % 720;
						int y = rand() % 400;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						drawSnow(x, y, 3, 1, 255, 255, 255);
						stars+=1;
						y+=1;
					}
                }
				if (key[KEY_T])
                {
					int lines2 = 0;
					while(lines2<=10000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 1500 + (-500);
						int y = rand() % 1200 + (-200);
						int r = rand() % 100;
						int g = rand() % 150;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(r, g, 255));
						lines2+=1;
					}
                }
				if (key[KEY_Y])
                {
					int circles = 0;
					while(circles<=100)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000 + 100;
						int r = rand() % 100;
						int g = rand() % 256;
						int b = rand() % 100;
						circle(backBuffer, 320, 240 ,rad, makecol(r, 255, b));
						circles+=1;
					}
                }
				if (key[KEY_U])
                {
					int lines = 0;
					while(lines<=1000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 321 + 160;
						int y = 480;
						int r = rand() % 100;
						int g = rand() % 50;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(255, g, r));
						lines+=1;
					}
                }

				//  compilation buttons
				if(key[KEY_I])
				{
					//key t
					int lines2 = 0;
					while(lines2<=10000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 1500 + (-500);
						int y = rand() % 1200 + (-200);
						int r = rand() % 100;
						int g = rand() % 150;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(r, g, 255));
						lines2+=1;
					}
					//key y
					int circles = 0;
					while(circles<=100)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 1000 + 100;
						int r = rand() % 100;
						int g = rand() % 256;
						int b = rand() % 100;
						circle(backBuffer, 320, 240 ,rad, makecol(r, 255, b));
						circles+=1;
					}
					//key u
					int lines = 0;
					while(lines<=1000)
					{
						int x1 = 320;
						int y1 = 240;
						int x = rand() % 321 + 160;
						int y = 480;
						int r = rand() % 100;
						int g = rand() % 50;
						int b = rand() % 256;
						line(backBuffer, x1, y1, x, y, makecol(255, g, r));
						lines+=1;
					}
				}
				if(key[KEY_SPACE])
				{
					//key q
					int circles1 = 0;
					int x1 = rand() % 641;
					int y1 = rand() % 481;
					while(circles1<=2000)
					{
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x1, y1 ,rad, makecol(0, 0, b));
						circles1+=1;
					}
					int circles2 = 0;
					int x2 = rand() % 641;
					int y2 = rand() % 481;
					while(circles2<=2000)
					{
						int rad = rand() % 1000;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, x2, y2 ,rad, makecol(0, 0, b));
						circles2+=1;
					}
					//key w
					int circles = 0;
					while(circles<=200)
					{
						int x = rand() % 641;
						int y = rand() % 481;
						int rad = rand() % 50;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						circle(backBuffer, 120, 40 ,rad, makecol(255, 255, 255));
						circles+=1;
					}
					//key e
					float y = 400;
					int lines = 0;
					while(lines<=500)
					{
						int x = rand() % 641;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						line(backBuffer, 0, y, 360000, y, makecol(r, 255, 255));
						lines+=1;
						y+=1;
					}
					int lines2 = 0;
					while(lines2<=500)
					{
						int xr1 = rand() % 700;
						int xr2 = xr1 - 60;
						int yr1 = 400;
						int yr2 = 480;
						int b = rand() % 256;
						line(backBuffer, xr1, yr1, xr2, yr2, makecol(0, 0, b));
						lines2+=1;
					}
					//key r
					float y100 = 400;
					int stars = 0;
					while(stars<=500)
					{
						int x = rand() % 720;
						int y100 = rand() % 400;
						int rad = rand() % 100;
						int r = rand() % 256;
						int g = rand() % 256;
						int b = rand() % 256;
						drawSnow(x, y100, 3, 1, 255, 255, 255);
						stars+=1;
						y100+=1;
					}
				}

                blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
        }
}
// Dont forget the END_OF_MAIN below
END_OF_MAIN()
