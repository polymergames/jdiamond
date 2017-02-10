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

#include "CD_Util.h"
#include "duSparseVector.h"
using namespace Diamond;

static SparseVector<PointList2D, tCD_Handle> pointLists;

tCD_Handle dPointList2DInit() {
    return pointLists.emplace();
}

void dPointList2DAddPoint(tCD_Handle list, tD_pos x, tD_pos y) {
    pointLists[list].emplace_back(x, y);
}

void dPointList2DPop(tCD_Handle list) {
    pointLists[list].pop_back();
}

void dPointList2DClear(tCD_Handle list) {
    pointLists[list].clear();
}

void dPointList2DDelete(tCD_Handle list) {
    pointLists.erase(list);
}

PointList2D &dGetPointList(tCD_Handle list) {
    return pointLists[list];
}
