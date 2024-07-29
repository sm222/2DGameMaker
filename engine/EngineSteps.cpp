#include "Engine.hpp"

EngineState	Engine::stepGame()
{
	PRINT_DEBUG( "Begining step" );

	this->stepRender();
	this->stepInputs();
	this->stepScript();
	this->stepPhysic();

	this->stepCount++;

	PRINT_DEBUG( "Ending step" );
	return E_STATE_RUNNING;
}

EngineState	Engine::stepRender()
{
	PRINT_DEBUG( "Rendering" );
	return E_STATE_RUNNING;
}

EngineState	Engine::stepInputs()
{
	PRINT_DEBUG( "Inputs" );
	return E_STATE_RUNNING;
}

EngineState	Engine::stepScript()
{
	PRINT_DEBUG( "Script" );
	return E_STATE_RUNNING;
}

EngineState	Engine::stepPhysic()
{
	PRINT_DEBUG( "Physic" );
	return E_STATE_RUNNING;
}