#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_R = 28;
const int BTN_G = 26;

int main() {
  stdio_init_all();

  //Inicia LED vermelho
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  //Inicia LED verde
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  //Inicia botao vermelho
  gpio_init(BTN_R);
  gpio_set_dir(BTN_R, GPIO_IN);
  gpio_pull_up(BTN_R);
  //Inicia botao verde
  gpio_init(BTN_G);
  gpio_set_dir(BTN_G, GPIO_IN);
  gpio_pull_up(BTN_G);

  while (true) {
    if (!gpio_get(BTN_R)){
      if (gpio_get(LED_PIN_R) == 0) {
        gpio_put(LED_PIN_R, 1);
      } else {
        gpio_put(LED_PIN_R, 0);
      }
      while (!gpio_get(BTN_R)) {
      }
    }
        if (!gpio_get(BTN_G)){
      if (gpio_get(LED_PIN_G) == 0) {
        gpio_put(LED_PIN_G, 1);
      } else {
        gpio_put(LED_PIN_G, 0);
      }
      while (!gpio_get(BTN_G)) {
      }
    }
  }
}
