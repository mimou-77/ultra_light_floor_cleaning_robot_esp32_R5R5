
> [!Note] uses esp-idf

# HW : 

## tools : 

- ✅ MCU : esp32c3_devkitM/devkitC

- ✅ ultrasound sensor HC-SR04

- ✅ servo motor SG90

- 2 DC motors + 2 encoders + 1 motor driver
  - ✅ 2 DC motors 
  - ❌ 2 encoders LM393
  https://tuni-smart-innovation.com/products/capteur-de-vitesse-lm393
  - ✅1 motor driver (i will use L298N but it's better to use DRV8833 for less energy consumption and heat diffusion )

- 2x battery 18650 (7.4V = 2x serial 3.7V battery) + 1x Buck converter MP1584EN
  - ❌ battery:
  https://2btrading.tn/batteries-et-chargeurs/10143-batterie-rechargeable-37v-18650-icr-2500mah.html
  - ❌ buck MP1584EN : 7.4V to 5V
    https://souilah-electronique.tn/modules-et-capteurs/747-module-mp1584-mini-alimentation-reglable-step-down-15-26v-3a-dc-dc-.html



## mapping : 

### L298N to esp32c3 : 
- GND --- GND
- remove jumpers on pins ENA && ENB
- ENA --- gpio_10 
- ENB --- gpio_11
- IN1 --- 4
- IN2 --- 5
- IN3 --- 6
- IN4 --- 7
- left motor: IN1, IN2, ENA
  - ENA : speed (this pin recieves a PWM signal (from ledc periph))
  - move in dir_1 (forward) : IN1,IN2=1,0
  - move in dir_2 (backward) : IN1,IN2=0,1
  - stop : IN1,IN2=0,0||1,1
- right motor: IN3, IN4, ENB
  - ENB : speed (this pin recieves a PWM signal (from ledc periph))
  - move in dir_1 : IN3,IN4=1,0
  - move in dir_2 : IN3,IN4=0,1
  - stop : IN3,IN4=0,0||1,1

=> 
- move forward : left motor dir_1 && right_motor dir_1 (IN1,IN2,IN3,IN4=1,0,1,0) ; same speed from ENA && ENB 
- turn left (pivot) : left motor backward (0,1) && right motor forward (1,0) 
- virage : lower speed on ENX for the motor on which dir to turn 

### buck MP1584EN to L298N :
- battery ---> MP1584EN ---> esp32 5V && L298N 5V




# SW : 

## used design patterns : 

- FSM (finite state machine) : xxxxxxxxxx
- observer : 
- command


  
 
  


  