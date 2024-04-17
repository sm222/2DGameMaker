struct renderValue {
	bool              *_visible;
	double            *_x;
	double            *_y;
	Texture2D         *_texture;
	unsigned long     *_id;
};

class Object{
	public:
		bool              _visible;          //is visible
		bool              _solid;            //is solid
		bool              _persistent;       //is persistent in the other room
		Image             _image;            //the image of the object (not the texture)
		unsigned long     _id;               //his id
		double            _xStart;           //initial x position
		double            _yStart;           //initial y position
		double            _x;                //x position
		double            _y;                //y position
		double            _xPrevious;        //last x position
		double            _yPrevious;        //last y position
		double            _direction;        //direction angle
		double            _speed;            //speed (guided by direction)
		double            _hSpeed;            //speed (guided by direction)
		double            _vSpeed;            //speed (guided by direction)
		double            _depth;            //the depth of this object
		double            _layer;            //layer information
		double            _image_angle;      //the image angle of this object
		double            _image_alpha;      //the image alpha
		double            _image_speed;      //the image speed (for a built in animation)
		bool              _image_xFlip;      //horizontal flip of the image
		bool              _image_yFlip;      //vertical flip of the image
	private:
};