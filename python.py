import pyautogui, webbrowser
from time import sleep
from random import choice

webbrowser.open("https://www.instagram.com/direct/t/104079937654191/?hl=es")

sleep (15)

mensaje = open("hello.txt")

for i in range (10):
    pyautogui.typewrite(choice(mensaje))
    pyautogui.press("enter")
    sleep(10)