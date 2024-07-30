#include "Engine.hpp"

// Constructor and Destructor

Engine::Engine()
{
	this->state = E_STATE_STARTING;
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
string	Engine::GameName( const string setName )
{
	this->gameName = setName;
	return this->gameName;
}


string	Engine::Version() { return this->engineVersion; }
string	Engine::Version( const string setVersion )
{
	this->engineVersion = setVersion;
	return this->engineVersion;
}

// State Methods

EngineState	Engine::initialize( int argc, char **argv )
{
	PRINT_DEBUG( "Engine initializing" );

	if ( argc != 2 )
	{
		PRINT_ERROR( string( "Usage: ") + argv[0] + string( MSG_ERROR_WRONG_ARGS ) );
		return this->State( E_STATE_WRONG );
	}

	this->GameName( argv[1] );

	PRINT_DEBUG( "Engine initialized" );
	return this->State( E_STATE_PAUSED );
}
EngineState Engine::shutdown()
{
	PRINT_DEBUG( "Engine shutting down" );

	this->pause();

	return this->State( E_STATE_CLOSING );
}


EngineState	Engine::pause()
{
	switch ( this->State() )
	{
		case E_STATE_STARTING:
			PRINT_ALERT( MSG_ALERT_STEP_STARTING );
			break;

		case E_STATE_PAUSED:
			PRINT_ALERT( "Engine already paused" );
			break;

		case E_STATE_RUNNING:
			PRINT_DEBUG( "Engine paused" );
			this->State( E_STATE_PAUSED );

		default:
			PRINT_ERROR( MSG_ERROR_WRONG_STATE );


		case E_STATE_CLOSING:
			PRINT_ALERT( MSG_ALERT_STEP_CLOSING );
			break;
	}
	return this->State();
}
EngineState	Engine::resume()
{
	switch ( this->State() )
	{
		case E_STATE_STARTING:
			PRINT_ALERT( MSG_ALERT_STEP_STARTING );
			break;

		case E_STATE_PAUSED:
			PRINT_DEBUG( "Engine resumed" );
			this->State( E_STATE_RUNNING );

		case E_STATE_RUNNING:
			PRINT_ALERT( "Engine already running" );
			break;

		case E_STATE_CLOSING:
			PRINT_ALERT( MSG_ALERT_STEP_CLOSING );
			break;

		default:
			PRINT_ERROR( MSG_ERROR_WRONG_STATE );

	}
	return this->State();
}

// Game Step Methods

EngineState	Engine::stepGame()
{
	PRINT_DEBUG( "Begining step" );

	switch ( this->State() )
	{
		case E_STATE_STARTING :
			PRINT_ALERT( MSG_ALERT_STEP_STARTING );
			return this->State();

		case E_STATE_PAUSED:
		PRINT_DEBUG( "Paused step" );
			this->stepRender();
			this->stepInputs();
			break;

		case E_STATE_RUNNING:
			PRINT_DEBUG( "Running step" );
			this->stepRender();
			this->stepInputs();
			this->stepScript();
			this->stepPhysic();
			break;

		case E_STATE_CLOSING:
			PRINT_ALERT( MSG_ALERT_STEP_CLOSING );
			return this->State();

		default:
			PRINT_ERROR( MSG_ERROR_WRONG_STATE );
			return this->State();
	}

	this->stepCount++;

	PRINT_DEBUG( "Ending step" );
	return this->State( E_STATE_RUNNING );
}


EngineState	Engine::stepRender()
{
	PRINT_DEBUG( "Handling Rendering" );
	return E_STATE_RUNNING;
}
EngineState	Engine::stepInputs()
{
	PRINT_DEBUG( "Handling Inputs" );
	return E_STATE_RUNNING;
}
EngineState	Engine::stepScript()
{
	PRINT_DEBUG( "Handling Scripts" );
	return E_STATE_RUNNING;
}
EngineState	Engine::stepPhysic()
{
	PRINT_DEBUG( "Handling Physics" );
	return E_STATE_RUNNING;
}