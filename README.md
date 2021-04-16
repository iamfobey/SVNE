# SVNE - Simple Visual Novel Engine written in C++

# Getting Started
Before installing the project, you must have  installed Visual Studio 17/19 with C ++ support.
#### Install
Start by cloning the repository with ```git clone https://github.com/DezlowNG/SVNE```
After cloning the repository, run the project and build it.
In the ```bin/(platform)```, create a new ```game``` folder (your source code will be there). 
Next, you need to create two files (in the previously created folder): ```settings.svne``` - your game settings and a ```script.svne``` - game script.
#### Create a new character and make him talk!
Before creating a character, you need to download the Impact font from the Internet (the file itself must be called Impact.ttf).
Have you downloaded it? Then create a new ```assets``` folder in the ```bin/(platform)/game``` (you will load your backgrounds, sprites and backgrounds) and in it create another ```fonts``` folder and copy the early font you downloaded there (as a reminder, it should be called Impact.ttf). You should get: bin/(platform)/game/assets/fonts/Impact.ttf
Now let's start creating a character!
To create a character, you need to write ```character me = Dezlow``` in the ```script.svne file```
After creating the character, make the transition to a new line and write ```me Hello World```
Now run ```SVNE.exe``` from ```bin/(platform)```
If everything started without problems and the text was displayed, then congratulations you created a character and made him speak!
