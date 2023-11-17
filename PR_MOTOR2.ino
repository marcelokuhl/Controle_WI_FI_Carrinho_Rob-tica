/* 
Robot 
tractor 
*/
// Marcelo Guilherme Kühl
// Colégio Estadual de Pato Branco
// NRE: Pato Branco
// Pato Branco - PR - Brasil
//            2023

/************************* Biblioteca ****************************/
#include <AFMotor.h>
/*****************************************************************/

/********************** Definies e variveis *******************/
AF_DCMotor Motor_Esquerda(2);
AF_DCMotor Motor_Direita(3);

int potencia = 255; // 0 a 255
int duracao_mov_pulsado = 255; // Tempo em milisegundos
int duracao_manobra = 255;     // Tempo em milisegundos
int pino_ESP = 10;

unsigned long Tempo_Pulso = 30;
unsigned long Tempo_Inicial_Pulso;
unsigned long Tempo_Final_Pulso;
/*****************************************************************/


/*************************** SETUP *******************************/
void setup(){
  pinMode(pino_ESP, INPUT);
  Motor_Esquerda.setSpeed(potencia);
  Motor_Direita.setSpeed(potencia);
  pare();
  delay(2000);
}
/*****************************************************************/


/************************* LOOP **********************************/
void loop()
{
  checa_pulso();

  if (Tempo_Pulso >= 5 && Tempo_Pulso <= 14) {
    frente();
    delay(duracao_mov_pulsado);
    pare();
  }

  if (Tempo_Pulso >= 15 && Tempo_Pulso <= 24) {
    esquerda();
    delay(duracao_manobra);
    pare();
  }

  if (Tempo_Pulso >= 25 && Tempo_Pulso <= 34) {
    pare();
  }

  if (Tempo_Pulso >= 35 && Tempo_Pulso <= 44) {
    direita();
    delay(duracao_manobra);
    pare();
  }

  if (Tempo_Pulso >= 45 && Tempo_Pulso <= 54) {
    re();
    delay(duracao_mov_pulsado);
    pare();
  }

  while (Tempo_Pulso >= 55 && Tempo_Pulso <= 62) {
    frente();
    checa_pulso();
  }

  while (Tempo_Pulso >= 65 && Tempo_Pulso <= 72) {
    re();
    checa_pulso();
  }

}// Fim do loop
/*****************************************************************/



/*********************** Fun��es Criadas *************************/

void pare()
{
  Tempo_Pulso = 30;
  Motor_Esquerda.run(RELEASE);
  Motor_Direita.run(RELEASE);
}

void frente()
{
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(FORWARD);
}

void re()
{
  Motor_Esquerda.run(BACKWARD);
  Motor_Direita.run(BACKWARD);
}

void esquerda()
{
  Motor_Esquerda.run(BACKWARD);
  Motor_Direita.run(FORWARD);
}

void direita()
{
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(BACKWARD);
}

void checa_pulso() { 
  /* Se receber o pulso.                                         */
  if (digitalRead(pino_ESP) == HIGH) {
    /* Marca o tempo do in�cio do pulso.                         */
    Tempo_Inicial_Pulso = millis();
    /* Aguarda enquanto o pulso estiver sendo enviado.           */
    while (digitalRead(pino_ESP) == HIGH) {}
    /* Marca o tempo que o pulso terminou.                       */
    Tempo_Final_Pulso = millis();
    /* Calcula a dura��o do pulso (T_final - T_inicial).         */
    Tempo_Pulso = Tempo_Final_Pulso - Tempo_Inicial_Pulso;
  }
  delay(1);
}
/*****************************************************************/