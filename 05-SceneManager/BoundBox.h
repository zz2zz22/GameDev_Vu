#pragma once

#include "GameUtils.h"
#include <vector>
class BoundBox {
private:
	std::vector<RECTF> _hitboxes;

public:
	RECTF GetBoundingBox(int = 0) const;
	float GetBoxOffsetX(int = 0) const;
	float GetBoxOffsetY(int = 0) const;
	float GetBoxWidth(int = 0) const;
	float GetBoxHeight(int = 0) const;

	void AddHitbox(RECTF);
};