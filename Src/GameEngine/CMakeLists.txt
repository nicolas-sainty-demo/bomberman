set(GAME_ENGINE_DIRECTORY Src/GameEngine/)

set(GAME_ENGINE_SRC
    bombs.cpp
    game.cpp
    explosions.cpp
    )

list(TRANSFORM GAME_ENGINE_SRC PREPEND ${GAME_ENGINE_DIRECTORY})