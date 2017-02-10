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

#include "CD_Physics2D.h"

#include "duSparseVector.h"
#include "CD_Engine2D.h"
#include "CD_Transform2.h"
#include "CD_Util.h" // for pointlist
using namespace Diamond;

static PhysicsWorld2D *physWorld = nullptr;
static SparseVector<SharedPtr<Rigidbody2D>, tCD_Handle> rigidbodies;
static SparseVector<SharedPtr<AABBCollider2D>, tCD_Handle> aabbs;
static SparseVector<SharedPtr<CircleCollider>, tCD_Handle> circles;
static SparseVector<SharedPtr<PolyCollider>, tCD_Handle> polys;

bool dPhysics2DInit() {
    auto engine = dEngine2DGetEngine();
    if (engine) {
        physWorld = engine->getPhysWorld();
        return true;
    }
    return false;
}

void dPhysics2DDestroy() {
    physWorld = nullptr;
    rigidbodies.clear();
    aabbs.clear();
    circles.clear();
    polys.clear();
}

tCD_Handle dPhysics2DMakeRigidbody(tCD_Handle transform) {
    return rigidbodies.insert(physWorld->makeRigidbody(dTransform2GetTransformPtr(transform)));
}

void dPhysics2DDestroyRigidbody(tCD_Handle rigidbody) {
    rigidbodies.erase(rigidbody);
}

tCD_Handle dPhysics2DMakeAABBCollider(
    tCD_Handle rigidbody, tD_pos originX, tD_pos originY, tD_pos dimX, tD_pos dimY
) {
    return aabbs.insert(physWorld->makeAABBCollider(
        rigidbodies[rigidbody],
        nullptr, // parent
        [](void *other){}, // empty collision callback
        Vector2<tD_pos>(dimX, dimY),
        Vector2<tD_pos>(originX, originY)
    ));
}

void dPhysics2DDestroyAABBCollider(tCD_Handle aabb) {
    aabbs.erase(aabb);
}

void dPhysics2DSetAABBCollider(
    tCD_Handle aabb, tD_pos originX, tD_pos originY, tD_pos dimX, tD_pos dimY
) {
    aabbs[aabb]->setOrigin(Vector2<tD_pos>(originX, originY));
    aabbs[aabb]->setDims(Vector2<tD_pos>(dimX, dimY));
}

tCD_Handle dPhysics2DMakeCircleCollider(
    tCD_Handle rigidbody, tD_pos centerX, tD_pos centerY, tD_pos radius
) {
    return circles.insert(physWorld->makeCircleCollider(
        rigidbodies[rigidbody],
        nullptr,
        [](void *other){},
        radius,
        Vector2<tD_pos>(centerX, centerY)
    ));
}

void dPhysics2DDestroyCircleCollider(tCD_Handle circle) {
    circles.erase(circle);
}

void dPhysics2DSetCircleCollider(
    tCD_Handle circle, tD_pos centerX, tD_pos centerY, tD_pos radius
) {
    circles[circle]->setRadius(radius);
    circles[circle]->setCenter(Vector2<tD_pos>(centerX, centerY));
}

// construct points using functions in CD_Util
tCD_Handle dPhysics2DMakePolyCollider(
    tCD_Handle rigidbody, tCD_Handle points
) {
    return polys.insert(physWorld->makePolyCollider(
        rigidbodies[rigidbody],
        nullptr,
        [](void *other){},
        dGetPointList(points)
    ));
}

void dPhysics2DDestroyPolyCollider(tCD_Handle poly) {
    polys.erase(poly);
}

SharedPtr<Rigidbody2D> &dPhysics2DGetRigidbody(tCD_Handle rigidbody) {
    return rigidbodies[rigidbody];
}

SharedPtr<AABBCollider2D> &dPhysics2DGetAABBCollider(tCD_Handle aabb) {
    return aabbs[aabb];
}

SharedPtr<CircleCollider> &dPhysics2DGetCircleCollider(tCD_Handle circle) {
    return circles[circle];
}

SharedPtr<PolyCollider> &dPhysics2DGetPolyCollider(tCD_Handle poly) {
    return polys[poly];
}
