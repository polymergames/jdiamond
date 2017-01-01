/*
    Copyright 2016 Ahnaf Siddiqui

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "CD_Game2D.h"
#include "CD_Engine2D.h"
using namespace Diamond;

template <typename FVoid, typename FUpdate>
class CDGame : public Game2D {
public:
    CDGame(Engine2D& engine,
           FVoid initFunc = nullptr,
           FUpdate updateFunc = nullptr,
           FUpdate postPhysicsUpdateFunc = nullptr,
           FVoid quitFunc = nullptr)
        : Game2D(engine),
          updateFunc(updateFunc),
          postPhysicsUpdateFunc(postPhysicsUpdateFunc),
          quitFunc(quitFunc) {

        if (initFunc) initFunc();
    }

    void update(tD_delta delta) override {
        if (updateFunc) updateFunc(delta);
    }

    void postPhysicsUpdate(tD_delta delta) override {
        if (postPhysicsUpdateFunc) postPhysicsUpdateFunc(delta);
    }

    void quit() override {
        if (quitFunc) quitFunc();
    }

  private:
      FUpdate updateFunc;
      FUpdate postPhysicsUpdateFunc;
      FVoid quitFunc;
};


static Game2D* game = nullptr;

bool dGame2DInit(dGame2DVoidFunc   initFunc,
                 dGame2DUpdateFunc updateFunc,
                 dGame2DUpdateFunc postPhysicsUpdateFunc,
                 dGame2DVoidFunc   quitFunc) {
    auto engine = dEngine2DGetEngine();
    if (engine) {
        game = new CDGame<dGame2DVoidFunc, dGame2DUpdateFunc>(
            *engine, initFunc, updateFunc, postPhysicsUpdateFunc, quitFunc
        );
        return true;
    }
    return false;
}

void dGame2DDestroy() {
    delete game;
    game = nullptr;
}

Game2D* dGame2DGetGame() {
    return game;
}
