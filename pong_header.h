#ifndef _PONG_HEADER_H
#define _PONG_HEADER_H

#include <allegro5/allegro.h>

#define PONG_VERSION "0.1"

#define FPS 30
#define SCR_W 640
#define SCR_H 480

#define PADDLE_HEIGHT 90
#define PADDLE_WIDTH 10
#define PADDLE_SPEED 10

enum Side {LEFT, RIGHT};

typedef struct {
	float ypos;
	float yspd;
	int score;
	int height;
	enum Side side;
} Paddle;

typedef struct {
	float xpos;
	float ypos;
	float xspd;
	float yspd;
	float radius;
} Ball;

void initP1(Paddle * const pad);
void initP2(Paddle * const pad);

void inputP1(Paddle * const pad);
void inputP2(Paddle * const pad);

void moveBall(Ball * const ball);

int doesBallHitPad(const Paddle * const pad, const Ball * const ball);

// Changes the ball's direction by how much the paddle influenced it.
void padDirToBall(const Paddle * const pad, Ball * const ball);

// -------- DRAWING FUNCTIONS -----------

void fonts_init();

// Y position will be hard coded here.
void drawScore(enum Side side, const int score);

// Draws a sick looking arena type thing.
void drawBoard();

void drawBall(const Ball * const ball);
void drawPaddle(const Paddle * const pad);

// ---------- MUSIC FUNCTIONS -------------
void audio_init();
void play_music();
void audio_destroy();

// ---------- GAME LOGIC -----------
void updatePaddlesForEvent(const ALLEGRO_EVENT * const event, Paddle *left_pad);
void updatePaddle(Paddle * const left_pad);
void moveBall(Ball * const ball);
void computerPaddle(Paddle * const pad, Ball * const ball);

// ---------- ARGUMENT PARSING -----------
typedef struct {
	int multiplayer;
	char *theme; // prob enough for any theme.
} Arguments;

#endif // _PONG_HEADER_H
