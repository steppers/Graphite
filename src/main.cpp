#include "Engine/Systems/System.h"
#include "Engine/Engine.h"
#include "Engine/Systems/GraphicsSystem.h"

using namespace std;

int main(void) {
    Engine eng;

    GraphicsSystem* graphicsSystem = new GraphicsSystem(300, 300);
    graphicsSystem->setVSync(true);

    eng.addSystem(graphicsSystem);

    eng.debugMode(true);
    eng.start();

    return 0;
}