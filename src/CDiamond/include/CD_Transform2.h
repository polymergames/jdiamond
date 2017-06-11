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
CDEXPORT bool dTransform2Init();

CDEXPORT void dTransform2Destroy();

CDEXPORT tCD_Handle dTransform2VMakeTransform(dVector2f position,
                                              float rotation,
                                              dVector2f scale);

CDEXPORT tCD_Handle dTransform2MakeTransform(float positionX, float positionY,
                                             float rotation,
                                             float scaleX, float scaleY);

CDEXPORT void dTransform2DestroyTransform(tCD_Handle transform);

CDEXPORT dTransform2f dTransform2GetTransform(tCD_Handle transform);

CDEXPORT void dTransform2VSetTransform(tCD_Handle transform,
                                       dVector2f position,
                                       float rotation,
                                       dVector2f scale);
CDEXPORT void dTransform2SetTransform(tCD_Handle transform,
                                      float positionX, float positionY,
                                      float rotation,
                                      float scaleX, float scaleY);

CDEXPORT void dTransform2VSetPosition(tCD_Handle transform, dVector2f position);
CDEXPORT void dTransform2SetPosition(tCD_Handle transform,
                                     float positionX, float positionY);

CDEXPORT float dTransform2GetPositionX(tCD_Handle transform);
CDEXPORT float dTransform2GetPositionY(tCD_Handle transform);

CDEXPORT void dTransform2VAddPosition(tCD_Handle transform, dVector2f dpos);
CDEXPORT void dTransform2AddPosition(tCD_Handle transform, float dx, float dy);

CDEXPORT void dTransform2AddPositionX(tCD_Handle transform, float dx);
CDEXPORT void dTransform2AddPositionY(tCD_Handle transform, float dy);

CDEXPORT float dTransform2GetRotation(tCD_Handle transform);
CDEXPORT void dTransform2SetRotation(tCD_Handle transform, float rotation);
CDEXPORT void dTransform2AddRotation(tCD_Handle transform, float drotation);

CDEXPORT void dTransform2VSetScale(tCD_Handle transform, dVector2f scale);
CDEXPORT void dTransform2SetScale(tCD_Handle transform,
                                  float scaleX, float scaleY);

CDEXPORT float dTransform2GetScaleX(tCD_Handle transform);
CDEXPORT float dTransform2GetScaleY(tCD_Handle transform);

#ifdef __cplusplus
}
#endif

Diamond::Transform2Ptr& dTransform2GetTransformPtr(tCD_Handle transform);

#endif // D_CD_TRANSFORM2_H
