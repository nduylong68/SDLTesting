#include "MainPlayer.h"
#include "Common_function.h"
#include "ObjectBase.h"

MainPlayer:: MainPlayer()
{
    frame = 0;
    x_pos = 0;
    y_pos = 0;
    x_val = 0;
    y_val = 0;
    width_frame = 0;
    height_frame = 0;
    status = -1;
}

MainPlayer::~MainPlayer()
{

}

bool MainPlayer::LoadImg(const char* path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path, screen);
    if (ret == true)
    {
        width_frame = rect_object.w / FrameSize;
        height_frame = rect_object.h;
    }

    return ret;
}

void MainPlayer::set_clip()
{
    if(width_frame > 0 && height_frame > 0)
    {   for(int i =0; i < FrameSize; i++)
        {
            frame_clip[i].x = i * width_frame;
            frame_clip[i].y = 0;
            frame_clip[i].w = width_frame;
            frame_clip[i].h = height_frame;
        }
    }
}

void MainPlayer::Show(SDL_Renderer* des)
{
    if(status == walk_left)
    {
        LoadImg("Pic/player_left.png", des);
    }
    else
    {
        LoadImg("Pic/player_right.png", des);
    }

    if (Input_type.left == 1 || Input_type.right == 1)
    {
        frame ++;
    }
    else frame = 0;

    if(frame >= 8)
    {
        frame = 0;
    }

    rect_object.x = x_pos;
    rect_object.y = y_pos;

    SDL_Rect* current_clip = &frame_clip[frame];

    SDL_Rect renderQuad = {rect_object.x, rect_object.y, width_frame, height_frame}; // chua toa do dang o va kich thuoc

    SDL_RenderCopy(des, p_object, current_clip, &renderQuad);
}



void MainPlayer::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                status = Walk_right;
                Input_type.right = 1;
            }
            break;
        case SDLK_LEFT:
            {
                status = walk_left;
                Input_type.left = 1;
            }
            break;
        default:
            break;
        }
    }
    else if ( events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                Input_type.right = 0;
            }
            break;
        case SDLK_LEFT:
            {
                Input_type.left = 0;
            }
            break;
    }
}
}
