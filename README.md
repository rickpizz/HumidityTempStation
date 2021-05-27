# Estação de monitoramento ambiental -  Temperatura e Humidade

Em uma Cidade Grande igual São Paulo, ou em cidades de interiores menores, sempre foi muito comum o uso de Termômetros e sensores para medir temperatura e umidade. 
Baseado nisso, o projeto visa exercer o papel de uma estação móvel de controle e medição de temperatura e umidade, porém, conta como vantagens extremamente úteis, como: seu tamanho compacto e sua vasta gama de adaptações. 
Pode ser usado e adaptado para casos específicos, como, medir a temperatura de uma câmara fria por exemplo, mas, a priori, o foco é medir a temperatura e umidade do ar, no ambiente em que está inserido. A estação conta com a Placa Arduino Uno R3 como principal placa eletrônica, a protoboard que irá fornecer maiores possibilidades de conectividade, possui o sensor Dht11, responsável por medir e temperatura e humidade, que comunica esses dados para o seu próprio microcontrolador, e o servo motor, que será responsável pela indicação dessa temperatura visualmente, e através do protocolo MQTT, os dados serão transmitidos para um WebService, que possibilizará a disponibilização destes dados, com pouco segundos de atraso, para o site, fornecendo a visualização dos dados gerados através de qualquer aparelho com internet e um navegador.

![WhatsApp_Image_2021-05-23_at_15 45 24-removebg-preview (1)](https://user-images.githubusercontent.com/48699967/119746232-5eb82480-be66-11eb-8bb8-66bd26bc0271.png)
![principal-removebg-preview](https://user-images.githubusercontent.com/48699967/119746242-61b31500-be66-11eb-85ea-c8f2b093dd3f.png)



## Hardware utilizados no projeto

* **Placa Arduino UNO R3** 

É uma plataforma open source ou hardware para prototipagem eletrônica, projetada com um microcontrolador Atmel AVR com suporte para entrada/saída dados já embutido, com linguagem de programação padrão baseado no em C/C++. Com 14 entradas e saídas digitais, sendo seis delas com Pulse With Modelation, microcontrolador com velocidade de 16MHz, 2Kb de memória de execução, 32Kb de memória de armazenamento, possui operação da placa em 5V, podendo ser alimentada por fontes de 7V a 12V.

![image](https://user-images.githubusercontent.com/48699967/119746316-9a52ee80-be66-11eb-9d33-0a13154fb88f.png)


* **Protoboard**

Permitirá uma maior área de trabalho, organização, e possibilitará a gamificação e inserção de diversos sensores e conexões no projeto.

![image](https://user-images.githubusercontent.com/48699967/119746323-a0e16600-be66-11eb-8ba0-b01b6dbcded1.png)


* **Sensor de Temperatura e Humidade DHT11**

O sensor será responsável por medir a temperatura e Humidade do ambiente em que está inserido, e comunicará estes dados para o seu microcontrolador.

![image](https://user-images.githubusercontent.com/48699967/119746337-a9d23780-be66-11eb-8308-3de225f12d6d.png)


* **Jumpers**

Conjunto de fios condutores utilizados para conectar extremidades distintas do circuito do projeto.

![image](https://user-images.githubusercontent.com/48699967/119746350-b5bdf980-be66-11eb-9404-6ebe9ba522a7.png)


* **Micro Servo SG90**

Utilizado no projeto para demonstrar um termômetro visual na ProtoBoard, que com seu braço mecânico irá movimentar conforme a medição da temperatura indicada, apontando em a temperatura em um desenho feito com a escala de temperatura em Celsius, podendo ser alternada para humidade. Funcionalidade semelhante ao apontador de um velocímetro.

![image](https://user-images.githubusercontent.com/48699967/119746375-bfdff800-be66-11eb-89ca-4a7de8e15b03.png)


## Softwares utilizados no projeto

* **Broker [Mosquitto](https://mosquitto.org/download/) - Protocolo MQTT**

É um protocolo de troca de mensagens, sendo via terminal ou dashboard, utilizado em pequenos dispositivos de Internet das Coisas e otimizado para redes TCP/IP. O broker adotado no projeto foi o Mosquitto, que realiza a implementação do protocolo.

**[Instalação no Windows](https://mosquitto.org/download/)**

**Instalação Mac**

```bash
brew install mosquitto
```

**Instalação Linux**

[Debian](https://mosquitto.org/2013/01/mosquitto-debian-repository)

Suporte a snap

```bash
snap install mosquitto
```

Ubuntu

```bash
sudo apt-add-repository ppa:mosquitto-dev/mosquitto-ppa
sudo apt-get update
```

* **[Arduino IDE](https://www.arduino.cc/en/software)**

Utilizado no projeto como ferramenta-base para programação de todos os sensores, atuadores e placas inseridos no contexto de desenvolvimento do projeto.

![image](https://user-images.githubusercontent.com/48699967/119746526-0b92a180-be67-11eb-9c71-b580d62d41c4.png)



* **[HiveMQ CLoud](https://www.hivemq.com/mqtt-cloud-broker/)**

Para utilização de um servidor que suportasse as mensagens PUB/SUB do broker MQTT, utilizamos o Hive MQ Cloud, um serviço web que permite utilizar de deus dados nos atributos do broker e plataforma de visualização de dados. Sua vantagem é o fato de suportar toda a especificação do protocolo MQTT, sendo também escalável.

![image](https://user-images.githubusercontent.com/48699967/119746468-ef8f0000-be66-11eb-96f3-ceb7565dd9c4.png)



* **[Node-RED](https://nodered.org/)**

Feito pela IBM e demonstrado em aula, é uma plataforma desenvolvida para interação de diversos hardwares. Foi utilizado para visualização gráfica dos dados, a partir de um char semelhante a um velocímetro de um carro, possuindo versatilidade quanto à origem do dado representado na tela, podendo ser temperatura ou humidade, baseado nas informações enviadas pelo Mosquitto. É uma ferramenta bastante intuitiva para o desenvolvimento necessário no projeto. 

![image](https://user-images.githubusercontent.com/48699967/119746436-e0a84d80-be66-11eb-8850-8e26f7b0d7fa.png)


* **[Fritzing](https://fritzing.org/)**

Para efeitos de diagramação, representação digital e testes de hardware, foi utilizado o Fritzing, plataforma open source com objetivos e aplicabilidade que se encaixam no contexto do projeto. Os diagramas estão nos arquivos do repositório.

![DIAGRAMAScircuitoEELETRO_Esquemático](https://user-images.githubusercontent.com/48699967/119746268-72638b00-be66-11eb-83a9-34591408aefa.png)
![DIAGRAMAScircuitoEELETRO_bb](https://user-images.githubusercontent.com/48699967/119746269-7394b800-be66-11eb-8a7c-3e59dc0640ac.png)




## Contribuição
As pull requests são bem-vindas. Para grandes mudanças, por favor, abra um assunto primeiro para discutir o que você gostaria de mudar.

Por favor, certifique-se de atualizar os testes conforme apropriado.
