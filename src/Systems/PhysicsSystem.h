/**
 * @file PhysicsSystem.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief only to read the state and do something for real world
 */

#ifndef GUNWAR_PHYSICSSYSTEM_H
#define GUNWAR_PHYSICSSYSTEM_H
#pragma once

class GameState;

class PhysicsSystem {
private:
    GameState &m_state;

public:
    explicit PhysicsSystem(GameState &state);

    void update(float dt);
};


#endif //GUNWAR_PHYSICSSYSTEM_H
