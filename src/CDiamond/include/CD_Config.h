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

#ifndef D_CD_CONFIG_H
#define D_CD_CONFIG_H

#include "D_ConfigTable.h"
#include "CD_typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Must call this before loading or writing config files
 * (using dConfigLoadConfigTable or dConfigWriteConfig).
 */
void dConfigInitConfigLoader(char* pathRoot);

void dConfigDestroyAll();

tCD_Handle dConfigMakeConfigTable();
tCD_Handle dConfigLoadConfigTable(char* path);
void dConfigDestroyConfigTable(tCD_Handle configtable);

void dConfigWriteConfig(tCD_Handle configtable, char* path);

bool dConfigHasKey(tCD_Handle configtable, char* key);

const char* dConfigGet      (tCD_Handle configtable, char* key);
int         dConfigGetInt   (tCD_Handle configtable, char* key);
float       dConfigGetFloat (tCD_Handle configtable, char* key);
bool        dConfigGetBool  (tCD_Handle configtable, char* key);

void dConfigSet      (tCD_Handle configtable, char* key, char* value);
void dConfigSetInt   (tCD_Handle configtable, char* key, int value);
void dConfigSetFloat (tCD_Handle configtable, char* key, float value);
void dConfigSetBool  (tCD_Handle configtable, char* key, bool value);

#ifdef __cplusplus
}
#endif

Diamond::ConfigTable& dConfigGetConfigTable(tCD_Handle configtable);

#endif // D_CD_CONFIG_H
