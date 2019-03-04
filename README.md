# RT

RT is a 42 project developped by squiquem, sederet, asarasy and qsebasti, which is designed to further student's understanding of the concepts behind ray tracing.
<br/>
___
<br/>
<img align="center" src="https://image.noelshack.com/fichiers/2019/08/2/1550605873-screen-spheres.png" width="100%" alt="Spheres"><br/>
<img align="center" src="https://image.noelshack.com/fichiers/2019/07/1/1549893934-screen-shot-2019-02-11-at-3-04-52-pm.png" width="100%" alt="multiobj"><br/>
<img align="center" src="https://image.noelshack.com/fichiers/2019/08/2/1550605873-screen-allmaterial.png" width="100%" alt="allmaterial">
<br/>
____

## Scene

The scene is defined by light, camera, material and objects (sphere, cone, plane, quadric, box).<br/>
____

## Features

- The scene can be modified in real-time and the program uses multithreading to speed up calculations.<br/>
- Every object can be modified by its type, color or variable as reflection, transparency, coefficient of refraction and more.<br />
- Any object can have a texture (xpm format, perlin sound, checkerboard, etc.).<br/>
- The program supports filters as sepia or black and white and more.<br/>
- Change the reflection max value for all the reflective surfaces.<br/>
- Increase or decrease antialiasing value.<br/>
- Funny (in my opinion) loading screen while waiting for changes to be applied.<br/>
- You can overwrite or export the new scene created by the changes.<br/>
- You can take a screenshot of your beautiful scene.<br/>
____

## Keys

### Camera movements

Step to the left / right :   <td align="right"><kbd>&nbsp;A&nbsp;</kbd>/<kbd>&nbsp;◄&nbsp;</kbd> || <kbd>&nbsp;D&nbsp;</kbd>/<kbd>&nbsp;►&nbsp;</kbd></td><br/>
Step forward / backward :   <td align="right"><kbd>&nbsp;W&nbsp;</kbd>/<kbd>&nbsp;S&nbsp;</kbd></td><br/>
Step up / down :    <kbd>&nbsp;▲&nbsp;</kbd>/<kbd>&nbsp;▼&nbsp;</kbd><br/>
Rotate to the left / right : <kbd>&nbsp;Q&nbsp;</kbd>/<kbd>&nbsp;E&nbsp;</kbd><br/>
Apply changes : <kbd>&nbsp;Return&nbsp;</kbd><br/>
Take a screenshot : <kbd>&nbsp;Backspace&nbsp;</kbd><br/>
____

## How to use it

You can apply any filter at any time with just one click on the filter and/or the cartoon effect and the apply button (on screen or the 'return' key). Also the antialiasing lvl.<br/>
<br/>
For any change on an object, first select an object.<br/>
Then pick up the type of material (uniform color, wood-like pattern, perlin noise, etc).<br/>
Third, choose the color (some material types need 2 selected colors).<br/>
Finally, apply the changes.<br/>
<br/>
On 3rd tabulation you can change the variables for an object.
____

## Installing and launch

    git clone vogsphere@vogsphere.42.fr:intra/2018/activities/rt/squiquem ~/RT
    cd ~/RT && make && ./RT scenes/scene1.xml

Important: you need the libpng library for the screenshot feature. You will also need change the path where you can find that library in the Makefile at `$(INCPNG)` and `$(LIBPNG)`.
____
<br/>
We do not own any right on every used image in the program.