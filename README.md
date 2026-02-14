# Sistema de Monitoramento de Nível de Água com Sensor Ultrassônico

## Descrição do Projeto

Este projeto tem como objetivo monitorar o nível e a quantidade de água acumulada em bueiros e logradouros urbanos, utilizando um sensor ultrassônico. O intuito principal é auxiliar na prevenção de enchentes, alagamentos e inundações em áreas urbanas.

O sistema realiza medições contínuas da distância entre o sensor e a superfície da água, calcula o volume estimado presente no bueiro e exibe essas informações em um display LCD, além de fornecer alertas visuais e sonoros conforme o nível da água se torna crítico.

---

## Objetivo

- Prevenir enchentes e alagamentos urbanos
- Monitorar o acúmulo de água em bueiros e logradouros
- Emitir alertas preventivos em situações de risco
- Servir como base para futuras integrações com sistemas em nuvem (IoT)

---

## Funcionamento do Sistema

1. O sensor ultrassônico mede a distância entre o sensor e o nível da água.
2. A partir dessa distância, o sistema calcula:
   - A altura da lâmina d’água
   - O volume aproximado de água (em litros)
3. As informações são:
   - Exibidas em um display LCD 16x2
   - Indicadas por LEDs de status
   - Sinalizadas por um buzzer em níveis críticos

---
##  Base de Cálculo

- A profundidade máxima considerada para o bueiro é de aproximadamente **3,34 metros**, valor tratado como padrão urbano para fins de monitoramento.
- O cálculo do volume de água é baseado em uma **área transversal padrão de 0,3276 m²**, equivalente a **3.276 cm²**.
- Com essas dimensões, o sistema considera uma **capacidade máxima estimada de cerca de 1.100 litros de água**.
- Os valores apresentados são **estimativas**, adequadas para detecção de níveis críticos, alertas preventivos e apoio à tomada de decisão.

Essa abordagem padronizada permite que o sistema seja replicado em diferentes pontos urbanos **sem a necessidade de recalibração individual**, mantendo consistência nas medições e simplicidade na implantação.


---

## 🚦 Indicadores de Nível

| Nível de Água | Indicação Visual | Indicação Sonora |
|--------------|----------------|-----------------|
| Seguro        | LED Verde       | Nenhuma         |
| Atenção      | LED Amarelo     | Beep curto      |
| Crítico      | LED Vermelho    | Alarme contínuo |

---
## Ilustração feita por IA generativa

  <img width="512" height="938" alt="image" src="https://github.com/user-attachments/assets/54bc2a57-6325-4e52-8190-00421a019488" />


---

## Componentes Utilizados

- Arduino Uno  
- Sensor ultrassônico (HC-SR04 ou equivalente)  
- Display LCD 16x2  
- LEDs (verde, amarelo e vermelho)  
- Buzzer  
- Protoboard e resistores  

---

