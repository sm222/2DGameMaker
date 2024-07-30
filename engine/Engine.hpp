#ifndef ENGINE_HPP_
# define ENGINE_HPP_

# include "core.hpp"

typedef enum
{
	E_STATE_WRONG				= -1,
	E_STATE_STARTING		= 0,
	E_STATE_PAUSED,
	E_STATE_RUNNING,
	E_STATE_CLOSING
}					EngineState;

class Engine{
//	The building blocks of any game

	protected:
		EngineState		state;
		string				gameName;
		string				engineVersion;
		long					stepCount;

		//	Step Methods
		EngineState stepRender();
		EngineState stepInputs();
		EngineState stepPhysic();
		EngineState stepScript();

		//	Accessors
		string	GameName();
		string	GameName( const string setName );

		string	Version();
		string	Version( const string setVersion );

	public:
		Engine();
		~Engine();

		//	Accessors
		EngineState	State();
		EngineState	State( EngineState setState );

		//	State Methods
		EngineState	initialize( int argc, char **argv );
		EngineState	shutdown();

		EngineState	stepGame();

		EngineState	pause();
		EngineState	resume();

};

#endif // ENGINE_HPP_