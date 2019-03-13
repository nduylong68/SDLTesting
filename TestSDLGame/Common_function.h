#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include<windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

using namespace std;


static SDL_Window *g_window = NULL; // build a window form for game
static SDL_Renderer* g_screen = NULL;
static SDL_Event* g_event; // event accept mouse, keyboard

//SCREEN

const int screen_width = 1280;
const int screen_height = 720;
const int screen_BPP = 32; // chi so ve pixel

const int color_key_r = 167;
const int color_key_g = 175;
const int color_key_b = 180;





#endif // COMMON_FUNCTION_H
