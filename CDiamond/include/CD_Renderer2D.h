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

#ifndef D_CD_RENDERER2D_H
#define D_CD_RENDERER2D_H

#include "CD_typedefs.h"

typedef int tCD_RenderLayer;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns INVALID_HANDLE if texture failed to load.
 */
tCD_Handle dRenderer2DLoadTexture(char* path);

void dRenderer2DDestroyTexture(tCD_Handle texture);


tCD_Handle dRenderer2DMakeRenderComponent(tCD_Handle transform,
                                          tCD_Handle texture,
                                          tCD_RenderLayer layer);

void dRenderer2DDestroyRenderComponent(tCD_Handle renderComponent);


/**
 * Renders all the render components currently in the renderer.
 */
void dRenderer2DRenderAll();


tCD_Handle dRenderComponent2DGetSprite();
void dRenderComponent2DSetSprite(tCD_Handle texture);

tCD_RenderLayer dRenderComponent2DGetLayer();
void dRenderComponent2DSetLayer(tCD_RenderLayer newLayer);

void dRenderComponent2DFlipX();
void dRenderComponent2DFlipY();

bool dRenderComponent2DIsFlippedX();
bool dRenderComponent2DIsFlippedY();


#ifdef __cplusplus
}
#endif

#endif // D_CD_RENDERER2D_H
