#ifndef TYPECTURRET_HPP
#define TYPECTURRET_HPP
#include "Turret.hpp"

class TypeCTurret: public Turret {
public:
    float slowFactor ;  
    float slowDuration ;  
	static const int Price;
    TypeCTurret(float x, float y);
    void CreateBullet() override;
};
#endif // TYPECTURRET_HPP
