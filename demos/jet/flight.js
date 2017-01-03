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
config.windowTitle = "Best game";
config.windowWidth = 1920;
config.windowHeight = 1080;
config.vsync = true;

if (Diamond.init(config)) {
    // laser ship
    const pos = Diamond.Vector2.scalarVec(
        Diamond.renderer.resolution, {x: 0.5, y: 0.25}
    );

    const shipSprite = Diamond.renderer.loadTexture("assets/laserShip.png");

    var movespeed = 1;
    var turnspeed = 0.2;

    const laserShip = new function() {
        this.transform = new Diamond.Transform2(pos);
        this.renderer = new Diamond.RenderComponent2D(this.transform, shipSprite, 1);
    };
    laserShip.renderer.pivot = {x: 40, y: 95};

    // particle system
    const particleConfig = JSON.parse(fs.readFileSync("jet/jetstreamparticles.json"));

    const particles = new Diamond.ParticleEmitter2D(
        particleConfig, laserShip.transform
    );

    // game update
    const update = function(delta) {
        laserShip.transform.position.add(
            Diamond.Vector2.rotateVector(
                {x: delta * movespeed, y: 0},
                laserShip.transform.rotation * Diamond.Math.DEG2RAD
            )
        );
        laserShip.transform.rotation += delta * turnspeed;
    }

    Diamond.launch(update);
    Diamond.cleanUp();
}
