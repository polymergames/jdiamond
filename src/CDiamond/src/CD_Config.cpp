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

#include "CD_Config.h"

#include "duSparseVector.h"
#include "D_StdConfigLoader.h"
using namespace Diamond;

static ConfigLoader* configLoader = nullptr;
static SparseVector<ConfigTable, tCD_Handle> configTables;

void dConfigInitConfigLoader(char* pathRoot) {
    configLoader = new StdConfigLoader(pathRoot);
}

void dConfigDestroyAll() {
    delete configLoader;
    configLoader = nullptr;
    configTables.clear();
}

tCD_Handle dConfigMakeConfigTable() {
    return configTables.emplace();
}

tCD_Handle dConfigLoadConfigTable(char* path) {
    return configTables.insert(configLoader->load(path));
}

void dConfigDestroyConfigTable(tCD_Handle configtable) {
    configTables.erase(configtable);
}

void dConfigWriteConfig(tCD_Handle configtable, char* path) {
    configLoader->write(configTables[configtable], path);
}

bool dConfigHasKey(tCD_Handle configtable, char* key) {
    return configTables[configtable].hasKey(key);
}

const char* dConfigGet(tCD_Handle configtable, char* key) {
    return configTables[configtable].get(key).c_str();
}
int dConfigGetInt(tCD_Handle configtable, char* key) {
    return configTables[configtable].getInt(key);
}
float dConfigGetFloat(tCD_Handle configtable, char* key) {
    return configTables[configtable].getFloat(key);
}
bool dConfigGetBool(tCD_Handle configtable, char* key) {
    return configTables[configtable].getBool(key);
}

void dConfigSet(tCD_Handle configtable, char* key, char* value) {
    configTables[configtable].set(key, value);
}
void dConfigSetInt(tCD_Handle configtable, char* key, int value) {
    configTables[configtable].set(key, value);
}
void dConfigSetFloat(tCD_Handle configtable, char* key, float value) {
    configTables[configtable].set(key, value);
}
void dConfigSetBool(tCD_Handle configtable, char* key, bool value) {
    configTables[configtable].set(key, value);
}

ConfigTable& dConfigGetConfigTable(tCD_Handle configtable) {
    return configTables[configtable];
}
