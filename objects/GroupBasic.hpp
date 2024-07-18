
#ifndef GROUPBASIC_HPP_
#define GROUPBASIC_HPP_

#	include "../inc/CPPDefine.hpp"

//	Class declaration
class GroupBasic {
//	The building blocks of any game

	protected:
		id_t									id; 			// Stores the group's unique id (?)
		std::string						name;			// Stores the group's name

//	ObjectBasic						*owner		// Stores the owner of this group		( if any )
//  Vector<ObjectBasic*>	members		// Stores this group's members

	public:
		GroupBasic();
		~GroupBasic();

		//	Accessers
		id_t									getId();
		std::string						getName();
		ObjectBasic						*getOwner();
		Vector<ObjectBasic*>	*getMembers();

		setId( id_t id );
		setName( std::string name );
		setOwner( ObjectBasic *owner );

		//	Methods
		void addMember( ObjectBasic *member );
		void removeMember( ObjectBasic *member );


};

/*	TODO : make these children classes :

	GroupChildren ( exclusively for an object's children )

*/

#endif	// GROUPBASIC_HPP_
