#include "RenderSystem.h"

#include "raylib.h"

RenderSystem::RenderSystem(GameState &state) : m_state(state) {
}

void RenderSystem::render() {
    DrawPlane({.x = 0,.y = 0,.z = 0},{.x = 100,.y = 100},WHITE);
    DrawCube({.x = 0,.y = 0.5,.z = 0},1,1,1,BLUE);
}