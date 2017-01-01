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

#include "CD_ParticleSystem2D.h"

#include "duSwapVector.h"
#include "D_ParticleManager2D.h"
#include "CD_Config.h"
#include "CD_Engine2D.h"
#include "CD_Transform2.h"
#include "CD_Renderer2D.h"
using namespace Diamond;

static Engine2D* engine = nullptr;
static Renderer2D* renderer = nullptr;
static ParticleManager2D* particleManager = nullptr;
static SwapVector<ParticleEmitter2D> particleEmitters;

bool dParticleSystem2DInit(int poolsize) {
    engine = dEngine2DGetEngine();
    if (engine) renderer = engine->getRenderer();
    particleManager = new ParticleManager2D(nullptr, poolsize);
    return engine != nullptr;
}

void dParticleSystem2DDestroy() {
    particleEmitters.clear();
    delete particleManager;
    particleManager = nullptr;
    renderer = nullptr;
    engine = nullptr;
}

tCD_Handle dParticleSystem2DMakeEmitter(tCD_Handle config, tCD_Handle transform) {
    return particleEmitters.insert(particleManager->makeEmitter(
        ParticleSystem2DConfig(dConfigGetConfigTable(config),
                               dGetTextureFactory()),
        dTransform2GetTransformPtr(transform),
        [engine](Particle2D &particle, const ParticleSystem2DConfig &config) {
            particle.transform = engine->makeTransform();
            particle.renderComponent = renderer->makeRenderComponent(
                particle.transform, config.particleTexture, config.layer;
            );
        }
    ));
}

void dParticleSystem2DDestroyEmitter(tCD_Handle emitter) {
    particleEmitters.erase(emitter);
}

void dParticleSystem2DUpdate(tD_delta delta) {
    particleManager->update(delta);
    for (auto emitter : particleEmitters) {
        emitter.update(delta);
    }
}
