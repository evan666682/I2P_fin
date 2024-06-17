#include <string>
#include "BlueEnemy.hpp"
#include "Scene/PlayScene.hpp"
BlueEnemy::BlueEnemy(int x, int y) : Enemy("play/enemy-9.png", x, y, 10, 50, 5, 5),teleportCooldown(2.0f), teleportTimer(1.0f), teleportDistance(50.0f)  {

}

void BlueEnemy::Update(float deltaTime) {
    teleportTimer += deltaTime;
    if (teleportTimer >= teleportCooldown) {
        teleportTimer = 0.0f;

        // 计算传送位置
        if (!path.empty()) {
            Engine::Point target = path.back() * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
            Engine::Point direction = (target - Position).Normalize();
            Position = Position + direction * teleportDistance;

            // 更新路径，确保敌人不会卡住
            getPlayScene()->UpdateEnemyPath(this);
        }
    }

    // 调用基类的 Update 方法
    Enemy::Update(deltaTime);
}