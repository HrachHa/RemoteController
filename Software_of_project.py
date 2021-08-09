import serial #Serial imported for Serial communication
from serial import Serial

import time #Required to use delay functions
import pyautogui


ArduinoSerial = serial.Serial('com6',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while 1:
    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)
    if 'CloseTab' in incoming:
        pyautogui.hotkey('ctrl', 'f4')  
    if 'Rewind' in incoming:
        pyautogui.press('left')  
    if 'Forward' in incoming:
        pyautogui.press('right') 
    if 'VoiceUp' in incoming:
        pyautogui.press('up')
    if 'VoiceDown' in incoming:
        pyautogui.press('down')



  