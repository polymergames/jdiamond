const assert = require('assert');
const Diamond = require('../jdiamond');

const floatEQ = function(x, y) {
  return Math.abs(x - y) < 0.0001;
}

describe('Diamond', function() {
  before(function() {
    assert.equal(Diamond.init(), true);
  });

  after(function() {
    Diamond.cleanUp();
  });

  describe('Transform2', function() {
    var transform;

    beforeEach(function() {
      transform = new Diamond.Transform2({x: 3, y: 4}, 25, {x: 0.1, y: 0.1});
    });

    afterEach(function() {
      transform.destroy();
    });

    it('constructed transform values should be returned', function() {
      assert(floatEQ(transform.position.x, 3));
      assert(floatEQ(transform.position.y, 4));
      assert(floatEQ(transform.rotation, 25));
      assert(floatEQ(transform.scale.x, 0.1));
      assert(floatEQ(transform.scale.y, 0.1));
    });

    it('set transform values from other transform object', function() {
      transform.set({
        position: {x: -3, y: 15},
        rotation: 4,
        scale: {x: 9, y: 10}
      });

      assert(floatEQ(transform.position.x, -3));
      assert(floatEQ(transform.position.y, 15));
      assert(floatEQ(transform.rotation, 4));
      assert(floatEQ(transform.scale.x, 9));
      assert(floatEQ(transform.scale.y, 10));
    });

    // TODO: more tests!
  });
});
