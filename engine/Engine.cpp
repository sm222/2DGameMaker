#include "Engine.hpp"

// Constructor and Destructor

Engine::Engine()
{
	this->state = E_STATE_NONE;
	this->gameName = "Default Game";
	this->engineVersion = "0.0.1";
	this->stepCount = 0;

	PRINT_DEBUG( "Engine created" );
}
Engine::~Engine() { PRINT_DEBUG( "Engine destroyed" ); }

// Accessors

EngineState	Engine::State() { return this->state; }
EngineState	Engine::State( EngineState setState )
{
	this->state = setState;
	return this->state;
}

string	Engine::GameName() { return this->gameName; }
string	Engine::GameName( const std::string setName )
{
	this->gameName = setName;
	return this->gameName;
}

string	Engine::Version() { return this->engineVersion; }
string	Engine::Version( const std::string setVersion )
{
	this->engineVersion = setVersion;
	return this->engineVersion;
}

// Other Methods

EngineState	Engine::initialize( int argc, char **argv )
{
	PRINT_DEBUG( "Engine initializing" );

	if ( argc != 2 )
	{
		PRINT_ERROR( string( "Usage: ") + argv[0] + string( MSG_ERROR_WRONG_ARGS ) );
		return E_STATE_WRONG;
	}

	PRINT_DEBUG( "Engine initialized" );
	return E_STATE_RUNNING;
}