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

const ffi = require('ffi');
const ref = require('ref');

// Define types for Diamond lib interface
const intPtr = ref.refType('int');

// Determine the path to the Diamond lib
const platformdir = process.platform;
var libpath = __dirname + '/src/CDiamond/lib/' + platformdir;
if (platformdir == 'win32') {
  if (process.arch == 'ia32')
      libpath += '/x86';
  else
      libpath += '/x64';
  libpath += '/CDiamond';
}
else {
  libpath += '/libCDiamond';
}

// This is the bridge to native Diamond functions
const Diamond = ffi.Library(libpath, {
  // Engine2D
  'dEngine2DConfigureGraphics': ['void', ['string', 'int', 'int', 'bool', 'bool']],
  'dEngine2DConfigureAudio': ['void', ['int', 'int', 'int']],
  'dEngine2DInit': ['bool', []],
  'dEngine2DDestroy': ['void', []],
  'dEngine2DLaunchGame': ['void', []],
  'dEngine2DQuitGame': ['void', []],
  // Game2D
  'dGame2DBenchmark': ['void', ['string']],
  'dGame2DInit': ['bool', ['pointer', 'pointer', 'pointer', 'pointer']],
  'dGame2DDestroy': ['void', []],
  // Transform2
  'dTransform2Init': ['bool', []],
  'dTransform2Destroy': ['void', []],
  'dTransform2MakeTransform': ['int', ['float', 'float', 'float', 'float', 'float']],
  'dTransform2DestroyTransform': ['void', ['int']],
  'dTransform2SetTransform': ['void', ['int', 'float', 'float', 'float', 'float', 'float']],
  'dTransform2SetPosition': ['void', ['int', 'float', 'float']],
  'dTransform2GetPositionX': ['float', ['int']],
  'dTransform2GetPositionY': ['float', ['int']],
  'dTransform2AddPosition': ['void', ['int', 'float', 'float']],
  'dTransform2AddPositionX': ['void', ['int', 'float']],
  'dTransform2AddPositionY': ['void', ['int', 'float']],
  'dTransform2GetRotation': ['float', ['int']],
  'dTransform2SetRotation': ['void', ['int', 'float']],
  'dTransform2AddRotation': ['void', ['int', 'float']],
  'dTransform2SetScale': ['void', ['int', 'float', 'float']],
  'dTransform2GetScaleX': ['float', ['int']],
  'dTransform2GetScaleY': ['float', ['int']],
  // Renderer2D
  'dRenderer2DInit': ['bool', []],
  'dRenderer2DDestroy': ['void', []],
  'dRenderer2DGetResolution': ['void', [intPtr, intPtr]],
  'dRenderer2DGetScreenResolution': ['void', [intPtr, intPtr]],
  'dRenderer2DLoadTexture': ['int', ['string']],
  'dRenderer2DDestroyTexture': ['void', ['int']],
  'dRenderer2DMakeRenderComponent': ['int', ['int', 'int', 'int']],
  'dRenderer2DDestroyRenderComponent': ['void', ['int']],
  'dRenderComponent2DSetSprite': ['void', ['int', 'int']],
  'dRenderComponent2DGetLayer': ['int', ['int']],
  'dRenderComponent2DSetLayer': ['void', ['int', 'int']],
  'dRenderComponent2DGetPivotX': ['float', ['int']],
  'dRenderComponent2DGetPivotY': ['float', ['int']],
  'dRenderComponent2DSetPivot': ['void', ['int', 'float', 'float']],
  'dRenderComponent2DFlipX': ['void', ['int']],
  'dRenderComponent2DFlipY': ['void', ['int']],
  'dRenderComponent2DIsFlippedX': ['bool', ['int']],
  'dRenderComponent2DIsFlippedY': ['bool', ['int']],
  // ParticleSystem2D
  'dParticleSystem2DInit': ['bool', ['int']],
  'dParticleSystem2DDestroy': ['void', []],
  'dParticleSystem2DMakeEmitter': ['int', ['int', 'int']],
  'dParticleSystem2DSetEmitterConfig': ['void', ['int', 'int']],
  'dParticleSystem2DDestroyEmitter': ['void', ['int']],
  'dParticleSystem2DUpdate': ['void', ['int']],
  // Config
  'dConfigInitConfigLoader': ['void', ['string']],
  'dConfigDestroyAll': ['void', []],
  'dConfigMakeConfigTable': ['int', []],
  'dConfigLoadConfigTable': ['int', ['string']],
  'dConfigDestroyConfigTable': ['void', ['int']],
  'dConfigWriteConfig': ['void', ['int', 'string']],
  'dConfigHasKey': ['bool', ['int', 'string']],
  'dConfigGet': ['string', ['int', 'string']],
  'dConfigGetInt': ['int', ['int', 'string']],
  'dConfigGetFloat': ['float', ['int', 'string']],
  'dConfigGetBool': ['bool', ['int', 'string']],
  'dConfigSet': ['void', ['int', 'string', 'string']],
  'dConfigSetInt': ['void', ['int', 'string', 'int']],
  'dConfigSetFloat': ['void', ['int', 'string', 'float']],
  'dConfigSetBool': ['void', ['int', 'string', 'bool']]
});

// shallow copies an object
function copyObj(from, to) {
  Object.assign(to, from)
}

// jdiamond API starts here

/**
 * Configuration for Diamond engine with default values.
 */
exports.Config = function() {
  this.windowTitle = "A Game Without a Name";
  this.windowWidth = 1280;
  this.windowHeight = 720;
  this.fullscreen = false;
  this.vsync = false;
  this.numAudioChannels = 2;
  this.audioFrequency = 44100; // hertz
  this.audioSampleSize = 2048; // bytes
  // estimate for the max number of particles
  // that may be present at any time.
  this.particlePoolSize = 100;
  this.benchmark = false;
  this.benchmarkFile = "benchmark.log";
}

/**
 * Initializes Diamond engine and its subsystems.
 */
exports.init = function(config) {
  var success = true;

  if (!config) {
    config = new exports.Config();
  }

  Diamond.dEngine2DConfigureGraphics(
    config.windowTitle,
    config.windowWidth,
    config.windowHeight,
    config.fullscreen,
    config.vsync
  );
  Diamond.dEngine2DConfigureAudio(
    config.numAudioChannels,
    config.audioFrequency,
    config.audioSampleSize
  );

  if (config.benchmark)
    Diamond.dGame2DBenchmark(config.benchmarkFile);

  if (!(Diamond.dEngine2DInit() &&
        Diamond.dTransform2Init() &&
        Diamond.dRenderer2DInit() &&
        Diamond.dParticleSystem2DInit(config.particlePoolSize))) {
    success = false;
  }

  Diamond.dConfigInitConfigLoader("");

  return success;
}

/**
 * Begins the game loop in the Diamond backend.
 */
exports.launch = function(update, postPhysicsUpdate, quit) {
  var postPhysicsUpdateCB = ref.NULL;
  var quitCB = ref.NULL;

  const updateCB = ffi.Callback('void', ['int'], function(delta) {
    if (update) {
      update(delta);
    }

    // update Diamond's non-core systems (ex. particles)
    // that aren't automatically updated within
    // Diamond Engine's game loop.
    Diamond.dParticleSystem2DUpdate(delta);
  });

  if (postPhysicsUpdate) {
    postPhysicsUpdateCB = ffi.Callback('void', ['int'], postPhysicsUpdate);
  }
  if (quit) {
    quitCB = ffi.Callback('void', [], quit);
  }

  Diamond.dGame2DInit(ref.NULL, updateCB, postPhysicsUpdateCB, quitCB);
  Diamond.dEngine2DLaunchGame();
}

/**
 * Ends the game but does not free engine resources.
 */
exports.quit = function() {
  Diamond.dEngine2DQuitGame();
}

/**
 * Frees all game and engine resources.
 */
exports.cleanUp = function() {
  Diamond.dGame2DDestroy();
  Diamond.dConfigDestroyAll();
  Diamond.dParticleSystem2DDestroy();
  Diamond.dRenderer2DDestroy();
  Diamond.dTransform2Destroy();
  Diamond.dEngine2DDestroy();
}

// Objects of the following classes reference their corresponding
// objects in the Diamond backend using a handle.

// obj returns a Javascript object containing properties
// corresponding to the current state of the properties in the jdiamond component.
// while the jdiamond component might rely on getters and setters
// for some fields, the returned object is a serializable snapshot
// containing only value-properties.
// this is a snapshot, and will not maintain any connection to the actual
// jdiamond component.

// set(other) updates a component's properties to those in other.
// other should be an object with the same interface
// for its component properties as the jdiamond component, but does
// not need to contain all component properties- only the properties
// defined in other will be updated in component this.

// TODO: test performance change from caching some values
// (ex. position data in transform) to return when getting
// and update when setting, in order to avoid making
// a call to the Diamond backend every time a value is read.
// This may not be worth it, because game logic seems to be more
// write-heavy than read-heavy (most of the read-heavy stuff
// probably happens in the physics engine, which is in the
// backend anyways, and in game logic-specific data
// that isn't stored in the Diamond backend).
exports.Transform2 = class Transform2 {
  constructor(position = {x: 0, y: 0},
              rotation = 0,
              scale    = {x: 1, y: 1}) {
    this.handle = Diamond.dTransform2MakeTransform(
      position.x, position.y, rotation, scale.x, scale.y
    );
  }
  destroy() {
    Diamond.dTransform2DestroyTransform(this.handle);
  }

  get obj() {
    let objref = {
      position: this.position,
      rotation: this.rotation,
      scale: this.scale
    }
    let objcopy = {}
    copyObj(objref, objcopy)
    return objcopy;
  }

  set(other) {
    if (other.position)
      this.position = other.position;

    if (other.rotation)
      this.rotation = other.rotation;

    if (other.scale)
      this.scale = other.scale;
  }

  // note: setting position.x or position.y directly
  // will not change the underlying Diamond transform.
  // position can only be changed by setting position
  // to a new {x, y} object, or by using add function.
  get position() {
    return {
      x: Diamond.dTransform2GetPositionX(this.handle),
      y: Diamond.dTransform2GetPositionY(this.handle),
      add: function(dpos) {
        Diamond.dTransform2AddPosition(this.handle, dpos.x, dpos.y);
      },
      addX: function(dx) {
        Diamond.dTransform2AddPositionX(this.handle, dx);
      },
      addY: function(dy) {
        Diamond.dTransform2AddPositionY(this.handle, dy);
      }
    };
  }
  set position(position) {
    Diamond.dTransform2SetPosition(this.handle, position.x, position.y);
  }

  get rotation() {
    return Diamond.dTransform2GetRotation(this.handle);
  }
  set rotation(rotation) {
    Diamond.dTransform2SetRotation(this.handle, rotation);
  }

  // see comment for setting position.x and position.y,
  // applies to scale as well.
  get scale() {
    return {
      x: Diamond.dTransform2GetScaleX(this.handle),
      y: Diamond.dTransform2GetScaleY(this.handle)
    };
  }
  set scale(scale) {
    Diamond.dTransform2SetScale(this.handle, scale.x, scale.y);
  }

  // TODO: this doesn't seem to work
  toString() {
    return "handle: " + this.handle + ", " +
           "position: " + this.position.toString() + ", " +
           "rotation: " + this.rotation.toString() + ", " +
           "scale: " + this.scale.toString();
  }
}

exports.RenderComponent2D = class RenderComponent2D {
  constructor(transform, texture, layer = 0) {
    this.texture = texture;
    this.handle = Diamond.dRenderer2DMakeRenderComponent(
      transform.handle, texture.handle, layer
    );
  }
  destroy() {
    Diamond.dRenderer2DDestroyRenderComponent(this.handle);
  }

  get obj() {
    let objref = {
      sprite: this.sprite,
      layer: this.layer,
      pivot: this.pivot,
      isFlippedX: this.isFlippedX,
      isFlippedY: this.isFlippedY
    }
    let objcopy = {}
    copyObj(objref, objcopy)
    return objcopy
  }

  set(other) {
    if (other.sprite)
      this.sprite = other.sprite;

    if (other.layer)
      this.layer = other.layer;

    if (other.pivot)
      this.pivot = other.pivot;

    if (other.isFlippedX != this.isFlippedX)
      this.flipX();

    if (other.isFlippedY != this.isFlippedY)
      this.flipY();
  }

  get sprite() {
    return this.texture;
  }
  set sprite(texture) {
    this.texture = texture;
    Diamond.dRenderComponent2DSetSprite(this.handle, texture.handle);
  }

  get layer() {
    return Diamond.dRenderComponent2DGetLayer(this.handle);
  }
  set layer(layer) {
    Diamond.dRenderComponent2DSetLayer(this.handle, layer);
  }

  get pivot() {
    return {
      x: Diamond.dRenderComponent2DGetPivotX(this.handle),
      y: Diamond.dRenderComponent2DGetPivotY(this.handle)
    };
  }
  set pivot(pivot) {
    Diamond.dRenderComponent2DSetPivot(this.handle, pivot.x, pivot.y);
  }

  flipX() {
    Diamond.dRenderComponent2DFlipX(this.handle);
  }
  flipY() {
    Diamond.dRenderComponent2DFlipY(this.handle);
  }

  get isFlippedX() {
    return Diamond.dRenderComponent2DIsFlippedX(this.handle);
  }
  get isFlippedY() {
    return Diamond.dRenderComponent2DIsFlippedY(this.handle);
  }
}

exports.renderer = {
  loadTexture: function(path) {
    const handle = Diamond.dRenderer2DLoadTexture(path);
    if (handle < 0)
      return null;
    return {handle: handle}
  },
  destroyTexture: function(texture) {
    Diamond.dRenderer2DDestroyTexture(texture.handle);
  },

  get resolution() {
    var xbuf = ref.alloc('int');
    var ybuf = ref.alloc('int');

    Diamond.dRenderer2DGetResolution(xbuf, ybuf);

    return {
      x: xbuf.deref(),
      y: ybuf.deref()
    };
  },
  get screenResolution() {
    var xbuf = ref.alloc('int');
    var ybuf = ref.alloc('int');

    Diamond.dRenderer2DGetScreenResolution(xbuf, ybuf);

    return {
      x: xbuf.deref(),
      y: ybuf.deref()
    };
  }
}

exports.ParticleEmitter2D = class ParticleEmitter2D {
  constructor(config, transform) {
    this.mConfig = {};
    copyObj(config, this.mConfig)
    this.transform = transform;
    this.configTable = Diamond.dConfigMakeConfigTable();

    // key to success!
    for (var key in config) {
      Diamond.dConfigSet(this.configTable, key, config[key].toString());
    }

    this.handle = Diamond.dParticleSystem2DMakeEmitter(
      this.configTable, transform.handle
    );
  }
  // note: this does not destroy the particle emitter's
  // associated transform!
  destroy() {
    Diamond.dParticleSystem2DDestroyEmitter(this.handle);
    Diamond.dConfigDestroyConfigTable(this.configTable);
  }

  get obj() {
    let objcopy = {}
    copyObj(this.mConfig, objcopy)
    return objcopy
  }

  set(other) {
    if (other.config)
      this.config = other.config;

    // if (other.transform)
    //   this.transform = other.transform;
  }

  // Warning: changing the returned object won't change this component's
  // actual config! Set this component.config to your new config object after making
  // changes in order to update this component.
  get config() {
    return this.mConfig;
  }

  set config(config) {
    copyObj(config, this.mConfig)

    for (let key in config) {
      Diamond.dConfigSet(this.configTable, key, config[key].toString());
    }

    Diamond.dParticleSystem2DSetEmitterConfig(this.handle, this.configTable);
  }
}

exports.Math = {
  RAD2DEG: 180 / Math.PI,
  DEG2RAD: Math.PI / 180
}

exports.Vector2 = {
  scalar: function(vec, scalar) {
    return {
      x: vec.x * scalar,
      y: vec.y * scalar
    };
  },
  scalarVec: function(vec, scalar) {
    return {
      x: vec.x * scalar.x,
      y: vec.y * scalar.y
    }
  },
  rotateVector: function(vec, radians) {
    const sinrad = Math.sin(radians);
    const cosrad = Math.cos(radians);
    return {
      x: vec.x * cosrad - vec.y * sinrad,
      y: vec.x * sinrad + vec.y * cosrad
    };
  }
}

exports.Util = {
  objToKeyvalPairs: function(obj) {
    var str = "";
    for (var prop in obj) {
      str += prop + ": " + obj[prop] + "\n";
    }
    return str;
  }
}
