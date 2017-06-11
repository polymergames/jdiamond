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

#ifndef D_CD_PHYSICS2D_H
#define D_CD_PHYSICS2D_H

#include "CD_typedefs.h"
#include "D_PhysicsWorld2D.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Call this before using any other physics functions.
 * Requires that dEngine2DInit was called first.
 */
CDEXPORT bool dPhysics2DInit();

CDEXPORT void dPhysics2DDestroy();

CDEXPORT tCD_Handle dPhysics2DMakeRigidbody(tCD_Handle transform);
CDEXPORT void dPhysics2DDestroyRigidbody(tCD_Handle rigidbody);

// TODO: take callback function pointers for collisions
CDEXPORT tCD_Handle dPhysics2DMakeAABBCollider(
    tCD_Handle rigidbody, tD_pos originX, tD_pos originY, tD_pos dimX, tD_pos dimY
);
CDEXPORT void dPhysics2DDestroyAABBCollider(tCD_Handle aabb);

CDEXPORT void dPhysics2DSetAABBCollider(
    tCD_Handle aabb, tD_pos originX, tD_pos originY, tD_pos dimX, tD_pos dimY
);

CDEXPORT tCD_Handle dPhysics2DMakeCircleCollider(
    tCD_Handle rigidbody, tD_pos centerX, tD_pos centerY, tD_pos radius
);
CDEXPORT void dPhysics2DDestroyCircleCollider(tCD_Handle circle);

CDEXPORT void dPhysics2DSetCircleCollider(
    tCD_Handle circle, tD_pos centerX, tD_pos centerY, tD_pos radius
);

// construct points using functions in CD_Util
CDEXPORT tCD_Handle dPhysics2DMakePolyCollider(
    tCD_Handle rigidbody, tCD_Handle points
);
CDEXPORT void dPhysics2DDestroyPolyCollider(tCD_Handle poly);

#ifdef __cplusplus
}
#endif

Diamond::DumbPtr<Diamond::Rigidbody2D> &dPhysics2DGetRigidbody(tCD_Handle rigidbody);
Diamond::DumbPtr<Diamond::AABBCollider2D> &dPhysics2DGetAABBCollider(tCD_Handle aabb);
Diamond::DumbPtr<Diamond::CircleCollider> &dPhysics2DGetCircleCollider(tCD_Handle circle);
Diamond::DumbPtr<Diamond::PolyCollider> &dPhysics2DGetPolyCollider(tCD_Handle poly);

#endif // D_CD_PHYSICS2D_H
