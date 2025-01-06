#include "game.h"

int main() {
    Game game;

    if (!game.initialize()) {
        return -1;
    }

    game.run();
    game.cleanup();
    return 0;
}
