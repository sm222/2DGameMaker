
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

#define VEC2(x,y) (Vector2){x, y}

struct renderValue {
    bool            _visible;
    Vector2         _pos;
    Texture         _texture;
};

struct Canvas {
    Camera2D*       _camera;
    size_t          _yG, _xG;       //size in memory
    size_t          _sizeG[101];    //number of item
    renderValue**   _game;
    //
    size_t          _yU, _xU;       //size in memory
    size_t          _sizeU[101];
    renderValue**   _ui;
};


class Room {
	private:
		string						_name;
		renderValue					_rv;
		map<string, unsigned int>	_layerName;
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