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

#ifndef D_CD_TRANSFORM2_H
#define D_CD_TRANSFORM2_H

#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Call this before using any other transform functions.
 * Requires that dEngine2DInit was called first.
 */
bool dTransform2Init();

void dTransform2Destroy();

tCD_Handle dTransform2VMakeTransform(dVector2f position,
                                     float rotation,
                                     dVector2f scale);

tCD_Handle dTransform2MakeTransform(float positionX, float positionY,
                                    float rotation,
                                    float scaleX, float scaleY);

void dTransform2DestroyTransform(tCD_Handle transform);

dTransform2f dTransform2GetTransform(tCD_Handle transform);

Diamond::SharedPtr<Diamond::DTransform2>&
dTransform2GetTransformPtr(tCD_Handle transform);

void dTransform2VSetTransform(tCD_Handle transform,
                              dVector2f position,
                              float rotation,
                              dVector2f scale);
void dTransform2SetTransform(tCD_Handle transform,
                             float positionX, float positionY,
                             float rotation,
                             float scaleX, float scaleY);

void dTransform2VSetPosition(tCD_Handle transform, dVector2f position);
void dTransform2SetPosition(tCD_Handle transform,
                            float positionX, float positionY);

float dTransform2GetPositionX(tCD_Handle transform);
float dTransform2GetPositionY(tCD_Handle transform);

void dTransform2VAddPosition(tCD_Handle transform, dVector2f dpos);
void dTransform2AddPosition(tCD_Handle transform, float dx, float dy);

void dTransform2AddPositionX(tCD_Handle transform, float dx);
void dTransform2AddPositionY(tCD_Handle transform, float dy);

float dTransform2GetRotation(tCD_Handle transform);
void dTransform2SetRotation(tCD_Handle transform, float rotation);
void dTransform2AddRotation(tCD_Handle transform, float drotation);

void dTransform2VSetScale(tCD_Handle transform, dVector2f scale);
void dTransform2SetScale(tCD_Handle transform,
                         float scaleX, float scaleY);

float dTransform2GetScaleX(tCD_Handle transform);
float dTransform2GetScaleY(tCD_Handle transform);

#ifdef __cplusplus
}
#endif

#endif // D_CD_TRANSFORM2_H
