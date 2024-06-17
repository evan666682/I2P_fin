#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"///////////
#include "Engine/Group.hpp"
#include "Bullet/SlowBullet.hpp"///////
#include "TypeCTurret.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int TypeCTurret::Price = 1000;
TypeCTurret::TypeCTurret(float x, float y) :
	Turret("play/tower-base.png", "play/turret-6.png", x, y, 300, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
	//for slow down bullet 
	slowFactor = 0.5f;  // 50% slow down
    slowDuration = 2.0f;  // Slow down for 2 seconds
}

void TypeCTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	Engine::Point normal = Engine::Point(-normalized.y, normalized.x);
	// Change bullet position to the front of the gun barrel.
	getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position + normalized * 36 - normal * 6, diff, rotation, this, slowFactor, slowDuration));
	getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position + normalized * 36 + normal * 6, diff, rotation, this, slowFactor, slowDuration));
	AudioHelper::PlayAudio("laser.wav");
}
