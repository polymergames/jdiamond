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

#ifndef D_CD_GAME2D_H
#define D_CD_GAME2D_H

#include "D_Game2D.h"

typedef void (*dGame2DVoidFunc)(void);
typedef void (*dGame2DUpdateFunc)(tD_delta);

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Turns on game benchmarking and sets the file to output results.
 * This should be called before dGame2DInit.
 */
void dGame2DBenchmark(char *filePath);

/**
 * Initializes the game. Should be called before calling dEngine2DLaunchGame.
 * Requires that dEngine2DInit has been called first.
 * Any/all of the parameters are allowed to be NULL.
 * Returns true if initialization was successful.
 */
bool dGame2DInit(dGame2DVoidFunc   initFunc,
                 dGame2DUpdateFunc updateFunc,
                 dGame2DUpdateFunc postPhysicsUpdateFunc,
                 dGame2DVoidFunc   quitFunc);

/**
 * Frees all game resources.
 * Should be called when the game ends along with dEngine2DDestroy.
 */
void dGame2DDestroy();

#ifdef __cplusplus
}
#endif

Diamond::Game2D* dGame2DGetGame();

#endif // D_CD_GAME2D_H
