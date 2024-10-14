import random
import mouse
from time import sleep

adivina = random.randint(0, 100);
if(adivina <= 50):
    sleep(3)
    mouse.click('left')
    print(adivina)
