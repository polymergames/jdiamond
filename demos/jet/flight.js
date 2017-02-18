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

  // using a function because in a regular object,
  // this.* members are usable during initialization
  const laserShip = new function() {
    this.transform = new Diamond.Transform2(pos);
    this.renderer = new Diamond.RenderComponent2D(this.transform, shipSprite, 1);
    this.rigidbody = new Diamond.Rigidbody2D(this.transform);
    this.collider = new Diamond.CircleCollider(this.rigidbody, {
      center: {x: 0, y: 0}, radius: 100
    });
    // this.destroy = function() {
    //   this.renderer.destroy();
    //   this.transform.destroy();
    // }
  };
  laserShip.renderer.pivot = {x: 40, y: 95};

  // particle system
  const particleConfig = JSON.parse(fs.readFileSync("jet/jetstreamparticles.json"));

  const particles = new Diamond.ParticleEmitter2D(
    particleConfig, laserShip.transform
  );

  // the poly thing
  const polypoints = [
    {x: 0, y: 50},
    {x: 100, y: 0},
    {x: 200, y: 50},
    {x: 150, y: 100},
    {x: 50, y: 100}
  ];

  const thing = new function() {
    this.transform = new Diamond.Transform2({x: 300, y: 300});
    this.rigidbody = new Diamond.Rigidbody2D(this.transform);
    this.collider = new Diamond.PolygonCollider(this.rigidbody, polypoints);

    // this.destroy = function() {
    //   this.collider.destroy();
    //   this.rigidbody.destroy();
    //   this.transform.destroy();
    // }
  };

  // for debug drawing
  const debugcolor = {r: 255, g: 0, b: 0, a: 100};

  // game update
  const update = function(delta) {
    laserShip.transform.position.add(
      Diamond.Vector2.rotateVector(
        {x: delta * movespeed, y: 0},
        laserShip.transform.rotation * Diamond.Math.DEG2RAD
      )
    );
    laserShip.transform.rotation += delta * turnspeed;
    thing.transform.rotation += delta * turnspeed;

    // test debug drawing
    Diamond.Debug.drawCircleCollider(laserShip.collider, debugcolor);
    Diamond.Debug.drawPolyCollider(thing.collider, debugcolor);
  }

  Diamond.launch({update: update});
  Diamond.cleanUp();
}
