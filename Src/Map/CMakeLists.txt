set(MAP_DIRECTORY Src/Map/)

set(MAP_SRC
    updateWalls.cpp
    wall.cpp
    models.cpp
    )

list(TRANSFORM MAP_SRC PREPEND ${MAP_DIRECTORY})