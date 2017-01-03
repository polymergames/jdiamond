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

const Diamond = require('../../jdiamond');
const fs = require('fs');

const config = new Diamond.Config();
config.windowTitle = "Fancy Partikle Effex";
config.windowWidth = 1920;
config.windowHeight = 1080;
config.vsync = true;
config.benchmark = true;

if (Diamond.init(config)) {
    const particleConfig = JSON.parse(fs.readFileSync("particles/particleseverywhere.json"));

    const particles = new Diamond.ParticleEmitter2D(
        particleConfig, new Diamond.Transform2({x: 960, y: 540})
    );

    Diamond.launch();
    Diamond.cleanUp();
}
