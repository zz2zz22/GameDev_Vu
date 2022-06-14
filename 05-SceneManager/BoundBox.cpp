#include "BoundBox.h"
RECTF BoundBox::GetBoundingBox(int index) const {
	return _hitboxes.empty() ? RECTF() : _hitboxes.at(index);
}
float BoundBox::GetBoxOffsetX(int index) const {
	return GetBoundingBox(index).left;
}
float BoundBox::GetBoxOffsetY(int index) const {
	return GetBoundingBox(index).top;
}
float BoundBox::GetBoxWidth(int index) const {
	return GetBoundingBox(index).right;
}
float BoundBox::GetBoxHeight(int index) const {
	return GetBoundingBox(index).bottom;
}
void BoundBox::AddHitbox(RECTF hitbox) {
	_hitboxes.emplace_back(hitbox);
}