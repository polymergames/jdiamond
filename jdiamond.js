
var ffi = require('ffi');

var Diamond = ffi.Library('CDiamond/build/libCDiamond', {
    'dEngine2DConfigureGraphics': ['void', ['string','int', 'int', 'bool', 'bool']],
    'dEngine2DConfigureAudio': ['void', ['int', 'int', 'int']],
    'dEngine2DInit': ['bool', []],
    'dEngine2DDestroy': ['void', []]
});

Diamond.dEngine2DConfigureGraphics("A game without a name", 1280, 720, false, true);

if (Diamond.dEngine2DInit()) {
    var running = true;

    while (running) {
        //
    };

    Diamond.dEngine2DDestroy();
};
