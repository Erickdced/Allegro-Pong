#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//main
int main (void)
{
	//pre-settings
	allegro_init();
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 320, 0, 0);
	
	//variable declarations
	BITMAP *buffer = create_bitmap(640, 320);
	int lpad[] = {170, 190, 210, 230, 250, 270}, rpad[] = {170, 190, 210, 230, 250, 270}, bg [] = {1, 639, 5, 315}, ball[] = {320, 160, 0, 0};
	int pcol = 0x273746, bcol = makecol(200, 30, 200), wcol = 0x000000, bgcol = 0x000000;
	srand(time(NULL));
	int direc = rand() % 10, win = 0, xr1 = 630, xr2 = 634, xl1 = 6, xl2 = 10, rad = 7, i, ms = 15, n = 1, r = 255, g = 255, b = 255;
	
	//first print
	clear_to_color(buffer, bgcol);
	textout_centre_ex(buffer, font, "Pong Ver-1.2", 320, 15, 0xFFFFFF, 0x000000);
	rect(buffer, bg[0], bg[2], bg[1], bg[3], wcol); //walls
	circlefill(buffer, ball[0], ball[1], rad, bcol); //ball
	rectfill(buffer, xr1, rpad[0], xr2, rpad[5], pcol); //right paddle
	rectfill(buffer, xl1, lpad[0], xl2, lpad[5], pcol); //left paddle
	blit(buffer, screen, 0, 0, 0, 0, 640, 320);
	
	
	readkey();
	//main while
	while(!key[KEY_ESC] && (win != 1 && win != 2))	
	{
		bcol = makecol(r, g, b);
		//win conditions
		ball[2] = ball[0] - rad, ball[3] = ball[0] + rad;
		if(ball[2] >= bg[1])
		{
			win = 1;
		}
		if(ball[3] <= bg[0])
		{
			win = 2;
		}
		
		//circle movement
		
		if(direc == 0)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] - 4, ball[1] = ball [1] - 4;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 1)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] - 4, ball[1] = ball[1] - 3;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 2)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball [0] - 5;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 3)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball [0] - 4, ball[1] = ball[1] + 3;  
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 4)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] - 4, ball[1] = ball[1] + 4;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 5)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] + 4, ball[1] = ball[1] - 4;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 6)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] + 4, ball[1] = ball[1] - 3;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 7)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] + 5;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		if(direc == 8)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball[0] + 4, ball[1] = ball[1] + 3; 
			circlefill(buffer, ball[0], ball[1], rad, bcol);	
		}
		if(direc == 9)
		{
			rectfill(buffer, 11, 0, 629, 320, bgcol);
			ball[0] = ball [0] + 4, ball[1] = ball[1] + 4;
			circlefill(buffer, ball[0], ball[1], rad, bcol);
		}
		rest(ms);

		//paddle movement
		if(key[KEY_W] && lpad[0] > 5)
		{
			rectfill(buffer, 0, 6, xl2, 314, bgcol);
			for(i = 0; i < 6; i++)
			{
				lpad[i] = lpad[i] - 5;
			}
			rectfill(buffer, xl1, lpad[0], xl2, lpad[5], pcol); 
			
		}		
		if(key[KEY_S] && lpad[5] < 315)
		{
			rectfill(buffer, 0, 6, xl2, 314, bgcol);
			for(i = 0; i < 6; i++)
			{
				lpad[i] = lpad[i] + 5;
			}
			rectfill(buffer, xl1, lpad[0], xl2, lpad[5], pcol); 
		}
		if(key[KEY_UP] && rpad[0] > 5)
		{
			rectfill(buffer, xr1, 6, 640, 314, bgcol);
			for(i = 0; i < 6; i++)
			{
				rpad[i] = rpad[i] - 5;
			}
			rectfill(buffer, xr1, rpad[0], xr2, rpad[5], pcol); 
		}
		if(key[KEY_DOWN] && rpad[5] < 315)
		{
			rectfill(buffer, xr1, 6, 640, 314, bgcol);
			for(i = 0; i < 6; i++)
			{
				rpad[i] = rpad[i] + 5;
			}
			rectfill(buffer, xr1, rpad[0], xr2, rpad[5], pcol); 
		}
		 
		//hitboxes of walls
		if(ball[1] - rad <= 5 &&(direc == 0 || direc == 1 || direc == 2 || direc == 3 || direc == 4))
		{
			direc = 3;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
			
		}
		if(ball[1] - rad <= 5 && (direc == 5 || direc == 6 || direc == 7 || direc == 8 || direc == 9))
		{
			direc = 8;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[1] + rad >= 315 && (direc == 0 ||direc == 1 || direc == 2 || direc == 3 || direc == 4))
		{
			direc = 1;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if( ball[1] + rad >= 315 && (direc == 5 || direc == 6 || direc == 7 || direc == 8 || direc == 9))
		{
			direc = 6;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		
		//hitboxes of paddles
		if(ball[2] <= xl2 && ball[2] >= xl1 && ball[1] >= lpad[0] && ball[1] <= lpad[1])
		{
			direc = 5;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[3] <= xr2 && ball[3] >= xr1 && ball[1] >= rpad[0] && ball[1] <= rpad[1])
		{
			direc = 0;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[2] <= xl2 && ball[2] >= xl1 && ball[1] >= lpad[1] && ball[1] <= lpad[2])
		{
			direc = 6;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[3] <= xr2 && ball[3] >= xr1 && ball[1] >= rpad[1] && ball[1] <= rpad[2])
		{
			direc = 1;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[2] <= xl2 && ball[2] >= xl1 && ball[1] >= lpad[2] && ball[1] <= lpad[3])
		{
			direc = 7;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[3] <= xr2 && ball[3] >= xr1 && ball[1] >= rpad[2] && ball[1] <= rpad[3])
		{
			direc = 2;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[2] <= xl2 && ball[2] >= xl1 && ball[1] >= lpad[3] && ball[1] <= lpad[4])
		{
			direc = 8;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[3] <= xr2 && ball[3] >= xr1 && ball[1] >= rpad[3] && ball[1] <= rpad[4])
		{
			direc = 3;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[2] <= xl2 && ball[2] >= xl1 && ball[1] >= lpad[4] && ball[1] <= lpad[5])
		{
			direc = 9;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		if(ball[3] <= xr2 && ball[3] >= xr1 && ball[1] >= rpad[4] && ball[1] <= rpad[5])
		{
			direc = 4;
			n++;
			r = rand() % 256, g = rand() % 256, b = rand() % 256;
		}
		
		//velocity amount
		if(n == 5)
		{
			n = 0;
			ms--;
		}
		//action print
		blit(buffer, screen, 0, 0, 0, 0, 640, 320);
		keypressed();
		clear_keybuf();
	}
	//winner print
	clear_to_color(buffer, bgcol);
	if(win == 1)
	{
		textout_centre_ex(buffer, font, "Player 1 win", 320, 160, 0xffffff, 0x000000);
	}
	if(win == 2)
	{
		textout_centre_ex(buffer, font, "Player 2 win", 320, 160, 0xffffff, 0x000000);
	}
	blit(buffer, screen, 0, 0, 0, 0, 640, 320);
	
	//end of main and program close
	readkey();
	while(!key[KEY_ESC])
	{
    	readkey();
	}
	destroy_bitmap(buffer);
	return 0;	
}
END_OF_MAIN();