
#ifndef SCRIPTBASIC_HPP_
#define SCRIPTBASIC_HPP_

#	include "../inc/CPPDefine.hpp"

//	Class declaration
class ScriptBasic {
// stores all the data and methods of a specific functionnality of an Object ( like render, physic, script )

	protected:
		std::string type;			// default = "basic"
		ObjectBasic *parent;	// Stores the parent object ( if any )

	public:
		//	Constructers
		ScriptBasic();
		~ScriptBasic();

		//	Accessers
		getType()
		getParent()

		setParent( ObjectBasic *parent )

		//	Methods
		virtual void onCreate() = 0; // called when using createObject()
		virtual void onUpdate() = 0; // called every frame
		virtual void onDelete() = 0; // called when using deleteObject()

};

/*	TODO : make these children classes :

	ScriptRender
	+ type = "render"
	+ virtual void onRender() = 0;
	+ Render data and methods

	ScriptPhysic
	+ type = "physic"
	+ virtual void onPhysic() = 0;
	+ Physic data and methods

*/

#endif	// SCRIPTBASIC_HPP_
