# Tarefa-1---Aula-Sincrona-27-01
# Unidade 4 - Capítulo 4: Interrupções

---

## Enunciado
Este projeto tem como objetivo consolidar a compreensão sobre interrupções no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento **BitDogLab**.

---

## Objetivos
- Compreender o funcionamento e a aplicação de interrupções em microcontroladores.
- Identificar e corrigir o fenômeno do **bouncing** em botões por meio de **debouncing** via software.
- Manipular e controlar LEDs comuns e LEDs endereçáveis **WS2812**.
- Fixar o estudo do uso de **resistores de pull-up internos** em botões de acionamento.
- Desenvolver um projeto funcional que combine hardware e software.

---

## Descrição do Projeto
O projeto envolve a utilização dos seguintes componentes conectados à placa **BitDogLab**:

- **Matriz 5x5 de LEDs WS2812**, conectada à **GPIO 7**.
- **LED vermelho**, conectado à **GPIO 13**.
- **Botão A**, conectado à **GPIO 5**.
- **Botão B**, conectado à **GPIO 6**.

---

## Funcionalidades do Projeto
1. O **LED vermelho** deve piscar continuamente 5 vezes por segundo.
2. O **Botão A** deve incrementar o número exibido na matriz de LEDs a cada pressão.
3. O **Botão B** deve decrementar o número exibido na matriz de LEDs a cada pressão.
4. A matriz de LEDs **WS2812** deve exibir números de **1 a 9** de forma visualmente clara.
    - Formatação fixa: Cada número deve ser exibido em estilo digital (como segmentos iluminados formando os dígitos).
    - Alternativamente, é permitido um estilo criativo, desde que o número seja identificável.
5. O display inicia ligado no numero 1.
6. Ao atingir o número **9**, pressionar o **Botão A** não terá efeito.
7. O **Botão B** só funcionará para decrementar os números de **9 a 1**.

---

## Requisitos do Projeto
- **Uso de Interrupções (IRQ):** Todas as funcionalidades dos botões devem ser implementadas utilizando interrupções.
- **Debouncing:** O tratamento de bouncing nos botões deve ser realizado via software.
- **Controle de LEDs:** O projeto deve demonstrar o controle de LEDs comuns e endereçáveis WS2812.
- **Organização do Código:** O código deve estar bem estruturado e comentado para facilitar o entendimento.

---

## Entrega
### 1. Código-Fonte
- O projeto deve ser entregue em um arquivo ou repositório contendo todos os arquivos necessários para execução.
- Caso o código não seja compilável ou não execute corretamente, a nota atribuída poderá ser nula.

### 2. Vídeo de Demonstração
- O vídeo deve ter no **máximo 2 minutos** e incluir:
  - **Demonstração do funcionamento do projeto**.
  - **Explicação breve das funcionalidades implementadas**.
  - **Execução do projeto na placa BitDogLab** com os botões e LEDs funcionando.

---

## Link do Wokwi e Foto do Projeto

https://wokwi.com/projects/421716575566939137

![image](https://github.com/user-attachments/assets/ea8df980-eec8-4bd1-9a41-ba1cafd1f699)

---

## Link do Vídeo de Demonstração
https://youtu.be/nT7Pjon8egk

---
