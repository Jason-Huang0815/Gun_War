#include "InputSystem.h"

#include "../Core/GameState.h"

InputSystem::InputSystem(GameState &state) : m_state(state) {
}

void InputSystem::update(const float dt) const {
    if (IsKeyPressed(KEY_SPACE))
        m_state.motion=JUMP;
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        m_state.motion=SQUAD;
    }else if (m_state.motion!=JUMP) {
        m_state.motion=STAND;
    }
}
