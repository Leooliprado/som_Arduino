// INCLUSÃO DE BIBLIOTECAS

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// DEFINIÇÕES DE PINOS
#define pinRx 10
#define pinTx 11

// DEFINIÇÕES
#define volumeMP3 30

#define DEBUG
// INSTANCIANDO OBJETOS
SoftwareSerial playerMP3Serial(pinRx, pinTx);

DFRobotDFPlayerMini playerMP3;


void setup() {
	Serial.begin(9600);
	playerMP3Serial.begin(9600);

  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));

  if (!playerMP3.begin(playerMP3Serial)) {  // COMUNICAÇÃO REALIZADA VIA SOFTWARE SERIAL
    Serial.println(F("Falha ao iniciar:"));
    Serial.println(F("1.Confira as conexões!"));
    Serial.println(F("2.Confira o cartão SD!"));
    while(true){
      delay(0);
    }
  }

  Serial.println(F("DFPlayer ligado!"));

  playerMP3.volume(volumeMP3);
  
	#ifdef DEBUG
		Serial.println("Iniciado com sucesso!");
	#endif	
  playerMP3.playFolder(1, 1);
  delay(6000);

  playerMP3.playFolder(1, 2);
  delay(11000);

  musica_opicao();
}

void loop() {

   if (Serial.available() > 0) {
    int input = Serial.read() - '0'; // Converte o caractere recebido para um número inteiro

    if (input == 1) {
      Serial.println("Música escolhida: Волны");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 1);
      delay(257000);
      musica_opicao();
    }
    else if (input == 2) {
      Serial.println("Música escolhida: Тоска");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 2);
      delay(189000);
      musica_opicao();
    }
    else if (input == 3) {
      Serial.println("Música escolhida: Судно (Борис Рижий)");
      
      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 3);
      delay(138600);
      musica_opicao();
    }
    else if (input == 4) {
      Serial.println("Música escolhida: Клетка");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 4);
      delay(277000);
      musica_opicao();
    }
    else if (input == 5) {
      Serial.println("Música escolhida: Танцевать");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 5);
      delay(198000);
      musica_opicao();
    }
    else if (input == 6) {
      Serial.println("Música escolhida: Танцевать");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 6);
      delay(279000);
      musica_opicao();
    }
    else if (input == 7) {
      Serial.println("Música escolhida: Танцевать");

      playerMP3.playFolder(1, 4);
      delay(5000);

      playerMP3.playFolder(2, 7);
      delay(259000);
      musica_opicao();
    }
  }  
  delay(1000);
}



void musica_opicao(){
  playerMP3.playFolder(1, 3);
  delay(4000);
  Serial.println("");
  Serial.println("Digite o número da música no campo do terminal acima!");
  Serial.println("");
  Serial.println("Волны -> 1");
  Serial.println("");
  Serial.println("Тоска -> 2");
  Serial.println("");
  Serial.println("Судно (Борис Рижий) -> 3");
  Serial.println("");
  Serial.println("Клетка -> 4");
  Serial.println("");
  Serial.println("Танцевать -> 5");
  Serial.println("");
  Serial.println("________________________________________________________________");
  Serial.println("");
  Serial.println("The Seed -> 6");
  Serial.println("");
  Serial.println("Runaway -> 7");
  Serial.println("");

}

