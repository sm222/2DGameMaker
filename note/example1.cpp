// class PropsObject{
// 	public:
// 		bool				_visible;		//is visible
// 		bool				_solid;			//is solid
// 		bool				_persistent;	//is persistent in the other room
// 		Image				_image;			//the image of the object (not the texture)
// 		unsigned long		_id;			//his id
// 		double				_xStart;		//initial x position
// 		double				_yStart;		//initial y position
// 		double				_x;				//x position
// 		double				_y;				//y position
// 		double				_xPrevious;		//last x position
// 		double				_yPrevious;		//last y position
// 		double				_direction;		//direction angle
// 		double				_speed;			//speed (guided by direction)
// 		double				_hSpeed;		//speed (guided by direction)
// 		double				_vSpeed;		//speed (guided by direction)
// 		double				_depth;			//the depth of this object
// 		double				_layer;			//layer information
// 		double				_image_angle;	//the image angle of this object
// 		double				_image_alpha;	//the image alpha
// 		double				_image_speed;	//the image speed (for a built in animation)
// 		bool				_image_xFlip;	//horizontal flip of the image
// 		bool				_image_yFlip;	//vertical flip of the image
// 	private:
// 		void coreStep();
// 		void step();
// 		void draw();
// };

/*
objects
BasicObject.cpp
BasicObject.h
PropObject.cpp
PropObject.h
LiteObject.cpp
LiteObject.h
UiObject.cpp
UiObject.h

basic object
	_texture
	_pos
		Prop object
			_visible
			_solid
			_persistent
			_image
			_id
			_xStart
			_yStart
			_x
			_y
			_xPrevious
			_yPrevious
			_direction
			_speed
			_hSpeed
			_vSpeed
			_depth
			_layer
			_imageAngle
			_imageAlpha
			_imageSpeed
			_imageXFlip
			_imageYFlip

		lite object // juste un basic object

		ui object // pour les ui



*/




class bob : public PropObject{
	public:
		bob();
		~bob();
		void step();
		void draw();
	private:
		double _x;
		double _y;
		double _depth;
		double _layer;
		double _image_angle;
		double _image_alpha;
		double _image_speed;
		bool _image_xFlip;
		bool _image_yFlip;
		Image _image;
};