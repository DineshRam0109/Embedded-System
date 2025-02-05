import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
TRIG = 7
ECHO = 11
i=0
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.output(TRIG, False)
Print(“Calibrating.....”)
time.sleep(2)
Print(“Place the object....”)
try:
 while True:
 GPIO.output(TRIG, True)
 time.sleep(0.00001)
 GPIO.output(TRIG, False)
 while GPIO.input(ECHO)==0:
 pulse_start = time.time()
 while GPIO.input(ECHO)==1:
 pulse_end = time.time()

pulse_duration = pulse_end - pulse_start
 distance = pulse_duration * 17150
 distance = round(distance+1.15, 2)
 if distance <=20 and distance >=5:
 print("Distance:",distance,"cm")
 i=1
 if distance>30 and i==1:
 print("Place the object....")
 i=0
 time.sleept(2)
except KeyboardInterrupt:
 GPIO.cleanup()