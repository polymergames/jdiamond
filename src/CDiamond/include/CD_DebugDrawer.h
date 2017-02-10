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

#ifndef D_CD_DEBUG_DRAWER_H
#define D_CD_DEBUG_DRAWER_H

#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Requires that engine and renderer have been initialized first.
 */
CDEXPORT bool dDebugDrawInit();

CDEXPORT void dDebugDrawDestroy();

CDEXPORT void dDebugDrawCircle(tD_pos x, tD_pos y, tD_pos radius,
                               unsigned char r, unsigned char g, unsigned char b, unsigned char a);

CDEXPORT void dDebugDrawPoly(tCD_Handle pointList,
                             unsigned char r, unsigned char g, unsigned char b, unsigned char a);

#ifdef __cplusplus
}
#endif

#endif // D_CD_DEBUG_DRAWER_H
