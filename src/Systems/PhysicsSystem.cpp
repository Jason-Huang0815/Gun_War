#include "PhysicsSystem.h"

#include <iostream>
#include <ostream>

#include "../Core/GameState.h"

PhysicsSystem::PhysicsSystem(GameState &state) : m_state(state) {
}

void PhysicsSystem::update(const float dt) {
    if (m_state.motion == JUMP) {
        m_state.camera.position.y += m_velocity*dt;
        m_velocity -= m_gravity*dt;
        std::cout<<m_state.camera.position.y<<std::endl;
        if (m_state.camera.position.y <= m_originHeight) {
            m_state.camera.position.y = m_originHeight;
            m_velocity = 8.0f;
            m_state.motion = STAND;
        }
    }
}
