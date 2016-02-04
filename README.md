# Floating-Point
I have uploaded all source files here in case someone is interested in the technical back-end of the project.
And also because I like to keep at least some level of project documentation.

The installation consists of three computer-controlled circular mirrors placed on a rooftop in the center of Santiago(Chile). They reflect sunlight onto a large nearby facade drawing an elliptical pattern throughout the day, until the sun goes out. The software that controlls the mirrors was developed using Grasshopper.

You can find more info about this project in my website: http://esrs.co/

Make sure to watch the project in action here: https://youtu.be/SHnhzbCWRn8

More photos of the installation here: https://www.flickr.com/photos/139682630@N04/albums/72157661634951554

The software is divided into a Rhino file called "Location.3dm"(in mm), a Grasshopper file called "Floating_Point_OS.gh" and an Arduino file called "Serial_CSV_to_Stepper.ino"

The Rhino file contains all the relevant geometry of the location and it basically helps you make sense of the GH simulation.

The Grasshopper simulation is where all the geometry and raytracing takes place. It allows precise controll and calibration of the mirrors. It takes cartesian coordinates, from the positions of the light dots on facade, and polar coordinates,from the position of the sun in space, and outputs a serial string with proper motor coordinate.s You will need two plugins to properly run the model. One called Heliotrope(Avaliable here for free: http://www.food4rhino.com/project/heliotropegh?ufh) used for sun vector calculation.
The other plugin is called Firefly(Available here for free: http://www.fireflyexperiments.com/) used here for sending serial data from GH to Arduino.

The Arduino file makes use of the AccelStepper library(http://www.airspayce.com/mikem/arduino/AccelStepper/) and it basically takes the serial string from the GH definition and turns it into instructions for the stepper motors.

You will also find a pdf file with schematics of the installation and details about the machines. The machines themselves where designed and built by me with help from Javier Toro (http://toroblum.com/)

Disclaimer:
There is probably a much efficient and easier way to build this system, including the software, electronics, mechanics involved. But at the end of the day everything worked the way it was supposed to be and all was successful. If you have any questions/comments you can contact me at: esteban@esrs.co
