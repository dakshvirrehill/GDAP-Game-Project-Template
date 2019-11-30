#pragma once
#include "Component.h"
#include "IRenderable.h"

class Player : public Component, public IRenderable
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

	virtual void render(sf::RenderWindow* _window) override;
	friend class RenderSystem;
};

