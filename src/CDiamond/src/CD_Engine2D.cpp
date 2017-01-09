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

#include "CD_Engine2D.h"
#include "CD_Game2D.h"
using namespace Diamond;

static Config config;
static Engine2D* engine = nullptr;

void dEngine2DConfigureGraphics(char* windowTitle,
                                int windowWidth,
                                int windowHeight,
                                bool fullscreen,
                                bool vsync) {
    config.game_name = windowTitle;
    config.window_width = windowWidth;
    config.window_height = windowHeight;
    config.fullscreen = fullscreen;
    config.vsync = vsync;
}

void dEngine2DConfigureAudio(int numChannels,
                             int frequency,
                             int sampleSize) {
    config.audio_channels = numChannels < 2 ? D_MONO : D_STEREO;
    config.audio_out_freq = frequency;
    config.audio_out_sample_size = sampleSize;
}

bool dEngine2DInit() {
    bool success = true;
    engine = new Engine2D(config, success);

    if (!success) {
        delete engine;
        engine = nullptr;
    }

    return success;
}

void dEngine2DDestroy() {
    delete engine;
    engine = nullptr;
}

void dEngine2DLaunchGame() {
    auto game = dGame2DGetGame();
    if (engine && game) {
        engine->launch(*game);
    }
}

void dEngine2DQuitGame() {
    if (engine)
        engine->quit();
}

Engine2D* dEngine2DGetEngine() {
    return engine;
}
