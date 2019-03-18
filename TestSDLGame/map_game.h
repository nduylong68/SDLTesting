
#ifndef MAP_GAME_H
#define MAP_GAME_H

#include "Common_function.h"
#include "ObjectBase.h"

#define MAX_TILES 20

class TileMap : public BaseObject
{
    public:
        TileMap() {;}
        ~TileMap() {;}

};


class GameMap
{
public:
    GameMap() {;}
    ~GameMap() {;}

    void LoadMap( char* name);
    void LoadTiles(SDL_Renderer* screen);
    void DrawMap(SDL_Renderer* screen);

private:
    Map game_map;
    TileMap tile_map[MAX_TILES];
};





#endif // MAP_GAME_H

