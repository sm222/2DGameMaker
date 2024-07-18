
#ifndef OBJECTBASIC_HPP_
#define OBJECTBASIC_HPP_

#	include "../inc/CPPDefine.hpp"

//	Class declaration
class ObjectBasic {
//	The building blocks of any game

	protected:
		id_t								id; 		// Stores a unique object id
		std::string					name;		// Stores the object name
		std::string					type;		// Stores the object type

/// vector<std::string>	tags			// Stores all the object's tags							( if any )
//	Object							parent		// Stores the parent object									( if any )
//	vector<ObjectBasic>	children	// Stores all the object's children objects	( if any )

//	ScriptRender				render		// Stores the render data and methods
//	ScriptPhysic				physic		// Stores the physic data and methods
//	ScriptBasic					script		// Stores all other data and methods

	public:
		ObjectBasic();
		~ObjectBasic();

		//	Accessers

		id_t				getId();
		std::string	getName();
		std::string	getType();

		setId( id_t id );
		setName( std::string name );
		setType( std::string type );

		//	Methods


};

/*	TODO : make these children classes :

	-- 	2D	--

	Object2D
	+ Position and Rotation
	+ default ModuleRender2D
	+ default ModulePhysic2D

	ObjectUI
	+ default UI script

	ObjectDevice
	+ default interaction ModuleScript

	--	3D	--

	Object3D
	+ Quaternion ( for pos and rot in 3D )
	+ default 3D render and physic module

	...

*/

#endif	// OBJECTBASIC_HPP_
