#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#define LED_R 13
#define BTN_A 5
#define BTN_B 6
#define WS2812_PIN 7
#define MATRIX_SIZE 25  // Matriz 5x5 de LEDs WS2812

// Variável global para armazenar o número atual exibido (0 significa desligado)
volatile int numero_atual = 0;

// Padrões para exibição dos números de 1 a 9 na matriz 5x5
const uint8_t numeros[9][25] = {
    // Número 1
    {0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0,
     0, 0, 1, 0, 0},

    // Número 2
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1},

    // Número 3
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1},

    // Número 4
    {1, 0, 0, 1, 0,
     1, 0, 0, 1, 0,
     1, 1, 1, 1, 1,
     0, 0, 0, 1, 0,
     0, 0, 0, 1, 0},

    // Número 5
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1},

    // Número 6
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 0,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1},

    // Número 7
    {1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     0, 0, 0, 1, 0,
     0, 0, 1, 0, 0,
     0, 1, 0, 0, 0},

    // Número 8
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1},

    // Número 9
    {1, 1, 1, 1, 1,
     1, 0, 0, 0, 1,
     1, 1, 1, 1, 1,
     0, 0, 0, 0, 1,
     1, 1, 1, 1, 1}
};

// Função para exibir o número na matriz de LEDs WS2812
void exibir_numero(int numero) {
    printf("Exibindo número: %d\n", numero);
    // Aqui ficaria o código para acionar os LEDs WS2812 conforme o padrão em numeros[numero-1]
}

// Função chamada quando o botão A é pressionado (incrementa o número)
void incrementar(uint gpio, uint32_t events) {
    if (numero_atual < 9) {
        numero_atual++;
        exibir_numero(numero_atual);
    }
}

// Função chamada quando o botão B é pressionado (decrementa o número)
void decrementar(uint gpio, uint32_t events) {
    if (numero_atual > 1) {
        numero_atual--;
        exibir_numero(numero_atual);
    }
}

int main() {
    stdio_init_all();

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &incrementar);
    
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &decrementar);

    printf("Sistema iniciado. Pressione o botão A para começar.\n");
    
    while (true) {
        sleep_ms(1000);
    }
}
