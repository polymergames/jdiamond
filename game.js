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

const Diamond = require('./jdiamond');

const config = new Diamond.Config();
config.windowTitle = "Best game";
config.vsync = true;

var success = false;
Diamond.init(config, res => success = res);

if (success) {
    const shipSprite = Diamond.renderer.loadTexture("laserShip.png");

    const laserShip = new function() {
        this.transform = new Diamond.Transform2({x: 600, y: 100});
        this.renderer = new Diamond.RenderComponent2D(this.transform, shipSprite);
    };
    laserShip.renderer.pivot = {x: 75, y: 105};

    var movespeed = 0.01;
    var turnspeed = 0.2;

    const update = function(delta) {
        // laserShip.renderer.flipX();
        // laserShip.renderer.flipY();
        laserShip.transform.position.add(
            Diamond.Math.rotateVector(
                {x: delta, y: 0},
                laserShip.transform.rotation * Diamond.Math.DEG2RAD
            )
        );
        laserShip.transform.rotation += delta * turnspeed;
    }

    Diamond.launch(update);

    Diamond.cleanUp();
}
