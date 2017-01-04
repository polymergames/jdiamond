# jdiamond
[![Build Status](https://travis-ci.org/polymergames/jdiamond.svg?branch=master)](https://travis-ci.org/polymergames/jdiamond)

`jdiamond` is a JavaScript game engine for desktop games. It is a node.js interface for [Diamond](https://github.com/polymergames/Diamond), a 2D C++ game engine. It allows you to develop high-performance PC games that are rendered on native graphics libraries such as OpenGL. And unlike some desktop game engines that feature "JavaScript" scripting, it runs in a real node.js environment, allowing you to take full advantage of JavaScript features and the massive variety of node.js libraries.

## API

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

## Installation

OSX or Windows is required- we plan on supporting Linux in the future.

If you don't already have node.js, install it from [here](https://nodejs.org/en/).
Then in your project folder, run:

``` bash
$ npm install jdiamond
```

You also need to have SDL2, SDL2 image, and SDL2 mixer installed. If you don't have them already, follow the instructions for your platform:

#### Mac

You can use our install script to automatically download and install the SDL frameworks:

``` bash
$ sudo ./node_modules/jdiamond/install_deps
```

If you can't sudo, you can install SDL to your user directory instead:

```
$ ./node_modules/jdiamond/install_deps ~/Library/Frameworks
```

#### Windows

As far as we know, SDL does not have an executable installer, and we haven't made one yet. This means that, for now, you'll have to manually install all of the DLLs in `jdiamond/src/CDiamond/extern/SDL2/lib/[your architecture]/`. You can copy those DLLs to your node.js directory (ex. `C:\Program Files\nodejs`) and jdiamond should be able to find them. Or, you could install them to `C:\Windows\System32`, but we haven't been able to do this successfully (if you're Windows-savvy, please consider contributing to the project!).

#### Did it work??

After you've installed SDL, you can run the following to make sure jdiamond is working:

```
$ cd node_modules/jdiamond
$ npm test
```

License
-------

jdiamond uses node-ffi to communicate with the C++ Diamond library. See [node-ffi](https://github.com/node-ffi/node-ffi) for license details.

Diamond uses Simple DirectMedia Layer (SDL), which is Copyright (c) 1997-2014 Sam Lantinga <slouken@libsdl.org>.

jdiamond is Copyright 2016 Ahnaf Siddiqui, and is licensed under the Apache License, Version 2.0 (see LICENSE file).
