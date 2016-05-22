import time
import serial
import smtplib

PORT = 'COM 5';
BAUD = 9600;
TO = 'jandropr78@gmail.com'
GMAIL_USER = 'jandropr78@gmail.com'
GMAIL_PASS = ''

SUBJECT = 'alarm!!'
TEXT = 'Your PIR sensor detected abnormality' 
  
# inisialization---------------

ser = serial.Serial(4, 9600)

#----------------------------

def send_print():
    print("alarm")

def send_email():
    print(" Start Sending Email")

    #start stmplib--------
    smtpserver = smtplib.SMTP("smtp.gmail.com",587)
    smtpserver.ehlo()
    smtpserver.starttls()
    print(" Start stmpserver")
    smtpserver.ehlo()
    smtpserver.login(GMAIL_USER, GMAIL_PASS)
    print(" Success login smtpserver")

    msg = SUBJECT + '\n' + TEXT + '\n'+ 'Suhu =' + str(message) + 'celcius'

    smtpserver.sendmail(GMAIL_USER, TO, msg)
    print("email sended !")

    smtpserver.quit()

    print("exiting smtpserver")
    
while True:
    message = float(ser.readline())
    print(str(message)+" celcius")
    if message >= 40 or  message <= 18 :
        send_email()
        print(message)
    
    time.sleep(10.5)
