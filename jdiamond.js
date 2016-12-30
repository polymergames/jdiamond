const ffi = require('ffi');
const ref = require('ref');

const Diamond = ffi.Library('src/CDiamond/build/libCDiamond', {
    // Engine2D
    'dEngine2DConfigureGraphics': ['void', ['string', 'int', 'int', 'bool', 'bool']],
    'dEngine2DConfigureAudio': ['void', ['int', 'int', 'int']],
    'dEngine2DInit': ['bool', []],
    'dEngine2DDestroy': ['void', []],
    'dEngine2DLaunchGame': ['void', []],
    // Game2D
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
    'dRenderComponent2DIsFlippedY': ['bool', ['int']]
});

Diamond.dEngine2DConfigureGraphics("Best Game",
                                   1280, 720, // window resolution
                                   false, // fullscreen
                                   false); // vsync

if (Diamond.dEngine2DInit() &&
    Diamond.dTransform2Init() &&
    Diamond.dRenderer2DInit()) {

    var transform = -1;
    var renderComp = -1;
    var direction = 1;

    var gameInit = ffi.Callback('void', [], function() {
        console.log("Game initializing!");
        transform = Diamond.dTransform2MakeTransform(600, 350, 0, 1, 1);
        renderComp = Diamond.dRenderer2DMakeRenderComponent(
            transform,
            Diamond.dRenderer2DLoadTexture("laserShip.png"),
            0
        );
    });

    var gameUpdate = ffi.Callback('void', ['int'], function(delta) {
        console.log("Update: ", delta, " ms");
        Diamond.dTransform2AddPositionX(transform, delta * direction);
        Diamond.dTransform2AddPositionY(transform, delta * direction);
        Diamond.dTransform2AddRotation(transform, delta * direction);
        direction *= -1;
    });

    Diamond.dGame2DInit(gameInit, gameUpdate, ref.NULL, ref.NULL);
    Diamond.dEngine2DLaunchGame();

    Diamond.dGame2DDestroy();
    Diamond.dRenderer2DDestroy();
    Diamond.dTransform2Destroy();
    Diamond.dEngine2DDestroy();
};


exports.Engine2D = class Engine2D {
    constructor(callback) {
        if (!(Diamond.dEngine2DInit() &&
              Diamond.dTransform2Init() &&
              Diamond.dRenderer2DInit())) {
            callback(false)
        }
        callback(true)
    }

    get renderer() {
        // return renderer
    }
}
