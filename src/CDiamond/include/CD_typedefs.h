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

#ifndef D_CD_TYPEDEFS_H
#define D_CD_TYPEDEFS_H

#include "D_typedefs.h"

#if defined _WIN32 || defined _WIN64
#define CDEXPORT __declspec(dllexport)
#endif

typedef int tCD_Handle;
#define CD_INVALID_HANDLE -1;

typedef struct {
    float x;
    float y;
} dVector2f;

typedef struct {
    dVector2f position;
    float rotation;
    dVector2f scale;
} dTransform2f;

#endif // D_CD_TYPEDEFS_H
