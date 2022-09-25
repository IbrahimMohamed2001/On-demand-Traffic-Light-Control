# On-demand-Traffic-Light-Control
A traffic light control system built with AVR ATMEGA32 microcontroller

## The Schematic used

![image](https://user-images.githubusercontent.com/106034477/192156301-2e9b728c-a80b-41a9-9279-790b39f94839.png)

So we have a traffic light with a button 3 LEDs for cars and 3 LEDs for pedestrians, as when the red LED for the cars is on the green one for pedestrians is off and vice versa, when the yellow LED for cars is blinking, the yellow one for pedestrians would blink as well.

## Project In Detail
![925729b1-0b1a-4af7-9d5d-ccbe3c6e0077](https://user-images.githubusercontent.com/106034477/192155936-f06572a6-4dcc-49c1-8b0f-6e6a6de3f23f.jpg)

The main goal here is to perform a simple traffic light control like the state of the LEDs are changing from red to yellow to green, but pedestrians have the high priority in this project so if they pushed the button the controller will check for the traffic light state as if the state was green or (yellow and the next state is green), it will turn off all the LEDs then start blinking both yellow LEDs then turning the red LED for cars and green LED for pedestrians then complete, but if the traffic light state is in red for cars or (yellow and the next state is red), it will ignore this action.




