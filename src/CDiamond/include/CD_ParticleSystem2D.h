/*
    Copyright 2017 Ahnaf Siddiqui

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

#ifndef D_CD_PARTICLESYSTEM2D_H
#define D_CD_PARTICLESYSTEM2D_H

#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Call this before using any other particle system functions.
 */
CDEXPORT bool dParticleSystem2DInit(int poolsize);

CDEXPORT void dParticleSystem2DDestroy();

CDEXPORT tCD_Handle dParticleSystem2DMakeEmitter(tCD_Handle config, tCD_Handle transform);

CDEXPORT void dParticleSystem2DDestroyEmitter(tCD_Handle emitter);

CDEXPORT void dParticleSystem2DUpdate(tD_delta delta);

#ifdef __cplusplus
}
#endif

#endif // D_CD_PARTICLESYSTEM2D_H
