# Nymeria
<h3>An accelerometer based hand gesture controlled robot.</h3>

<h3>Description:</h3> The project intends to make a car that can be controlled using hand gestures. This can be applied to wheel-chairs in real life to help the handicapped.</br>
In this case, hand gestures mean tilt of hand in different direction. To detect different hand gestures, we will use the accelerometer sensor. The sensor will be attached with hand and it shall detect movements and transfer the signals to the microcontroller. The three output signals of accelerometer sensor are analog in nature and it cannot be processed directly by ATmega32 microcontroller. For this, we shall use the ADC of the microcontroller to convert the analog signals to digital. After converting the analog signals of accelerometer sensor to digital values, the microcontroller will process the digital values to find different gestures of the hand. Once the direction is known the DC motors will work accordingly. There will be a chassis where the motors will be placed.</br>
The control hand gestures for the car are forward tilt, backward tilt, left tilt, right tilt and no tilt to drive in forward, backward, left, right direction and to stop it respectively.

<h3>Sensors Used:</h3>
<ul>
  <li>Accelerometer</li>
  <li>RF Transmitter Receiver Pair 433 MHz - RXB6</li>
  <li>HT12D</li>
  <li>HT12E</li>
</ul>

<h3>Actuator Used:</h3>
<ul>
  <li>4-Wheel Drive Chassis (comes with 4 DC motor on 4 wheels)</li>  
  <li>Motor-Driver</li>  
</ul>

<h3>Others</h3>
<ul>
  <li>ATMega-32</li>
  <li>Breadboard</li>
  <li>Jumper-wires</li>
</ul>

<h3>Circuit Diagram:</h3>
