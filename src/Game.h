/**
 * @file Game.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief the main loop of the whole project
 */

#ifndef GUNWAR_GAME_H
#define GUNWAR_GAME_H
#pragma once
#include<raylib.h>
#include<memory>

class GameState;
class InputSystem;
class PhysicsSystem;
class RenderSystem;

class Game {
private:
    std::unique_ptr<GameState> m_state;
    std::unique_ptr<InputSystem> m_input;
    std::unique_ptr<PhysicsSystem> m_physics;
    std::unique_ptr<RenderSystem> m_render;

    void _update(float dt) const;

    void _render() const;

public:
    Game();

    ~Game();

    void run() const;
};


#endif //GUNWAR_GAME_H
