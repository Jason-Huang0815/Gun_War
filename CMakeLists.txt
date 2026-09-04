cmake_minimum_required(VERSION 4.3)
project(GunWar)

set(CMAKE_CXX_STANDARD 26)

add_executable(GunWar
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Core/GameState.h
        src/Core/GameRules.cpp
        src/Core/GameRules.h
        src/Managers/SceneManager.cpp
        src/Managers/SceneManager.h
        src/Managers/ResourceManager.cpp
        src/Managers/ResourceManager.h
        src/Systems/InputSystem.cpp
        src/Systems/InputSystem.h
        src/Systems/PhysicsSystem.cpp
        src/Systems/PhysicsSystem.h
        src/Systems/RenderSystem.cpp
        src/Systems/RenderSystem.h

)
target_include_directories(GunWar PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib-6.0/include
)

target_link_directories(GunWar PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib-6.0/lib
)

target_link_libraries(GunWar
        raylib
)

if (WIN32)
    target_link_libraries(GunWar
            winmm
            gdi32
            opengl32
    )
endif ()