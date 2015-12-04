#include "Engine/Systems/System.h"
#include "Engine/Engine.h"
#include "Math/Vector2i.h"
#include "Engine/Managers/StateManager/StateManager.h"
#include "Engine/Systems/Graphics/GraphicsSystem.h"
#include "Engine/Prototyping/Tester.h"

using namespace std;

int main(void) {
//    Engine eng;
//
//    GraphicsSystem* graphicsSystem = new GraphicsSystem(300, 300);
//    graphicsSystem->setVSync(true);
//
//    eng.addSystem(graphicsSystem);
//
//    eng.debugMode(true);
//    eng.start();

    Tester tester;
    tester.Start();

//    Vector2i v1(3, 5);
//    Vector2i v2(3, 5);
//
//    StateManager& sm = StateManager::getInstance();
//
//    sm.registerForChanges(&v1, &v2);
//    sm.registerForChanges(&v2, &v1);
//
//    v2.setX(2);
//    v1.setY(3);
//
//    sm.distributeChanges();

    return 0;
}