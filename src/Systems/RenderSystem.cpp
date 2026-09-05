#include "RenderSystem.h"

#include "raylib.h"
#include "../Core/GameState.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    _drawSpace();
    _drawObstacles();
}

void RenderSystem::_drawSpace() const {
    DrawPlane(m_state.space.centre, m_state.space.size,WHITE);
}

void RenderSystem::_drawObstacles() const {
    int count = 0;
    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            for (int k = 1; k <= m_state.obstacles[count].layer; k++) {
                const float cubeX = i * m_state.obstacles[count].length;
                const float cubeZ = j * m_state.obstacles[count].width;
                const float cubeY = k * m_state.obstacles[count].height + m_state.obstacles[count].height / 2;
                DrawCube({cubeX, cubeY, cubeZ},
                         m_state.obstacles[count].width, m_state.obstacles[count].height,
                         m_state.obstacles[count].length,RED);
                DrawCubeWires({cubeX, cubeY, cubeZ},
                         m_state.obstacles[count].width, m_state.obstacles[count].height,
                         m_state.obstacles[count].length,BLACK);
            }
            count++;
        }
    }
}