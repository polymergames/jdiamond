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

if (Diamond.init()) {
  const pos = Diamond.Vector2.scalarVec(
    Diamond.renderer.resolution, {x: 0.5, y: 0.25}
  );

  const animation = {
    spritesheet: Diamond.renderer.loadTexture('assets/turretSheet.png'),
    frameLength: 20,
    numFrames:   4,
    numRows:     1,
    numColumns:  4
  };

  const turret = new function() {
    this.transform = new Diamond.Transform2(pos);
    this.renderer = new Diamond.RenderComponent2D(this.transform, animation.spritesheet);
    this.animator = new Diamond.AnimatorSheet(animation, this.renderer);
  };

  Diamond.launch();
  Diamond.cleanUp();
}
