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

#ifndef D_CD_ANIMATION2D_H
#define D_CD_ANIMATION2D_H

#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

CDEXPORT tCD_Handle dAnimation2DLoadAnimationSheet(
    tCD_Handle spritesheet, tD_delta frameLength, int numFrames, int rows, int cols
);

CDEXPORT void dAnimation2DDestroyAnimationSheet(tCD_Handle animationSheet);

CDEXPORT tCD_Handle dAnimation2DMakeAnimatorSheet(
    tCD_Handle renderComponent, tCD_Handle animationSheet
);

CDEXPORT void dAnimation2DDestroyAnimatorSheet(tCD_Handle animatorSheet);

// Sets the given animator's animation to the given animation sheet
CDEXPORT void dAnimation2DSetAnimationSheet(
    tCD_Handle animatorSheet, tCD_Handle animationSheet
);

// Updates all animations for the current frame
CDEXPORT void dAnimation2DUpdate(tD_delta delta);

#ifdef __cplusplus
}
#endif

#endif // D_CD_ANIMATION2D_H
