#ifndef DEBUG_HPP_
# define DEBUG_HPP_

# include <iostream>

typedef enum
{
	LOG_LEVEL_NONE,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_WARN,
	LOG_LEVEL_INFO,
	LOG_LEVEL_DEBUG
}						DebugLevel;

# define LOG_LEVEL_GLOBAL		LOG_LEVEL_DEBUG	// Change this to change what debug messages get displayed

bool		PRINT_ERROR( const std::string msg );
bool 		PRINT_WARN( const std::string msg );
bool		PRINT_INFO( const std::string msg );
bool		PRINT_DEBUG( const std::string msg );

#endif // DEBUG_HPP_