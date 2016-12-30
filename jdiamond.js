var ffi = require('ffi');
var ref = require('ref');

var Diamond = ffi.Library('CDiamond/build/libCDiamond', {
    // Engine2D
    'dEngine2DConfigureGraphics': ['void', ['string', 'int', 'int', 'bool', 'bool']],
    'dEngine2DConfigureAudio': ['void', ['int', 'int', 'int']],
    'dEngine2DInit': ['bool', []],
    'dEngine2DDestroy': ['void', []],
    'dEngine2DLaunchGame': ['void', []],
    // Game2D
    'dGame2DInit': ['bool', ['pointer', 'pointer', 'pointer', 'pointer']],
    'dGame2DDestroy': ['void', []],
    // Transform
    'dTransform2Init': ['bool', []],
    'dTransform2Destroy': ['void', []],
    'dTransform2MakeTransform': ['int', ['float', 'float', 'float', 'float', 'float']],
    'dTransform2DestroyTransform': ['void', ['int']],
    'dTransform2SetTransform': ['void', ['int', 'float', 'float', 'float', 'float', 'float']],
    'dTransform2SetPosition': ['void', ['int', 'float', 'float']],
    'dTransform2GetPositionX': ['float', ['int']],
    'dTransform2SetPositionX': ['void', ['int', 'float']],
    'dTransform2GetPositionY': ['float', ['int']],
    'dTransform2SetPositionY': ['void', ['int', 'float']],
    'dTransform2GetRotation': ['float', ['int']],
    'dTransform2SetRotation': ['void', ['int', 'float']],
    'dTransform2SetScale': ['void', ['int', 'float', 'float']],
    'dTransform2GetScaleX': ['float', ['int']],
    'dTransform2SetScaleX': ['void', ['int', 'float']],
    'dTransform2GetScaleY': ['float', ['int']],
    'dTransform2SetScaleY': ['void', ['int', 'float']],
});

Diamond.dEngine2DConfigureGraphics("Best Game",
                                   1280, 720, // window resolution
                                   false, // fullscreen
                                   false); // vsync

if (Diamond.dEngine2DInit()) {
    var gameInit = ffi.Callback('void', [], function() {
        console.log("Game initializing!");
    });
    var gameUpdate = ffi.Callback('void', ['int'], function(delta) {
        console.log("Update: ", delta);
    });

    Diamond.dGame2DInit(gameInit, gameUpdate, ref.NULL, ref.NULL);
    Diamond.dEngine2DLaunchGame();

    Diamond.dGame2DDestroy();
    Diamond.dEngine2DDestroy();
};
