#include "Engine.hpp"


Engine	*getEngine()
{
	static Engine	*NG = new Engine();

	return NG;
}


int	main	(int argc, char **argv)
{
	Engine	*NG = getEngine();

	NG->initialize( argc, argv );

	while ( true )
	{
		NG->stepGame();

		if ( NG->State() == E_STATE_SHUTDOWN )
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