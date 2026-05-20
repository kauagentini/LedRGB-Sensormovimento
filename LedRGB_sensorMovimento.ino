// C++ code
//

#define VERMELHO 6
#define AZUL     5
#define VERDE    3

//fotoresistor
#define FOTO A0

//sensor de distância
#define DISTANCIA 8

void setup()
{
    pinMode(VERMELHO, OUTPUT);
    pinMode(AZUL, OUTPUT);
    pinMode(VERDE, OUTPUT);
    pinMode(FOTO, INPUT);

    Serial.begin(9600);

    //distância será definida na função pois pode ser
    //entrada OU saída
}

void loop()
{
    //leitura da porta A0 - intensidade da luz - 0 a 1023
    int lerFoto = analogRead(FOTO);

    // Ajusta o máximo para 1023
    lerFoto = map(lerFoto, 54, 974, 0, 1023);

    Serial.print("Luminosidade: ");
    Serial.println(lerFoto);

    // Variável que armazenará a distância calculada
    float distancia = medirDistancia();

    // Exibe a distância no monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    if((lerFoto <= 300) || (distancia < 50)) // pouca luz
    {
        Serial.println("pouca luz ou perto");

        acenderCor(255,0,0,1500); // vermelho forte
        acenderCor(0,255,0,1500); // azul forte
        acenderCor(0,0,255,1500); // verde forte
    }
    else
    {
        // luz média ou distância entre 50 e 100 cm
        if((lerFoto > 300 && lerFoto < 800) ||
           (distancia >= 50 && distancia < 100))
        {
            Serial.println("luz media");

            acenderCor(120,0,0,1500);
            acenderCor(0,120,0,1500);
            acenderCor(0,0,120,1500);
        }
        else
        {
            Serial.println("muita luz ou longe");

            acenderCor(0,0,0,1500);
        }
    }
}

// Função responsável por medir a distância
// função retorna algo - distância em metros - float - real
float medirDistancia()
{
    // Variável que armazenará o tempo de ida e volta do sinal
    long duracao;

    // ====================================
    // ETAPA 1: ENVIAR O PULSO
    // ====================================

    // Configura o pino como saída (vamos enviar sinal)
    pinMode(DISTANCIA, OUTPUT);

    // Garante que o pino começa desligado (reset do sensor)
    digitalWrite(DISTANCIA, LOW);
    delayMicroseconds(2);

    // Envia pulso HIGH por 5 microssegundos
    // Isso inicia a medição no sensor
    digitalWrite(DISTANCIA, HIGH);
    delayMicroseconds(5);

    // Desliga o pulso
    digitalWrite(DISTANCIA, LOW);

    // ====================================
    // ETAPA 2: RECEBER O RETORNO
    // ====================================

    // Agora o pino vira entrada (vamos escutar o sensor)
    pinMode(DISTANCIA, INPUT);

    // Mede o tempo que o sinal ficou HIGH
    // Esse tempo representa o percurso do som (ida e volta)
    duracao = pulseIn(DISTANCIA, HIGH);

    // Converte o tempo em distância
    // velocidade do som = 340 m/s
    float distancia = duracao / 58.0;

    return distancia;
}

// Função para acender LED RGB
void acenderCor(int vermelho, int azul, int verde, int tempo)
{
    analogWrite(VERMELHO, vermelho);
    analogWrite(AZUL, azul);
    analogWrite(VERDE, verde);

    delay(tempo);
}