cmake_minimum_required(VERSION 3.29)
project(wumpus_pokorny_van_zant)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(wumpus_pokorny_van_zant
    src/entity.cpp
    src/entity.h
    src/main.cpp
    src/map.cpp
    src/map.h
        src/game.cpp
        src/game.h
        src/Entities/Player.cpp
        src/Entities/Player.h
        src/Entities/wumpus.cpp
        src/Entities/wumpus.h
        src/Feature.cpp
        src/Features/Vortex.h
        src/Features/Vortex.cpp
        src/Features/Pitfall.h
        src/Features/Pitfall.cpp
        src/Features/Loot.cpp)
