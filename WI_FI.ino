/************************** Bibliotecas ***************************/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/******************************************************************/

/********************* Definições de variáveis ********************/
const char *nome_da_rede = "Rust_eze";
const char *senha = "12345678";
int pino_Pulsos = 2;
String pagina = "<html>\n"
                "\n"
                "<style>\n"
                "body {\n"
                /* Código html para a cor de fundo da página.     */
                "background: #009541; \n"
                "}\n"
                /* Código html para configuração dos botões.      */
                ".button {\n"
                "background-color: #312682;\n"
                "border: none;\n"
                "color: white;\n"
                "padding: 15px 32px;\n"
                "text-align: center;\n"
                "display: inline-block;\n"
                "font-size: 64px;\n"
                "margin: 4px 2px;\n"
                "cursor: pointer;\n"
                "border-radius: 100%;\n"
                "width: 150px;\n"
                "height: 150px;\n"
                "}\n"
                "</style>\n"
                "<section><center>\n"
                "<br><br>\n"
                /* Código html para os títulos da página.         */
                "<font size=\"6\"> \n"
                "<h1>&#129302; "
                "ROB&Oacute;TICA PARAN&Aacute; "
                "&#129302; </h1>\n"
                "<h1>&#x1F3AE; "
                "Aula 39 - Rob&ocirc; Wireless "
                "&#128246;</h1>\n"
                /* Código html para o botão Frente.               */
                "<h1>Movimento Pulsado</h1>"
                "<p><a href=\"/frente_p\">"
                "<button class=\"button button\">"
                "&#x2B06;</button></a>\n"
                /* Código html para o botão Esquerda.            */
                "<p><a href=\"/esquerda_p\">"
                "<button class=\"button button\">"
                "&#11013;</button></a>\n"
                /* Código html para o botão Pare.                */
                "<a href=\"/pare\">"
                "<button class=\"button button\">"
                "&#x1F6D1;</button></a>\n"
                /* Código html para o botão Direita.             */
                "<a href=\"/direita_p\">"
                "<button class=\"button button\">"
                "&#10145;</button></a>\n"
                /* Código html para o botão Ré.                  */
                "<p><a href=\"/re_p\">"
                "<button class=\"button button\">"
                "&#11015;</button></a>\n"
                "<BR>"
                "<BR>"
                "<h1>Movimento Cont&iacute;nuo</h1>"
                "</font>\n"
                "<p><a href=\"/frente_c\">"
                "<button class=\"button button\">"
                "&#x2B06;</button></a>\n"
                /* Código html para o botão Pare.                */
                "<p><a href=\"/pare\">"
                "<button class=\"button button\">"
                "&#x1F6D1;</button></a>\n"
                /* Código html para o botão Ré.                  */
                "<p><a href=\"/re_c\">"
                "<button class=\"button button\">"
                "&#11015;</button></a>\n";
/* Fim dos códigos da página HTML.                               */
/*****************************************************************/

/***************** Criação do objeto servidor ********************/
ESP8266WebServer servidor(80);
/*****************************************************************/


/*************************** SETUP *******************************/
void setup(){

  pinMode(pino_Pulsos, OUTPUT);
  digitalWrite(pino_Pulsos, LOW);
  WiFi.softAP(nome_da_rede, senha);

  servidor.on("/", []() {
    servidor.send(200, "text/html", pagina);
  });


  servidor.on("/frente_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(10);
  });


  servidor.on("/esquerda_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(20);
  });


  servidor.on("/pare", []() {
    servidor.send(200, "text/html", pagina);
    pulso(30);
  });


  servidor.on("/direita_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(40);
  });


  servidor.on("/re_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(50);
  });


  servidor.on("/frente_c", []() {
    servidor.send(200, "text/html", pagina);
    pulso(60);
  });


  servidor.on("/re_c", []() {
    servidor.send(200, "text/html", pagina);
    pulso(70);
  });


  servidor.begin();
} // Fim do Setup
/*****************************************************************/


/**************************** LOOP *******************************/
void loop(){
  servidor.handleClient();
}
/*****************************************************************/


/********************** Função Envio de Pulso ********************/
/* Função responsável por enviar o pulso ao Arduino com a duração*/
/* informada de acordo com a requisição:                         */
/* Seguir em frente -> Pulso de 10 milissegundos.                */
/* Girar à esquerda -> Pulso de 20 milissegundos.                */
/* Parar -> Pulso de 30 milissegundos.                           */
/* Girar à direita -> Pulso de 40 milissegundos.                 */
/* Ré -> Pulso de 50 milissegundos.                              */
/* Frente contínuo -> Pulso de 60 milissegundos.                 */
/* Ré contínuo      -> Pulso de 70 milissegundos.                */

void pulso(int tempo) {
  /* Ativa o pino do pulso.                                      */
  digitalWrite(pino_Pulsos, HIGH);
  /* Aguarda a duração do pulso.                                 */
  delay(tempo);
  /* Desativa o pino do pulso.                                   */
  digitalWrite(pino_Pulsos, LOW);
}
/*****************************************************************/
