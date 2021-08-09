# RemoteController
Remote Controller for Arduino
	Remote Controller for Youtube
		Hrachya Harutyunyan 
		     August 1 2021
1.Description
My project is created  especially for youtube and Video based sites. With it you can easily pause close the tab  forward the video , backward the video and with your hand you can control voice. To make this functions working I used python script which is reading Serial output of the Arduino as a input and based on it he is doing functions which I already mentioned.
Features 
1)	When clicking the first button it will make the running video Play or Pause depends on the current state
2)	For the second button you can just close the  video tab which you didn’t want
3)	Third button is responsible for the  backward of the vide it goes back for 5 seconds
4)	Fourth is responsible for forwarding for the five second 
5)	Fifth button is responsible for decreasing and increasing the voice of the video with the ultrasonic sensor. The details how is it working will be explained in the next chapters.

2.Hardware Schema
     Components
         Arduino nano x1                    Resistor  - 1K-OHM x5        Wires
         Push button x5                      Ultrasonic sensor - x1

 

In the schema you can see that every button is connected in the way which enables to change state of digital pin of Arduino from Low to High. When the state of digital pins is high Arduino prints appropriate Message for the function and then it sends to software where python code is handling software part. Ultrasonic sensor is handling volume function . To decide increase volume or not our ultrasonic sensor is  measuring distance two times. If distance2-distance1 is positive it is increasing the volume by 5% , If it is negative it will decrease the volume again by 5%.
 3.Code(Software)
The code with Hardware is written in C++. It is divided parts where I am defining pins . In the setup function I am defining pins as output or input by the pinMode function . In the loop I am checking if the state of  pins which  is used to control the state of the button is high printing the action in the Serial output  and python is doing the next steps. Void sensor function is used to count the distances of two signals and then after checking if it is positive or negative return the next step whether you should decrease or increase the volume. 
The code for the software is written in python. In the script I am using Serial library to connect Arduino board with his specified port and Sensor.begin bandth which is 9600 for us. After successfully establishing connection in the while loop we should check the message which is coming from Arduino to do appropriate action> For it we are using pyautogui module which is handling the pressing the keys for the buttons.

   
