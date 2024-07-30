#ifndef CORE_HPP_
# define CORE_HPP_

# include "../inc/CPPDefine.hpp"

typedef enum
{
	LOG_LEVEL_NONE,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_ALERT,
	LOG_LEVEL_DEBUG
}						DebugLevel;

# define LOG_LEVEL_GLOBAL		LOG_LEVEL_DEBUG // NOTE : Change this to change what debug messages get displayed

bool		PRINT_ERROR( const string msg );
bool 		PRINT_ALERT( const string msg );
bool		PRINT_DEBUG( const string msg );

#endif // CORE_HPP_