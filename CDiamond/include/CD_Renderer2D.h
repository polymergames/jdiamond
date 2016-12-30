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

#include "D_Renderer2D.h"
#include "CD_typedefs.h"

typedef int tCD_RenderLayer;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Call this before using any other renderer functions.
 * Requires that dEngine2DInit was called first.
 */
bool dRenderer2DInit();

void dRenderer2DDestroy();

/**
 * Returns CD_INVALID_HANDLE if texture failed to load.
 */
tCD_Handle dRenderer2DLoadTexture(char* path);

void dRenderer2DDestroyTexture(tCD_Handle texture);

Diamond::SharedPtr<Diamond::Texture>&
dRenderer2DGetTexture(tCD_Handle texture);


tCD_Handle dRenderer2DMakeRenderComponent(tCD_Handle transform,
                                          tCD_Handle texture,
                                          tCD_RenderLayer layer);

void dRenderer2DDestroyRenderComponent(tCD_Handle renderComponent);

Diamond::SharedPtr<Diamond::RenderComponent2D>&
dRenderComponent2DGetRenderComponent(tCD_Handle renderComponent);

void dRenderComponent2DSetSprite(tCD_Handle renderComponent,
                                 tCD_Handle texture);

tCD_RenderLayer dRenderComponent2DGetLayer(tCD_Handle renderComponent);
void dRenderComponent2DSetLayer(tCD_Handle renderComponent,
                                tCD_RenderLayer newLayer);

dVector2f dRenderComponent2DGetPivot(tCD_Handle renderComponent);
void dRenderComponent2DSetPivot(tCD_Handle renderComponent,
                                dVector2f newPivot);

void dRenderComponent2DFlipX(tCD_Handle renderComponent);
void dRenderComponent2DFlipY(tCD_Handle renderComponent);

bool dRenderComponent2DIsFlippedX(tCD_Handle renderComponent);
bool dRenderComponent2DIsFlippedY(tCD_Handle renderComponent);


#ifdef __cplusplus
}
#endif

#endif // D_CD_RENDERER2D_H
