#include "RenderSystem.h"

#include <iostream>
#include <ostream>

#include "raylib.h"
#include "../Core/GameState.h"
#define RLIGHTS_IMPLEMENTATION
#include "rlight.h"
#include "raymath.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() const {
    _drawLight();
    BeginShaderMode(m_state.shader);
    _drawSpace();
    _drawObstacles();
    _drawPerson();
    EndShaderMode();
}

void RenderSystem::_drawLight() const {
    static Light light = CreateLight(
        LIGHT_POINT,
        m_state.light.position,
        Vector3Zero(),
        m_state.light.color,
        m_state.shader
    );
    light.position = m_state.light.position;
    UpdateLightValues(m_state.shader, light);
}

void RenderSystem::_drawSpace() const {
    DrawPlane(m_state.space.centre, m_state.space.size,BROWN);
}

void RenderSystem::_drawObstacles() const {
    int count = 0;
    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            for (int k = 1; k <= m_state.obstacles[count].layer; k++) {
                const float cubeX = i * m_state.obstacles[count].length;
                const float cubeZ = j * m_state.obstacles[count].width;
                const float cubeY = (k - 1) * m_state.obstacles[count].height + m_state.obstacles[count].height / 2;
                DrawCube({cubeX, cubeY, cubeZ},
                         m_state.obstacles[count].width, m_state.obstacles[count].height,
                         m_state.obstacles[count].length,WHITE);
                DrawCubeWires({cubeX, cubeY, cubeZ},
                              m_state.obstacles[count].width, m_state.obstacles[count].height,
                              m_state.obstacles[count].length,BLACK);
            }
            count++;
        }
    }
}

void RenderSystem::_drawPerson() const {
    const float height=m_state.camera.position.y-3.50;
    DrawCube({.x = m_state.camera.position.x, .y = height, .z = m_state.camera.position.z},
        m_state.player.width,m_state.player.height,m_state.player.length,GREEN);
}