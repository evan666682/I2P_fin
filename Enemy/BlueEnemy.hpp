#ifndef BlueEnemy_HPP
#define BlueEnemy_HPP
#include "Enemy.hpp"

class BlueEnemy : public Enemy {
public:
	BlueEnemy(int x, int y);
	///for teleport
	void Update(float deltaTime) override;
private:
    float teleportCooldown; // cooldown
    float teleportTimer;    // timer for tele
    float teleportDistance; // how far
};
#endif // BlueEnemy_HPP
