
#include <allegro.h>
#include <stdio.h>
BITMAP * backBuffer;

void drawXmas(float xa, float ya, float rada, int ra, int ga, int ba)
{
	//Merry xmas
	//'M'( * radx1)
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

void drawXmasballs( int xc, int yc, float radc, int rc, int gc, int bc)
{
	//xc, yc centre point of large circle, radc is radius, colours
	circle(backBuffer, xc, yc, radc, makecol(rc, gc, bc));

	//inner concentric circles
	int spacec = rand() % 6 + 2;

	for(float qtyc= 0; qtyc< (radc/1.1); qtyc++)
	{
		if(radc > spacec)
		{
			radc -= spacec;
		}
		circle(backBuffer, xc, yc, radc, makecol( rc, gc, bc));
	}

}

void drawTrees( float xd, float yd, float radd, float rd, float gd, float bd)
{
	// xd, yd == centre point, radd == size, rd, gd, bd == colours

	//top triangle
	triangle(backBuffer, xd, yd - (radd / 4), xd - (radd / 4), yd + (radd / 8), xd + (radd / 4), yd + (radd / 8), makecol(rd, gd, bd));
	//mid triangle
	triangle(backBuffer, xd, yd, xd - (radd / (2 + (2/3))), yd + (radd / 2), xd + (radd / (2 + (2/3))), yd + (radd / 2), makecol(rd, gd, bd));
	//trunk
	rectfill(backBuffer, xd - (radd / 16), yd + (radd / 2), xd + (radd / 16), yd + (radd / (1 + (1 / 2))), makecol(rd + 105, gd - 70, bd - 15));
}

void drawTrees2( float xd, float yd, float radd, float rd, float gd, float bd)
{
	// xd, yd == centre point, radd == size, rd, gd, bd == colours

	//top triangle
	triangle(backBuffer, xd, yd - (radd / 4), xd - (radd / 4), yd + (radd / 8), xd + (radd / 4), yd + (radd / 8), makecol(rd, gd, bd));
	//mid triangle
	triangle(backBuffer, xd, yd, xd - (radd / (2 + (2/3))), yd + (radd / 2), xd + (radd / (2 + (2/3))), yd + (radd / 2), makecol(rd, gd, bd));
	//trunk
	rectfill(backBuffer, xd - (radd / 16), yd + (radd / 2), xd + (radd / 16), yd + (radd / 1.35), makecol(rd + 105, gd - 70, bd - 15));
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
        
		int timerA = 0, 
			intervalA = 10;
		bool keyA = false;
		
		install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
		MIDI * music = load_midi("rolling_stones-paint_it_black.mid");
		install_keyboard();
        bool done = false;
		play_midi(music, true);
        while (! done)
        {
			 if (key[KEY_ESC])
                {
                        done = true;
                        break;                                
                }
                               
                // Call your function from here!!
				

				clear_to_color(backBuffer, makecol(0, 0, 0));
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

				if (key[KEY_W])
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
				if (key[KEY_E])
                {
					int randx = rand() % 641;
					int randy = rand() % 481;
					int randrad = rand() % 3 + 1;
					drawSnow(randx, randy, randrad, 255, 255, 255);
					int i = 0;

					while(i<=randx)
					{
						int randx1 = rand() % 641;
						int randy1 = rand() % 481;
						int randrad1 = rand() % 3 + 1;
						drawSnow(randx1, randy1, randrad1, 255, 255, 255);
						i++;
					}
				}

				if (key[KEY_R])
				{
				for(int i1 = 0; i1 < 100; i1 ++)
				{
				bool i = false;
				int j1 = rand() % 100;
				if (j1>50)
                {
					i = true;
				}
				if (!i)
				{
					int x1 = rand() % 641;
					int y1 = rand() % 481;
					int rad1 = rand() % 100;
					int r1 = rand() % 256 + 150;
					circle(backBuffer, x1, y1, rad1, makecol(r1, 0, 0));
				}
				else
				{
					int x1 = rand() % 641;
					int y1 = rand() % 481;
					int rad1 = rand() % 100;
					int r1 = rand() % 256 + 150;
					circle(backBuffer, x1, y1, rad1, makecol(0, r1, 0));
				}
				}
				}
				if (key[KEY_T])
				{
					int width = 640;
					int height = 480;
					int rad = 0;
					int x = (width/2) - 50;
					int y = (height/2);
					int r = rand() % 256;
					int g = rand() % 256;
					int b = rand() % 256;
					while(rad<=500)
					{
						circle(backBuffer, x, y, rad, makecol(r, g, 0));
						for(int i = 0; i <= 20; i++)
						{
							x + 2;
							y + 1;
						}
						rad++;
					}
				}
				if (key[KEY_Y])
                {
					float Xinc = 0.1f;
					float Xpos = 20;

						Xpos += Xinc;
						int rd = rand() % 256;
						int gd = rand() % 256;
						int bd = rand() % 256;
					
							drawXmas(Xpos, 100, 10, rd, gd, bd);
					
					
				}
				if (key[KEY_U])
				{
					int r7 = rand() % 256;
					int g7 = rand() % 256;
					int b7 = rand() % 256;
					int x7 = rand() % 640;
					int y7 = rand() % 480;
					int rad7 = rand() % 240;

					//drawTrees(x7, y7, rad7, r7, g7, b7);

					drawTrees(x7, y7, rad7, 34, 139, 34);
				}
				if (key[KEY_I])
				{
					int r8 = rand() % 256;
					int g8 = rand() % 256;
					int b8 = rand() % 256;
					int x8 = rand() % 256;
					int y8 = rand() % 256;
					//triangle(backBuffer, r8, g8, b8, r8, g8, b8, makecol(r8, g8, b8));
					int i8 = 0;
					//while(i8 <= 65025)
					while(i8 <= 1000)
					{
						int r9 = rand() % 256;
						int g9 = rand() % 256;
						int b9 = rand() % 256;
						//putpixel(backBuffer, r9, g9, makecol(r9, g9, b9));
						circle(backBuffer, r9 + b9, g9 + b9, b9, makecol(r9, g9, b9));
						i8 ++;
					}
				}
				if (key[KEY_O])
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

					int randx = rand() % 641;
					int randy = rand() % 481;
					int randrad = rand() % 3 + 1;
					drawSnow(randx, randy, randrad, 255, 255, 255);
					int i = 0;
					while(i<=randx)
					{
						int randx1 = rand() % 641;
						int randy1 = rand() % 481;
						int randrad1 = rand() % 3 + 1;
						drawSnow(randx1, randy1, randrad1, 255, 255, 255);
						i++;
					}

						float Xinc = 0.1f;
						float Xpos = 20;
						Xpos += Xinc;
						int rd = rand() % 256;
						int gd = rand() % 256;
						int bd = rand() % 256;
					
						drawXmas(Xpos, 100, 10, rd, gd, bd);

					int r10 = rand() % 256;
					int g10 = rand() % 256;
					int b10 = rand() % 256;
					float x10;
					int y10 = 300;
					float x11;
					
					for(int i9 = 0; i9 <= 300; i9 ++)
					{
						int y11 = rand() % 480 + 300;
						int y12 = rand() % 480 + 300;
						x10 = i9 * 5;
						y10 ++;
						x11 = x10 * 1.1;
						drawTrees( x10, y11, 10, 34, 139, 34);
						drawTrees( x11, y12, 10, 34, 139, 34);
						line(backBuffer, 0, y10, 640, y10, makecol(255, 255, 255));

					}
				}

				//Xmas
				if (key[KEY_Q])
                {
					int randx = rand() % 641;
					int randy = rand() % 10; 
					int x1 = 50;
					int y1 = 50;
					int i = 0;
					while(x1<=70)
					{
						int r = rand() % 256 + 100;
						int g = rand() % 256 + 100;
						int b = rand() % 256;
						drawXmas(x1, y1, 31, r, g, 0);
						x1+=2;
						y1+=1;
					}
				}

				
				//	finals
				//    made on
				//    2013-04-02
				int ticker = 0,
					interval = 100;
				while(key[KEY_A])
				{
					if(ticker % interval == 0)
					{
						clear_to_color(backBuffer, makecol(0, 0, 0));
						//key w
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
						//key e
						if(ticker > 3 * interval)
						{
							int randx = rand() % 641;
							int randy = rand() % 481;
							int randrad = rand() % 3 + 1;
							drawSnow(randx, randy, randrad, 255, 255, 255);
							int i = 0;

							while(i<=randx)
							{
								int randx1 = rand() % 641;
								int randy1 = rand() % 481;
								int randrad1 = rand() % 3 + 1;
								drawSnow(randx1, randy1, randrad1, 255, 255, 255);
								i++;
							}
						}
						//key q
						if(ticker > 8 * interval)
						{
							int randx = rand() % 641;
							int randy = rand() % 10; 
							int x1 = 50;
							int y1 = 50;
							int i = 0;
							while(x1<=70)
							{
								int r = rand() % 256 + 100;
								int g = rand() % 256 + 100;
								int b = rand() % 256;
								drawXmas(x1, y1, 31, r, g, 0);
								x1+=2;
								y1+=1;
							}
						}
					}
					ticker ++;
					blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
				}
				if(key[KEY_S])
				{
					//key o
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

					int randx = rand() % 641;
					int randy = rand() % 481;
					int randrad = rand() % 3 + 1;
					drawSnow(randx, randy, randrad, 255, 255, 255);
					int i = 0;
					while(i<=randx)
					{
						int randx1 = rand() % 641;
						int randy1 = rand() % 481;
						int randrad1 = rand() % 3 + 1;
						drawSnow(randx1, randy1, randrad1, 255, 255, 255);
						i++;
					}

						float Xinc = 0.1f;
						float Xpos = 20;
						Xpos += Xinc;
						int rd = rand() % 256;
						int gd = rand() % 256;
						int bd = rand() % 256;
					
						drawXmas(Xpos, 100, 10, rd, gd, bd);

					int r10 = rand() % 256;
					int g10 = rand() % 256;
					int b10 = rand() % 256;
					float x10;
					int y10 = 300;
					float x11;
					
					int iRay = 0;
					while(iRay < 300)
					{
						line(backBuffer, 0, y10, 640, y10, makecol(255, 255, 255));
						y10 ++;
						iRay ++;
					}
					y10 = 300;
					for(int i9 = 0; i9 <= 300; i9 ++)
					{
						int y11 = rand() % 480 + 300;
						int y12 = rand() % 480 + 300;
						x10 = i9 * 5;
						y10 ++;
						x11 = x10 * 1.1;
						drawTrees2( x10, y11, 10, 34, 139, 34);
						drawTrees2( x11, y12, 10, 34, 139, 34);
						//line(backBuffer, 0, y10, 640, y10, makecol(255, 255, 255));

					}
				}


                blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
        }
}
// Dont forget the END_OF_MAIN below
END_OF_MAIN()
