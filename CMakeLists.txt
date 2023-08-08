cmake_minimum_required(VERSION 3.16)

project("Nest2D")

set(CMAKE_CXX_STANDARD 14)

set(BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(Nest2D
    src/main.cpp 
    src/Application/Application.hpp
    src/Application/Application.cpp
    src/Game/World.hpp
    src/Game/World.cpp
    src/Game/Level.hpp
    src/Game/Direction.hpp
    src/Game/GameObject/GameObject.hpp
    src/Game/GameObject/GameObject.cpp
    src/Game/Core/Camera.hpp
    src/Game/Core/Camera.cpp
    src/Game/Core/GovnoCollisionDetector.hpp
    src/Game/Core/GovnoCollisionDetector.cpp
    src/Game/Core/Sprite.hpp
    src/Game/Core/Sprite.cpp
    src/Game/Levels/MenuLevel.hpp
    src/Game/Levels/MenuLevel.cpp
    src/Game/LevelManager/LevelManager.hpp
    src/Game/LevelManager/LevelManager.cpp
    src/Game/Levels/SimulationLevel.hpp
    src/Game/Levels/SimulationLevel.cpp
    src/Game/Scripts/Menu.hpp
    src/Game/Scripts/Menu.cpp
    src/Game/Scripts/Square.hpp
    src/Game/Scripts/Square.cpp
    src/Game/Scripts/Player.hpp
    src/Game/Scripts/Player.cpp
    src/Renderer/imgui_impl/imgui_impl_glfw.h
    src/Renderer/imgui_impl/imgui_impl_glfw.cpp
    src/Renderer/imgui_impl/imgui_impl_opengl3.h
    src/Renderer/imgui_impl/imgui_impl_opengl3.cpp
    src/Renderer/imgui_impl/imgui_impl_opengl3_loader.h
    src/Renderer/ImGui.hpp
    src/Renderer/ImGui.cpp
    src/Renderer/Renderer.hpp
    src/Renderer/Renderer.cpp
    src/Renderer/IndexBuffer.cpp
    src/Renderer/IndexBuffer.hpp
    src/Renderer/Mesh.cpp
    src/Renderer/Mesh.hpp
    src/Renderer/Shader.cpp
    src/Renderer/Shader.hpp
    src/Renderer/Texture.cpp
    src/Renderer/Texture.hpp
    src/Renderer/VertexArray.cpp
    src/Renderer/VertexArray.hpp
    src/Renderer/VertexBuffer.cpp
    src/Renderer/VertexBuffer.hpp
    src/Renderer/VertexBufferLayout.hpp
    src/Window/Key.hpp
    src/Window/Window.cpp
    src/Window/Window.hpp
    src/Physics/Physics.hpp
    src/Physics/Physics.cpp
    include/AMSTL/Vector2.hpp)

target_include_directories(Nest2D PRIVATE src)
target_include_directories(Nest2D PRIVATE include)

# GLFW
add_subdirectory(vendor/glfw)

target_link_libraries(Nest2D glfw)
target_include_directories(Nest2D PRIVATE vendor/glfw/include)

# GLAD
add_subdirectory(vendor/glad)

target_link_libraries(Nest2D glad)
target_include_directories(Nest2D PRIVATE vendor/glad/include)

# GLM
add_subdirectory(vendor/glm)

target_link_libraries(Nest2D glm)
target_include_directories(Nest2D PRIVATE vendor/glm)

# STB_IMAGE
add_subdirectory(vendor/stb_image)

target_link_libraries(Nest2D stb_image)
target_include_directories(Nest2D PRIVATE vendor/stb_image)

# imgui
add_subdirectory(vendor/imgui)

target_link_libraries(Nest2D imgui)
target_include_directories(Nest2D PRIVATE vendor/imgui)

# set output directories for all builds (Debug, Release, etc.)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set_target_properties(Nest2D
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIRECTORY}
    )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )