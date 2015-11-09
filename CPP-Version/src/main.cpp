#include "UI/Window.h"
#include "Engine/Systems/System.h"
#include "Engine/Engine.h"
#include "Engine/Systems/GraphicsSystem.h"

using namespace std;

int main(void) {
    Engine eng;

    eng.addSystem(new GraphicsSystem(300, 300));

    eng.debugMode(true);
    eng.start();

    return 0;
}