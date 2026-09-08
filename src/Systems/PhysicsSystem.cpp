#include "PhysicsSystem.h"

#include "../Core/GameState.h"

PhysicsSystem::PhysicsSystem(GameState &state) : m_state(state) {
}

void PhysicsSystem::update(const float dt) {
    _jump(dt);
    _squad();
}

void PhysicsSystem::_jump(const float dt) {
    if (m_state.motion == JUMP) {
        m_state.camera.position.y += m_velocity * dt;
        m_velocity -= m_gravity * dt;
        if (m_state.camera.position.y <= m_originHeight) {
            m_state.camera.position.y = m_originHeight;
            m_velocity = 8.0f;
            m_state.motion = STAND;
        }
    }
}

void PhysicsSystem::_squad() const {
    if (m_state.motion == SQUAD) {
        m_state.camera.position.y =m_originHeight-2;
    }else if (m_state.motion !=JUMP) {
        m_state.camera.position.y = m_originHeight;
    }
}
