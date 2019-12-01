///-------------------------------------------------------------------------------------------------
// file: ProjectEngine.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Project Engine
///-------------------------------------------------------------------------------------------------
#ifndef _PROJECTENGINE_H_
#define _PROJECTENGINE_H_
#pragma once

#include "ISystem.h"
class Player;
class ProjectEngine final : public ISystem
{
	Player* playerScript = nullptr;
	std::string levelFile = "../Assets/Levels/level1.json";
	bool loaded = false;
public:
    void initialize() override;
    void update(float deltaTime)override;
	void setPlayer(Player* _player) { playerScript = _player; }
    DECLARE_SINGLETON(ProjectEngine)
};

#endif