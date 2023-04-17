#Pseudo 3D Objects

The idea consists in rendering 3D objects BEFORE running the game, to generate images that can be drawn witheout the extensive calculations required.

Step 1 (Get an Object):<br>
<Image><br>

Step 2 (Rotate 45° in YZ Axis):<br>
<Image><br>

Step 3 (Rotate 45° in XZ Axis):<br>
<Image><br>

The result should be an topdown view of the object, so it would be advisable to use an isometric projection.<br>

For a object that changes looks based on position, the rendering must repeat the 3º step a few times, for each possible face.<br>

Since the result must have transparency, it is necessary to use a very dynamic bitmap logic.<br>
By doing so, there will be an extra feature of changing colors based on pallete.<br>

