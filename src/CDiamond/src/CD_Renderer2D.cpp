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

#include "CD_Renderer2D.h"

#include "duSparseVector.h"
#include "CD_Engine2D.h"
#include "CD_Transform2.h"
using namespace Diamond;

static Renderer2D* renderer = nullptr;
static TextureFactory* textureFactory = nullptr;
static SparseVector<SharedPtr<RenderComponent2D>, tCD_Handle> renderComponents;
static SparseVector<SharedPtr<Texture>, tCD_Handle> textures;

bool dRenderer2DInit() {
    auto engine = dEngine2DGetEngine();
    if (engine) {
        renderer = engine->getRenderer();
        textureFactory = new TextureFactory(renderer);
    }
    return renderer != nullptr;
}

void dRenderer2DDestroy() {
    renderComponents.clear();
    textures.clear();
    renderer = nullptr;
}

tCD_Handle dRenderer2DLoadTexture(char* path) {
    auto texture = textureFactory->loadTexture(path);
    if (!texture) return CD_INVALID_HANDLE;
    return textures.insert(texture);
}

void dRenderer2DDestroyTexture(tCD_Handle texture) {
    textures.erase(texture);
}

SharedPtr<Texture>& dRenderer2DGetTexture(tCD_Handle texture) {
    return textures[texture];
}

tCD_Handle dRenderer2DMakeRenderComponent(tCD_Handle transform,
                                          tCD_Handle texture,
                                          tCD_RenderLayer layer) {
    return renderComponents.insert(
        renderer->makeRenderComponent(dTransform2GetTransformPtr(transform),
                                      textures[texture],
                                      (RenderLayer)layer)
    );
}

void dRenderer2DDestroyRenderComponent(tCD_Handle renderComponent) {
    // SparseVector.erase doesn't immediately destroy the element,
    // so we set it to nullptr to make sure it's destroyed.
    renderComponents[renderComponent] = nullptr;
    renderComponents.erase(renderComponent);
}

SharedPtr<RenderComponent2D>&
dRenderComponent2DGetRenderComponent(tCD_Handle renderComponent) {
    return renderComponents[renderComponent];
}

void dRenderComponent2DSetSprite(tCD_Handle renderComponent,
                                 tCD_Handle texture) {
    renderComponents[renderComponent]->setSprite(textures[texture]);
}

tCD_RenderLayer dRenderComponent2DGetLayer(tCD_Handle renderComponent) {
    (tCD_RenderLayer)(renderComponents[renderComponent]->getLayer());
}
void dRenderComponent2DSetLayer(tCD_Handle renderComponent,
                                tCD_RenderLayer newLayer) {
    renderComponents[renderComponent]->setLayer((RenderLayer)newLayer);
}

dVector2f dRenderComponent2DGetPivot(tCD_Handle renderComponent) {
    auto pivot = renderComponents[renderComponent]->getPivot();
    return {pivot.x, pivot.y};
}

float dRenderComponent2DGetPivotX(tCD_Handle renderComponent) {
    return renderComponents[renderComponent]->getPivot().x;
}
float dRenderComponent2DGetPivotY(tCD_Handle renderComponent) {
    return renderComponents[renderComponent]->getPivot().y;
}

void dRenderComponent2DVSetPivot(tCD_Handle renderComponent,
                                 dVector2f newPivot) {
    renderComponents[renderComponent]->setPivot(
        Vector2<tD_pos>((tD_pos)(newPivot.x), (tD_pos)(newPivot.y))
    );
}
void dRenderComponent2DSetPivot(tCD_Handle renderComponent,
                                float newPivotX, float newPivotY) {
    renderComponents[renderComponent]->setPivot(
        Vector2<tD_pos>((tD_pos)newPivotX, (tD_pos)newPivotY)
    );
}

void dRenderComponent2DFlipX(tCD_Handle renderComponent) {
    renderComponents[renderComponent]->flipX();
}
void dRenderComponent2DFlipY(tCD_Handle renderComponent) {
    renderComponents[renderComponent]->flipY();
}

bool dRenderComponent2DIsFlippedX(tCD_Handle renderComponent) {
    return renderComponents[renderComponent]->isFlippedX();
}
bool dRenderComponent2DIsFlippedY(tCD_Handle renderComponent) {
    return renderComponents[renderComponent]->isFlippedY();
}

TextureFactory* dGetTextureFactory() {
    return textureFactory;
}

Renderer2D* dRenderer2DGetRenderer() {
    return renderer;
}
