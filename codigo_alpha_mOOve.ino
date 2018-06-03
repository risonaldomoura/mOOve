/*
  --------------------------------------------------------------
 |       Project LookEagle 2.0 - placa Digispark                |              
 | Button com motor de vibração  ativado por intervalos de      |
 | pulsos conforme a distância do sensor com o obstáculo        |
  --------------------------------------------------------------
  By: Risonaldo Moura
*/

#define T 0 //T é Trig
#define E 2 //E é Echo
#define M 1 //M é motor

void setup()
{
  pinMode (M, OUTPUT); //pino do motor  
  pinMode(T, OUTPUT); //Pino Trigger como saída
  pinMode(E, INPUT); //Pino Echo como entrada  
}

void loop()
{
  int duracao, cm;//Declaração de variáveis locais

  digitalWrite(M, LOW); //Desliga motor inicialmente
  //pulso Sensor
  digitalWrite(T, LOW);
  delayMicroseconds(2); 
  digitalWrite(T, HIGH);
  delayMicroseconds(10);
  digitalWrite(T, LOW);
  duracao = pulseIn(E, HIGH);
  
  cm = 1+(duracao/58.2);//Equação para distância em centímetros

   if (cm < 100 && cm >0)
   {
    digitalWrite(M, HIGH);//Acionamento do motor
    delay((cm/2)+2);//Tempo que o motor ficará acionado em função da distância
    digitalWrite(M, LOW);//Desligamento do motor
    delay((cm/2)+2);//Tempo para a próxima leitura em função da distância
   }
   else
   {
   digitalWrite(M, LOW); 
   }   
   cm = 0;
   duracao = 0;
}

