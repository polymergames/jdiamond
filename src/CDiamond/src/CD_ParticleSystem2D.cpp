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

#include "D_ParticleManager2D.h"
#include "CD_Config.h"
#include "CD_Transform2.h"
#include "CD_Renderer2D.h"
using namespace Diamond;

static ParticleManager2D* particleManager = nullptr;
