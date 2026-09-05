/**
 * @file RenderSystem.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief only to read the state and render things
 */

#ifndef GUNWAR_RENDERSYSTEM_H
#define GUNWAR_RENDERSYSTEM_H
#pragma once

class GameState;

class RenderSystem {
private:
    GameState &m_state;

public:
    explicit RenderSystem(GameState &state);

    void render();
};


#endif //GUNWAR_RENDERSYSTEM_H
