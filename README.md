jdiamond
========
[![Build Status](https://travis-ci.org/polymergames/jdiamond.svg?branch=master)](https://travis-ci.org/polymergames/jdiamond)

`jdiamond` is a JavaScript game engine for desktop games. It is a node.js interface for [Diamond Engine](https://github.com/polymergames/Diamond), a 2D C++ game engine. It allows you to develop high-performance PC games that are rendered on native graphics libraries such as OpenGL. And unlike some desktop game engines that feature "JavaScript" scripting, it runs in a real node.js environment, allowing you to take full advantage of JavaScript features and the massive variety of node.js libraries.

API
---

To make a game, just require `jdiamond`, initialize the engine, and construct your gameobjects. Create an `update` callback to handle game logic, and then launch your game.

``` js
const Diamond = require('jdiamond');

if (Diamond.init()) {
    const shipSprite = Diamond.renderer.loadTexture("laserShip.png");

    // use a JavaScript object to easily build an entity-component model.
    // this entity has the components transform and renderer.
    const laserShip = new function() {
        this.transform = new Diamond.Transform2({x: 600, y: 100});
        this.renderer = new Diamond.RenderComponent2D(this.transform, shipSprite);
    };

    // this function will be called every frame.
    // here, we are making our ship fly around in a circle.
    const update = function(delta) {
        laserShip.transform.position.add(
            Diamond.Vector2.rotateVector(
                {x: delta, y: 0},
                laserShip.transform.rotation * Diamond.Math.DEG2RAD
            )
        );
        laserShip.transform.rotation += delta;
    }

    Diamond.launch(update);
    Diamond.cleanUp();
}
// game over!
```

Installation
------------

Coming soon! Once we have everything ready, you can expect installation to be a simple `npm install jdiamond`.

License
-------

jdiamond is Copyright 2016 Ahnaf Siddiqui, and is licensed under the Apache License, Version 2.0 (see LICENSE file).
