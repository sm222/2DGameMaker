
/********************************************
*                                           *
* this file should never be compile or use. *
*                                           *
*********************************************/

#ifndef  __EX__NOT_USE
# define __EX__NOT_USE

#include <raylib.h>
#include <string>
#include <map>

using std::string;
using std::map;

struct renderValue {
	bool			_visible;
	Vector2			_pos;
	Texture			_texture;
	unsigned long	_id;
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