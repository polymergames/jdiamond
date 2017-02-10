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

#include "CD_DebugDrawer.h"

#include "D_DebugDrawer2D.h"
#include "CD_Renderer2D.h"
#include "CD_Util.h"
using namespace Diamond;

static DebugDrawer *debug = nullptr;

bool dDebugDrawInit() {
    auto renderer = dRenderer2DGetRenderer();
    if (renderer) {
        debug = new DebugDrawer(renderer);
        return true;
    }
    return false;
}

void dDebugDrawDestroy() {
    delete debug;
}

void dDebugDrawCircle(tD_pos x, tD_pos y, tD_pos radius,
                      unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    CircleDef circle;
    circle.radius = radius;
    circle.center = Vector2<tD_pos>(x, y);
    debug->draw(circle, {r, g, b, a});
}

void dDebugDrawPoly(tCD_Handle pointList,
                    unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    debug->draw(dGetPointList(pointList), {r, g, b, a});
}
