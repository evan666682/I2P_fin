#ifndef SLOWBULLET_HPP
#define SLOWBULLET_HPP
#include <allegro5/base.h>
#include <list>

#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class SlowBullet : public Bullet {
protected:
	const float rotateRadian = 2 * ALLEGRO_PI;
	std::list<Bullet*>::iterator lockedBulletIterator;
	//
	float slowFactor;
	float slowDuration;
public:
	explicit SlowBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent,float slowFactor,float slowDuration);
	void Update(float deltaTime) override;
	void OnExplode(Enemy* enemy) override;
};
#endif // SLOWBULLET_HPP
