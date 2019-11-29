#pragma once
#include "Component.h"
class Player : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Player, Component)

public:
	sf::Sprite playerSprite;
	sf::Texture spriteTexture;
	float moveSpeed = 100;

protected:
	void initialize() override;

public:

	Player() = default;
	~Player() = default;
	void update(float deltaTime) override;
	void load(json::JSON& node) override;
};

