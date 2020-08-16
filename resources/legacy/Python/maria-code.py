#This is a test class for MARIA codes.
#Created by: Sampreet Sarkar
##Department of Robotics Engineering,
##The Neotia University
##----------------------------------------------------------------
import os
import time
import RPi.GPIO as GPIO

GPIO.setmode(BCM)       #Identify the pins using the Broadcomm processor pin numbers
GPIO.setWarnings(False) #This is to stop the printing of warning messages on screen

class MARIA:
    pass

    def __init__(self):
        #This is going to be the constructor. This will be used to initialise all
        #the pins, and activate a method call to initialise other sensory modules.
        GPIO.setup(TRIG1, GPIO.OUT)
        GPIO.setup(ECHO1, GPIO.OUT)
        GPIO.setup(TRIG2, GPIO.OUT)
        GPIO.setup(ECHO2, GPIO.OUT)
        GPIO.setup(TRIG3, GPIO.OUT)
        GPIO.setup(ECHO3, GPIO.OUT)

        

