
var ffi = require('ffi');

var Diamond = ffi.Library('cDiamond/build/libCDiamond', {
    'configureName': ['void', ['string']],
    'configureGraphics': ['void', ['int', 'int', 'bool', 'bool']],
    'configureAudio': ['void', ['int', 'int', 'int']],
    'initEngine': ['bool', []],
    'shutdownEngine': ['void', []]
});

Diamond.configureName("A game without a name");
Diamond.configureGraphics(1280, 720, false, true);

if (Diamond.initEngine()) {
    var running = true;

    while (running) {
        //
    };

    Diamond.shutdownEngine();
};
