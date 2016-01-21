# Floating-Point
Project files for the Floating Point public installation.

You can find more info about this project in my website: http://esrs.co/
Make sure to watch the project in action here: https://youtu.be/SHnhzbCWRn8

The software that controls the mirrors is divided into a Grasshopper called "Floating_Point_OS.gh" and an Arduino file called "Serial_CSV_to_Stepper.ino.ino"

The Grasshopper simulation is where all the geometry and raytracing takes place. You will need two plugins to properly run the model. One called Heliotrope(Avaliable here for free: http://www.food4rhino.com/project/heliotropegh?ufh) used for sun vector calculation.
The other plugin is called Firefly(Available here for free: http://www.fireflyexperiments.com/) used here for sending serial data from GH to Arduino.

The Arduino file makes use of the AccelStepper library(http://www.airspayce.com/mikem/arduino/AccelStepper/) and it basically takes the serial string from the GH definition and turns it into instructions for the stepper motors.

You will also find a pdf file with schematics of the installation and details about the machines. The machines themselves where designed and built by me with help from Javier Toro (http://toroblum.com/)

Disclaimer:
There is probably a much efficient and easier way to build this system, including the software, electronics, mechanics involved. But at the end of the day everything worked the way it was supposed to be and all was successful. If you have any questions/comments you can contact me at: esteban@esrs.co
