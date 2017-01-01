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

#include "CD_Transform2.h"

#include "duSparseVector.h"
#include "CD_Engine2D.h"
using namespace Diamond;

static Engine2D* engine = nullptr;
static SparseVector<SharedPtr<DTransform2>, tCD_Handle> transforms;

bool dTransform2Init() {
    engine = dEngine2DGetEngine();
    return engine != nullptr;
}

void dTransform2Destroy() {
    transforms.clear();
    // note: we don't own the engine, so we don't destroy it.
    // we were just borrowing a pointer to it.
    engine = nullptr;
}

tCD_Handle dTransform2VMakeTransform(dVector2f position,
                                     float rotation,
                                     dVector2f scale) {
    return transforms.insert(engine->makeTransform(Vector2<tD_pos>(position.x, position.y),
                                                   (tD_rot)rotation,
                                                   Vector2<tD_real>(scale.x, scale.y)));
}

tCD_Handle dTransform2MakeTransform(float positionX, float positionY,
                                    float rotation,
                                    float scaleX, float scaleY) {
    return transforms.insert(engine->makeTransform(Vector2<tD_pos>(positionX, positionY),
                                                   (tD_rot)rotation,
                                                   Vector2<tD_real>(scaleX, scaleY)));
}

void dTransform2DestroyTransform(tCD_Handle transform) {
    // SparseVector.erase doesn't immediately destroy the element,
    // so we set it to nullptr to make sure it's destroyed.
    transforms[transform] = nullptr;
    transforms.erase(transform);
}

dTransform2f dTransform2GetTransform(tCD_Handle transform) {
    auto trans = transforms[transform].get();
    return {{trans->position.x, trans->position.y},
            trans->rotation,
            {trans->scale.x, trans->scale.y}};
}

SharedPtr<DTransform2> &dTransform2GetTransformPtr(tCD_Handle transform) {
    return transforms[transform];
}

void dTransform2VSetTransform(tCD_Handle transform,
                              dVector2f position,
                              float rotation,
                              dVector2f scale) {
    auto trans = transforms[transform].get();
    trans->position.x = position.x;
    trans->position.y = position.y;
    trans->rotation   = rotation;
    trans->scale.x    = scale.x;
    trans->scale.y    = scale.y;
}

void dTransform2SetTransform(tCD_Handle transform,
                             float positionX, float positionY,
                             float rotation,
                             float scaleX, float scaleY) {
    auto trans = transforms[transform].get();
    trans->position.x = positionX;
    trans->position.y = positionY;
    trans->rotation   = rotation;
    trans->scale.x    = scaleX;
    trans->scale.y    = scaleY;
}

void dTransform2VSetPosition(tCD_Handle transform, dVector2f position) {
    auto trans = transforms[transform].get();
    trans->position.x = position.x;
    trans->position.y = position.y;
}

void dTransform2SetPosition(tCD_Handle transform,
                            float positionX, float positionY) {
    auto trans = transforms[transform].get();
    trans->position.x = positionX;
    trans->position.y = positionY;
}

float dTransform2GetPositionX(tCD_Handle transform) {
    return transforms[transform]->position.x;
}

float dTransform2GetPositionY(tCD_Handle transform) {
    return transforms[transform]->position.y;
}

void dTransform2VAddPosition(tCD_Handle transform, dVector2f dpos) {
    transforms[transform]->position.x += dpos.x;
    transforms[transform]->position.y += dpos.y;
}

void dTransform2AddPosition(tCD_Handle transform, float dx, float dy) {
    transforms[transform]->position.x += dx;
    transforms[transform]->position.y += dy;
}

void dTransform2AddPositionX(tCD_Handle transform, float dx) {
    transforms[transform]->position.x += dx;
}

void dTransform2AddPositionY(tCD_Handle transform, float dy) {
    transforms[transform]->position.y += dy;
}

float dTransform2GetRotation(tCD_Handle transform) {
    return transforms[transform]->rotation;
}

void dTransform2SetRotation(tCD_Handle transform, float rotation) {
    transforms[transform]->rotation = rotation;
}

void dTransform2AddRotation(tCD_Handle transform, float drotation) {
    transforms[transform]->rotation += drotation;
}

void dTransform2VSetScale(tCD_Handle transform, dVector2f scale) {
    auto trans = transforms[transform].get();
    trans->scale.x = scale.x;
    trans->scale.y = scale.y;
}

void dTransform2SetScale(tCD_Handle transform,
                         float scaleX, float scaleY) {
    auto trans = transforms[transform].get();
    trans->scale.x = scaleX;
    trans->scale.y = scaleY;
}

float dTransform2GetScaleX(tCD_Handle transform) {
    return transforms[transform]->scale.x;
}

float dTransform2GetScaleY(tCD_Handle transform) {
    return transforms[transform]->scale.y;
}
