#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "Common_function.h"
#include<iostream>

using namespace std;

class BaseObject
{
public :
    BaseObject();
    ~BaseObject();

    void Set_Rect (const int& valueofx, const int& valueofy) // ham dung de set kich thuoc cho rect
    {
        rect_object.x = valueofx ;
        rect_object.y = valueofy ;
    }

    SDL_Rect GetRect() const { return rect_object; } // ham lay ra size cua hinh anh
    SDL_Texture* GetObject() const { return p_object;} // ham lay ra hinh anh

    bool LoadImg(const char* path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();



private :
    SDL_Texture* p_object; // bien chuyen luu tru hinh anh
    SDL_Rect rect_object; // bien chuyen luu tru size cua hinh anh





};

#endif // OBJECTBASE_H
