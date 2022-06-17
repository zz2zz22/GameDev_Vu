#include "Entity.h"
#include "Trigger.h"

void Trigger::_ParseSprites(std::string) {}

Trigger::Trigger() {
	isPassThroughable = true;
}

Trigger::~Trigger() {}

void Trigger::ParseData(
	std::string dataPath,
	Texture*& texture,
	std::vector<std::string> extraData)
{
	Entity::ParseData(dataPath, texture, extraData);
}

void Trigger::HandleStates() {}

void Trigger::HandleCollisionResult(LPCOLLISIONEVENT, D3DXVECTOR2&, D3DXVECTOR2&, D3DXVECTOR2&, D3DXVECTOR2&) {}

void Trigger::Update(
	DWORD deltaTime,
	std::vector<Entity*>* collidableEntities,
	std::vector<Entity*>* collidableTiles,
	Grid* grid)
{
	for (unsigned int i = 0; i < collidableEntities->size(); ++i) {
		Entity* entity = collidableEntities->at(i);
		if (entity->IsActive() && entity->GetHealth() > 0) {

		}
	}
}

void Trigger::Render() {}

void Trigger::Release() {}