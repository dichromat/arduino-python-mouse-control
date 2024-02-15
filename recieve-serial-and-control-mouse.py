#Imports neccesary libraries
import serial
import keyboard
import pyautogui

#Opens the serial port and reads serial input
ser = serial.Serial("COM57",9600)

while True:
    #Grabs the exact input to the Arudino Serial.println function
    bs = ser.readline().decode().strip()

    #safety measure: holding q turns off mouse control
    if not keyboard.is_pressed('q'):
        print(bs)
        #Move the mouse based on the serial data
        match bs:
            case 'UP':
                pyautogui.moveRel(0, -10, 0.0001)

            case 'DOWN':
                pyautogui.moveRel(0, 10, 0.0001)

            case 'LEFT':
                pyautogui.moveRel(-10, 0, 0.0001)

            case 'RIGHT':
                pyautogui.moveRel(10, 0, 0.0001)

            case 'UPLEFT':
                pyautogui.moveRel(-10, -10, 0.0001)

            case 'UPRIGHT':
                pyautogui.moveRel(10, -10, 0.0001)

            case 'DOWNLEFT':
                pyautogui.moveRel(-10, 10, 0.0001)

            case 'DOWNRIGHT':
                pyautogui.moveRel(10, 10, 0.0001)





