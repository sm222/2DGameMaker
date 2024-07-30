
#ifndef OBJECTBASIC_HPP_
# define OBJECTBASIC_HPP_

#	include "../core.hpp"

class GroupBasic;

//	Class declaration
class ObjectBasic {
//	The building blocks of any game

	protected:
		id_t				id; 		// Stores the object's unique id
		string			name;		// Stores the object name
		string			type;		// Stores the object type

//	ScriptRender		render		// Stores the render data and methods
//	ScriptPhysic		physic		// Stores the physic data and methods
//	ScriptBasic			script		// Stores all other data and methods

//	ObjectBasic					*parent		// Stores the parent of this object					( if any )
//  GroupBasic					*children	// Stores the children this object has			( if any )
//	vector<GroupBasics>	groups		// Stores the groups this object belongs to	( if any )

	public:
		ObjectBasic();
		~ObjectBasic();

		//	Accessers
		id_t		getId();
		string	getName();
		string	getType();

		ObjectBasic	*getParent();
		GroupBasic	*getChildren();
		GroupBasic	*getSiblings(); // = getParent()->getChildren() minus yourself

		void	setId( id_t id );
		void	setName( string name );
		void	setType( string type );

		void	setParent( ObjectBasic *parent );

		//	Methods

		void addChild( ObjectBasic *child );
		void removeChild( ObjectBasic *child );

		void addSibling( ObjectBasic *sibling );
		void removeSibling( ObjectBasic *sibling );


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
