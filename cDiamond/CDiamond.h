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

#ifndef D_CDIAMOND_H
#define D_CDIAMOND_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Sets the game window's title.
     */
    void configureName(char* gameName);

    void configureGraphics(int windowWidth,
                           int windowHeight,
                           bool fullscreen,
                           bool vsync);

    /**
     * numChannels should be 1 or 2, for mono or stereo, respectively.
     * frequency is in hertz.
     * sampleSize is in bytes.
     */
    void configureAudio(int numChannels,
                        int frequency,
                        int sampleSize);

    /**
     * Initializes the game engine and all subsystems.
     * Call configure_ functions before calling this.
     * Must call this before using any other engine functions.
     */
    bool initEngine();

    /**
     * Frees all engine/game resources and ends the game.
     */
    void shutdownEngine();


#ifdef __cplusplus
}
#endif

#endif // D_CDIAMOND_H
