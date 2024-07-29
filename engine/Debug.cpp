#include "Debug.hpp"

bool		PRINT_ERR( const std::string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_ERROR )
	{
		std::cerr << "ERROR: " << msg << std::endl;
		return true;
	}	else return false;
}

bool 		PRINT_WARN( const std::string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_WARN )
	{
		std::cerr << "WARNING: " << msg << std::endl;
		return true;
	}	else return false;
}

bool		PRINT_INFO( const std::string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_INFO )
	{
		std::cout << "INFO: " << msg << std::endl;
		return true;
	}	else return false;
}

bool		PRINT_DEBUG( const std::string msg )
{
	if ( LOG_LEVEL_GLOBAL >= LOG_LEVEL_DEBUG )
	{
		std::cout << "DEBUG: " << msg << std::endl;
		return true;
	}	else return false;
}