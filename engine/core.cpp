#include "core.hpp"
#include "Engine.hpp"

Engine	*getEngine()
{
	static Engine	NG = Engine();
	return &NG;
}


// CORE ENGINE LOOP
int	main	(int argc, char **argv)
{
	TIME_START;

	Engine	*NG = getEngine();
	NG->initialize( argc, argv );

	while ( true )
	{
		NG->stepGame();

		if ( NG->State() == E_STATE_CLOSING )
			break;

		if ( NG->State() == E_STATE_WRONG )
		{
			PRINT_ERROR( MSG_ERROR_WRONG_STATE );
			break;
		}
	}
	NG->shutdown();

	return 0;
}

// DEBUG FUNCTIONS
bool		PRINT_ERROR( const string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_ERROR )
	{
		LOG_ERR( msg.c_str() );
		return true;
	}	else return false;
}

bool 		PRINT_ALERT( const string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_ALERT )
	{
		LOG_WAR( msg.c_str() );
		return true;
	}	else return false;
}

bool		PRINT_DEBUG( const string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_DEBUG )
	{
		LOG_MSG( msg.c_str() );
		return true;
	}	else return false;
}