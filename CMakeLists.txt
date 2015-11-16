cmake_minimum_required(VERSION 3.3)
project(SSimCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(libs/glfw-3.1.2)
include_directories(libs/glfw-3.1.2/include)

set(SOURCE_FILES src/main.cpp src/UI/Window.cpp src/UI/Window.h src/Math/Vector2i.cpp src/Math/Vector2i.h src/Engine/Engine.cpp src/Engine/Engine.h src/UI/Input.cpp src/UI/Input.h src/Engine/Systems/System.h src/Engine/Framework/Scheduler.cpp src/Engine/Framework/Scheduler.h src/Engine/Managers/TaskManager/Task.h src/Engine/Managers/TaskManager/TaskManager.cpp src/Engine/Managers/TaskManager/TaskManager.h src/Engine/Managers/Manager.h src/Engine/Managers/StateManager.cpp src/Engine/Managers/StateManager.h src/Engine/Managers/EnvironmentManager.cpp src/Engine/Managers/EnvironmentManager.h src/Util/BlockingQueue.h src/Util/SThread.h src/Engine/Managers/TaskManager/TaskThread.cpp src/Engine/Managers/TaskManager/TaskThread.h src/Engine/Managers/TaskManager/TerminateTask.cpp src/Engine/Managers/TaskManager/TerminateTask.h src/Engine/Framework/Debug/Logger.cpp src/Engine/Framework/Debug/Logger.h src/Engine/Systems/GraphicsSystem.cpp src/Engine/Systems/GraphicsSystem.h src/Engine/Managers/InputManager.cpp src/Engine/Managers/InputManager.h)
add_executable(SSim ${SOURCE_FILES})

target_link_libraries(SSim glfw ${GLFW_LIBRARIES})