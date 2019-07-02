import RPi.GPIO as GPIO
import time
import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
        print("Connected With Result Code " (rc))

if __name__ == "__main__":
# MQTT
        host = "MTL-700-NOA55.MTL1.CO.TH"
        port = 1883
        client = mqtt.Client("OPTO")
        client.connect(host, port)
# GPIO
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(5, GPIO.IN)
        GPIO.setup(6, GPIO.IN)
        GPIO.setup(13, GPIO.IN)
        GPIO.setup(19, GPIO.IN)
        GPIO.setup(26, GPIO.IN)
        GPIO.setup(16, GPIO.IN)
        GPIO.setup(20, GPIO.IN)
        GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_UP)

        try:
                while True:
                        client.loop_start()
                        if GPIO.input(5)==False:
                                print("Opto CH.1 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(6)==False:
                                print("Opto CH.2 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(13)==False:
                                print("Opto CH.3 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(19)==False:
                                print("Opto CH.4 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(26)==False:
                                print("Opto CH.5 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(16)==False:
                                print("Opto CH.6 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(20)==False:
                                print("Opto CH.7 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        if GPIO.input(21)==False:
                                print("Opto CH.8 ON")
                                #client.publish('Facility/Andon1',json_string)
                                time.sleep(4)
                        time.sleep(1)
        finally:
                GPIO.cleanup()
                client.loop_stop()
