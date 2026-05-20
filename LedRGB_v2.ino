// Pinos do LED RGB
#define VERMELHO 6
#define AZUL     5
#define VERDE    3

// Pino do fotoresistor
#define FOTO A0

void setup()
{
    // LED RGB
    pinMode(VERMELHO, OUTPUT);
    pinMode(AZUL, OUTPUT);
    pinMode(VERDE, OUTPUT);

    // Fotoresistor
    pinMode(FOTO, INPUT);

    // Monitor serial
    Serial.begin(9600);
}

void loop()
{
    // Lê intensidade da luz
    int lerFoto = analogRead(FOTO);

    // Mostra valor no monitor serial
    Serial.println(lerFoto);
  
    // POUCA LUZ

    if (lerFoto <= 300)
    {
        Serial.println("Pouca luz");

        chamarProcedimento(255, 0, 0, 5000); // vermelho
        chamarProcedimento(0, 255, 0, 5000); // azul
        chamarProcedimento(0, 0, 255, 5000); // verde
    }

    // LUZ MÉDIA

    else if (lerFoto > 300 && lerFoto < 800)
    {
        Serial.println("Media luz");

        chamarProcedimento(150, 0, 0, 4000); // vermelho médio
        chamarProcedimento(0, 150, 0, 4000); // azul médio
        chamarProcedimento(0, 0, 150, 4000); // verde médio
    }
  
    // MUITA LUZ

    else if (lerFoto >= 800 && lerFoto < 900)
    {
        Serial.println("Muita luz");

        chamarProcedimento(70, 0, 0, 3000); // vermelho fraco
    }

    // LUZ TOTAL

    else
    {
        Serial.println("Luz total");

        chamarProcedimento(255, 0, 255, 1500);   // amarelo
        chamarProcedimento(255, 255, 255, 1500); // branco
        chamarProcedimento(0, 0, 0, 1500);       // preto
        chamarProcedimento(255, 100, 0, 1500);   // rosa
        chamarProcedimento(255, 50, 150, 1500);  // laranja
    }
}

// PROCEDIMENTO

void chamarProcedimento(int vermelho, int azul, int verde, int tempo)
{
    analogWrite(VERMELHO, vermelho);
    analogWrite(AZUL, azul);
    analogWrite(VERDE, verde);

    delay(tempo);
}