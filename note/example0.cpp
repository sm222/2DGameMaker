
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

//	C defines
#define VEC2(x,y)   (Vector2){x, y}
#define MAX_CANVAS  10
#define MAX_LAYER   100
#define DEF_CAM     Camera2D{VEC2(0,0),VEC2(0,0), 0, 0}


//	C++ defines
#define MAX_DEF_ROOM 50
#define Cams    map<string, Camera2D>

//	Should be compatible with C
struct renderValue {
    bool                visible;
    bool                _rander;
    Vector2             *pos;
    Texture             *texture;
    unsigned int        depth;
    unsigned long long  _id;
};

//	Should be compatible with C
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
        Cams                        _CamList;
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
    _CamList["default"] = DEF_CAM;
}

Room::~Room() {
}

int main() {
	Room *ptr[10];
    ptr[0] = new Room("menu");
}

#endif