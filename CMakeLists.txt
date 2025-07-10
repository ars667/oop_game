cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER "g++")

project(MyProject)

add_executable(final main.cpp player.cpp playerMovement.cpp cell.cpp field.cpp goodEvent.cpp badEvent.cpp teleportEvent.cpp makeLevel.cpp game.cpp control.cpp fileReader.cpp reader.cpp tracker.cpp draw.cpp winMessage.cpp output.cpp)