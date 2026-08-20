
> [!Note] uses esp-idf

# HW : 

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


# SW : 

## used design patterns : 

- FSM (finite state machine) : xxxxxxxxxx
- observer : 
- command


  
 
  


  