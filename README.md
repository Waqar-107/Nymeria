# Nymeria
<h3>An accelerometer based hand gesture controlled robot.</h3>

<h3>Description:</h3> The project intends to make a car that can be controlled using hand gestures. This can be applied to wheel-chairs in real life to help the handicapped.</br>
In this case, hand gestures mean tilt of hand in different direction. To detect different hand gestures, we will use the accelerometer ADXL345. The sensor will be attached with a breadboard and it shall detect movements and transfer the signals to the microcontroller. Once the direction is known the DC motors will work accordingly. There will be a chassis where the motors will be placed.</br>
The control hand gestures for the car are forward tilt, backward tilt, left tilt, right tilt and no tilt to drive in forward, backward, left, right direction and to stop it respectively.

<h3>Sensors Used:</h3>
<ul>
  <li>Accelerometer-ADXL345</li>
  <li>RF Transmitter Receiver Pair 433 MHz - RXB6</li>
  <li>HT12D</li>
  <li>HT12E</li>
</ul>

<h3>Actuator Used:</h3>
<ul>
  <li>4-Wheel Drive Chassis (comes with 4 DC motor on 4 wheels, each 12volts)</li>  
  <li>Motor-Driver-L298</li>  
</ul>

<h3>Others</h3>
<ul>
  <li>ATMega-32</li>
  <li>Breadboard</li>
  <li>Jumper-wires</li>
</ul>

<h3>Circuit Diagram:</h3>
<h5>Transmitter:</h5>
<img src="https://github.com/Waqar-107/Nymeria/blob/master/circuit-designs/nymeria_transmitter.png" height="350px" width="600px">

<h5>Receiver:</h5>
<img src="https://github.com/Waqar-107/Nymeria/blob/master/circuit-designs/nymeria_receiver.png" height="350px" width="600px">

<h3>Working Principles:</h3>
<h4>RF-module:</h4> <pre>The rf module can be used with a HT12E and HT12D ICs, the connections should be according 
to the circuits given above, <h3>the resistors used in OSC1 and OSC2 of the ICs are very important, using</br>different resistors caused problems and data were not passing</br>
We found two combinations in the net,</br></pre> 
<ul>
<li>1M in transmitter and 51k in receiver.</li></br>
<li>750k in transmitter and 33k in receiver.</li></br>
</ul><pre>
We used 1M in the transmitter and 33k in the receiver.
</h3></pre>

<h4>ADXL345:</h4><pre>ADXL345 uses I2C connection. The headers in codes section are used to work with it.</br>
<ul>
  <li>GND</li>
  <li>VCC</li>
  <li>CS - feed 5v</li>
  <li>SDA - with atmega32's SDA(PC1)</li>
  <li>SCL - with atmega32's SCL(PC0)</li>
</ul></pre>

When the accelerometer senses tilt in any direction, it gives different 
values, e.g when in positive x-axis, it gives a value between 0 to 9.8, when in
negative x-axis, it gives a value betwen 0 to -9.8.

From the values read from accelerometer, we can easily identify in which side to go. So we send signals through the transmitter. A encoder is used here and we can send 4-bits

The receiver receives and sends the data to decoder, it then is sent to another atmega32 and in1,in2,in3 and in4 are controlled to move the motors. 

Here motors of each sides are sorted so that both the wheels of a side moves in the same direction.

Forward - both side moves forward.
backward - both side moves backward.
right - left side moves forward, motors of right side are kept off.
left - right side moves forward, motors of left side are kept off.


<h3>**antenna is not reuired for short range, but we used jumper wires (https://www.techshopbd.com/product-categories/cable/1677/jumper-wire-set-techshop-bangladesh)</h3>

