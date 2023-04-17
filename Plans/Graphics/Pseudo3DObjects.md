#Pseudo 3D Objects

The idea consists in rendering 3D objects BEFORE running the game, to generate images that can be drawn witheout the extensive calculations required.

Step 1 (Get an Object):<br>
![image](https://user-images.githubusercontent.com/64809360/232524992-2e5cb46d-0a4d-4494-a91e-a7ab210e1c46.png)<br>

Step 2 (Rotate 45° in YZ Axis):<br>
![image](https://user-images.githubusercontent.com/64809360/232525143-6d8ed0a5-f348-49d2-9356-157197ccd6d0.png)<br>

Step 3 (Rotate 45° in XZ Axis):<br>
![image](https://user-images.githubusercontent.com/64809360/232525406-bce07ec2-6938-41e7-beac-6cd735e5cbf2.png)<br>

The result should be an topdown view of the object, so it would be advisable to use an isometric projection.<br>

For a object that changes looks based on position, the rendering must repeat the 3º step a few times, for each possible face.<br>

Since the result must have transparency, it is necessary to use a very dynamic bitmap logic.<br>
By doing so, there will be an extra feature of changing colors based on pallete.<br>
