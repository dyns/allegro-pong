#include "pong_header.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void drawScore(const int xpos, const int score) {

}

void drawBoard() {
	const float x = SCR_W / 2;
	const float y = SCR_H / 2;
	const ALLEGRO_COLOR col = al_map_rgb(256, 100, 0);
	const float rad = SCR_H / 8;

	al_draw_line(x, 0, x, y-rad, col, 5);
	al_draw_line(x, y+rad, x, SCR_H, col, 5);
	al_draw_circle(x, y, rad, col, 5);
}

void drawBall(const Ball * const ball) {

}

void drawPaddle(const Paddle * const pad) {
	int x1 = 0, x2 = 0;
	const int paddle_width = 15;
	const int paddle_height = 40;
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	if(pad->side == LEFT){
		x1 = 0;
	} else {
		x2 = SCR_W - paddle_width;
	}

	x2 = x1 + paddle_width;

	al_draw_filled_rectangle(x1, pad->ypos, x2, pad->ypos + paddle_height, white);
}
