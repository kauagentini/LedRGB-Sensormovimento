// C++ code

#define VERMELHO 6
#define AZUL 	 5
#define VERDE 	 3

void setup()
{
  pinMode(VERMELHO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode (FOTO, INPUT);
}

void loop()
{
  //acenderCor(Vermelha, Azul, Verde, tempo)
  acenderCor(255,0,0,5000); // vermelho forte
  acenderCor(150,0,0,1500); // vermelho médio
  acenderCor(70,0,0,1500);  // vermelho fraco

  //
  acenderCor(0,255,0,5000); // azul forte
  acenderCor(0,150,0,1500); // azul médio
  acenderCor(0,70,0,1500);  // azul fraco

  //
  acenderCor(0,0,255,5000); // verde forte
  acenderCor(0,0,150,1500); // verde médio
  acenderCor(0,0,70,1500);  // verde fraco

  //
  acenderCor(255,0,255,1500); // amarelo
  acenderCor(255,255,255,1500); // branco
  acenderCor(0,0,0,1500); // preto
  acenderCor(255,0,100,1500); // laranja
  acenderCor(255,150,50,1500); // rosa
}

//procedimento - sub-programa
void acenderCor(int intensidadeVermelha, int intensidadeAzul,
                int intensidadeVerde, int tempo) {
  analogWrite(VERMELHO, intensidadeVermelha);
  analogWrite(AZUL, intensidadeAzul);
  analogWrite(VERDE, intensidadeVerde);
  delay(tempo);
}