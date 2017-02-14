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

#include "CD_Animation2D.h"

#include "duSparseVector.h"
#include "duSwapVector.h"
#include "D_AnimatorSheet.h"
#include "CD_Renderer2D.h"
using namespace Diamond;

// TODO: refator engine so that animator is given an animation object
// instead of an animation pointer!
// for now, we have memory leaks if user doesn't free animations!
static SparseVector<AnimationSheet*, tCD_Handle> animationSheets;
static SwapVector<AnimatorSheet, tCD_Handle> animatorSheets;

tCD_Handle dAnimation2DLoadAnimationSheet(
    tCD_Handle spritesheet, tD_delta frameLength, int numFrames, int rows, int cols
) {
    auto sheet = new AnimationSheet();
    sheet->sprite_sheet = dRenderer2DGetTexture(spritesheet);
    sheet->frame_length = frameLength;
    sheet->num_frames = numFrames;
    sheet->rows = rows;
    sheet->columns = cols;
    return animationSheets.insert(sheet);
}

void dAnimation2DDestroyAnimationSheet(tCD_Handle animationSheet) {
    delete animationSheets[animationSheet];
    animationSheets.erase(animationSheet);
}

tCD_Handle dAnimation2DMakeAnimatorSheet(
    tCD_Handle renderComponent, tCD_Handle animationSheet
) {
    return animatorSheets.emplace(dRenderComponent2DGetRenderComponent(renderComponent),
                                  animationSheets[animationSheet]);
}

void dAnimation2DDestroyAnimatorSheet(tCD_Handle animatorSheet) {
    animatorSheets.erase(animatorSheet);
}

// Sets the given animator's animation to the given animation sheet
void dAnimation2DSetAnimationSheet(
    tCD_Handle animatorSheet, tCD_Handle animationSheet
) {
    animatorSheets[animatorSheet].setAnimation(animationSheets[animationSheet]);
}

// Updates all animations for the current frame
void dAnimation2DUpdate(tD_delta delta) {
    for (auto i = animatorSheets.begin(); i != animatorSheets.end(); ++i) {
        i->update(delta);
    }
}
