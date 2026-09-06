#include "Game.h"

#include "Core/GameRules.h"
#include "Core/GameState.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/RenderSystem.h"

Game::Game() {
    m_state=std::make_unique<GameState>();
    m_input=std::make_unique<InputSystem>(*m_state);
    m_physics=std::make_unique<PhysicsSystem>(*m_state);
    m_render=std::make_unique<RenderSystem>(*m_state);
    InitWindow(m_state->screen.width,m_state->screen.height,"GunWar");
    SetTargetFPS(60);
    m_state->initCamera();
}

Game::~Game() {
    m_input.reset();
    m_physics.reset();
    m_render.reset();
    m_state->reset();
    CloseWindow();
}

void Game::run() const {
    m_state->reset();
    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();
        _update(dt);
        _render();
        //GameRules::CheckLoseCondition();
        //GameRules::CheckWinCondition();
    }
}

void Game::_update(const float dt) const {
    m_input->update(dt);
    m_physics->update(dt);
}

void Game::_render() const {
    UpdateCamera(&m_state->camera,CAMERA_FIRST_PERSON);
    BeginDrawing();
    ClearBackground(SKYBLUE);
        BeginMode3D(m_state->camera);
            m_render->render();
        EndMode3D();
    EndDrawing();
}