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

#ifndef D_CD_UTIL_H
#define D_CD_UTIL_H

#include "D_typedefs.h"
#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

CDEXPORT tCD_Handle dPointList2DInit();

CDEXPORT void dPointList2DAddPoint(tCD_Handle list, tD_pos x, tD_pos y);

// pops the last element from the given point list
CDEXPORT void dPointList2DPop(tCD_Handle list);

CDEXPORT void dPointList2DClear(tCD_Handle list);

CDEXPORT void dPointList2DDelete(tCD_Handle list);

#ifdef __cplusplus
}
#endif

Diamond::PointList2D &dGetPointList(tCD_Handle list);

#endif // D_CD_UTIL_H
