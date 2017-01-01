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

#ifndef D_CD_ENGINE2D_H
#define D_CD_ENGINE2D_H

#include "D_Engine2D.h"

#ifdef __cplusplus
extern "C" {
#endif

void dEngine2DConfigureGraphics(char* windowTitle,
                                int windowWidth,
                                int windowHeight,
                                bool fullscreen,
                                bool vsync);

/**
 * numChannels should be 1 or 2, for mono or stereo, respectively.
 * frequency is in hertz.
 * sampleSize is in bytes.
 */
void dEngine2DConfigureAudio(int numChannels,
                             int frequency,
                             int sampleSize);

/**
 * Initializes the game engine and all subsystems.
 * configure_ functions should be called before this
 * if custom configuration is needed.
 * Must call this before using any engine functions
 * or any subsystems (ex. dRenderer2D init and functions).
 * Returns true if initialization was successful.
 */
bool dEngine2DInit();

/**
 * Frees all engine resources.
 */
void dEngine2DDestroy();

/**
 * Launches the game in CD_Game2D and begins the game loop.
 * Requires that dGame2DInit was called first.
 */
void dEngine2DLaunchGame();

#ifdef __cplusplus
}
#endif

Diamond::Engine2D* dEngine2DGetEngine();

#endif // D_CD_ENGINE2D_H
