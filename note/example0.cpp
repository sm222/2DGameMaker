
/********************************************
*                                           *
* this file should never be compile or use. *
*                                           *
*********************************************/

#ifndef  __EX__NOT_USE
# define __EX__NOT_USE

#include <stdint.h>

#include <raylib.h>
#include <string>
#include <map>

using std::string;
using std::map;

// C define
#define VEC2(x,y)   (Vector2){x, y}
#define MAX_CANVAS  100
#define MAX_LAYER   100

//C++ define
//#define

// sould be conpatible on C
struct renderValue {
    bool            _visible;
    Vector2         _pos;
    Texture        *_texture;

};

// sould be conpatible on C
struct Canvas {
    Camera2D*       _camera;
    size_t          _yG, _xG;                 // size in memory
    size_t          _sizeG[MAX_LAYER + 1];    // number of item
    renderValue**   _game;                    // value to print
    //
    size_t          _yU, _xU;                 // size in memory
    size_t          _sizeU[MAX_LAYER + 1];    //
    renderValue**   _ui;
};


class Room {
    private:
        string                      _name;
        renderValue                 _rv;
        map<string, unsigned int>   _layerName;
        Canvas                      *canvasList[MAX_CANVAS + 1];
    public:
        //ft
        Room(string name);
        ~Room();
};



Room::Room(string name) : _name(name) {
}

Room::~Room() {
}

int main() {
	Room* ptr = new Room("menu");
}

#endif