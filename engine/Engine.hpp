#ifndef ENGINE_HPP_
# define ENGINE_HPP_

# include "../inc/Messages.h"
# include "Debug.hpp"
# include <iostream>

using std::string;

typedef enum
{
	E_STATE_WRONG					= -1,
	E_STATE_NONE					= 0,
	E_STATE_INITIALIZING,
	E_STATE_PAUSED,
	E_STATE_RUNNING,
	E_STATE_SHUTDOWN
}					EngineState;


class Engine{
//	The building blocks of any game

	protected:
		EngineState		state;
		string				gameName;
		string				engineVersion;
		long					stepCount;

		//	Methods
		EngineState stepRender();
		EngineState stepInputs();
		EngineState stepPhysic();
		EngineState stepScript();

		string	GameName();
		string	GameName( const std::string setName );

		string	Version();
		string	Version( const std::string setVersion );

	public:
		Engine();
		~Engine();

		//	Accessors
		EngineState	State();
		EngineState	State( EngineState setState );

		//	Methods
		EngineState	initialize( int argc, char **argv );
		EngineState	stepGame();
		EngineState	shutdown();

};

#endif // ENGINE_HPP_