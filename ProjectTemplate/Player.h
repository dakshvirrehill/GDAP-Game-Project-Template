#pragma once
#include "Component.h"

class Player : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Player, Component)

public:
	sf::Sprite playerSprite;
	sf::Texture spriteTexture;
	float moveSpeed = 50;

protected:
	void initialize() override;

public:
	Player() = default;
	~Player() = default;
	void update(float deltaTime) override;
	void load(json::JSON& node) override;
	void onTriggerEnter(const Collision* const collisionData) override;
	void setEnabled(bool _enabled) override;
};

