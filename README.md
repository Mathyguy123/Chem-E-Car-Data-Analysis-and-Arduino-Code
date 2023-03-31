# ElectriCar-Code

Author: Abrar Sheikh

This folder includes all Arduino and Python analysis code used in developing the Chem-E-Car as of March 29th, 2023. Some changes were made by Maria Beebe and Calista Krass on March 30th in a separate directory, based on recommendations by Abrar. 

"Motor controller" code is responsible for telling the rover when to stop based on the iodine-clock stopping mechanism. Physically, a photosensor is placed on the reaction vessel opposite an LED- when the reaction begins, it detects light. As endpoint is reached, it no longer detects light, telling the Arduino to cut power. 

Battery discharge curve producer allows a constant current to be taken from the battery while monitoring voltage vs. time. The voltage vs time graph can be obtained using "Analysis of Analog Pin Data Arduino.ipynb".

The iodine-clock team required calibration curves to ensure reliability of the stopping mechanism. To do this, they used the photosensor/LED circuit and "Motor controller" code (with all lines regarding powering the motors commented out) and "Analysis of Analog Pin Data Arduino.ipynb" to determine at what time reaction endpoint occurred.

For more information, please refer to the manuals "Guide to Using Arduino for Battery Discharge Curve" and "Guide to Using Arduino to Measure Voltage" (used for iodine clock team).