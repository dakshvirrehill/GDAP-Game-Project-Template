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

class ProjectEngine final : public ISystem
{
public:
    void initialize() override;
    void update(float deltaTime)override;

    DECLARE_SINGLETON(ProjectEngine)
};

#endif