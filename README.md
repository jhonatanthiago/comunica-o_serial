### **Resumo do Projeto**

O projeto implementa uma comunicação entre dois Arduinos (Mestre e Escravo) utilizando a biblioteca `SoftwareSerial` para troca de dados via pinos digitais. Ele controla o estado de um LED no Arduino Escravo com base no estado de um botão e nos valores de um sensor de luminosidade lidos pelo Arduino Mestre.

---

### **Descrição do Funcionamento**

1. **Arduino Mestre**:
   - Lê os valores de um sensor de luminosidade conectado ao pino analógico **A0**.
   - Detecta o estado de um botão conectado ao pino digital **8**.
   - Envia via Serial uma string no formato:  
     ```
     "<valor_do_sensor> <estado_do_botao>"
     ```  
     - **`valor_do_sensor`**: Intensidade de luz lida pelo sensor (0 a 1023).  
     - **`estado_do_botao`**: 1 (pressionado) ou 0 (não pressionado).

2. **Arduino Escravo**:
   - Recebe os dados enviados pelo Mestre.
   - Quando o botão está pressionado (**1**):
     - O LED conectado ao pino **12** acende na máxima intensidade.
   - Quando o botão não está pressionado (**0**):
     - O LED ajusta sua intensidade proporcional ao valor lido pelo sensor.
     - Se o valor da luminosidade for menor que **20**, o Escravo exibe no monitor serial a mensagem:
       ```
       "Baixa luminosidade!"
       ```
   - Exibe no monitor serial o valor PWM aplicado ao LED.

---

### **Aplicações**
Este projeto pode ser usado como base para:
- Sistemas de controle remoto entre dois Arduinos.
- Ajuste automático de dispositivos baseados em sensores e interruptores.
- Ensino de conceitos básicos de comunicação serial e controle PWM em projetos embarcados.
