// Cofre 0: 9600 8N1>   <9600 8N1
// Cofre 1: 9600 8N1>   <19200 8N1
# define COFRE0



#define LED 13

#ifdef COFRE0
char msg[] = "RPI8N1"; // Cofre 0: 9600 8N1
#endif
#ifdef COFRE1
char msg[] = "uC 19200 8O1"; // Cofre 1: 19200 8N1
#endif
#ifdef COFRE2
char msg[] = "cP 115200 8E2"; // Cofre 1: 19200 8N1
#endif
char msgSize;
char i = 0;
char c = 0;
char erros = 0;
void setup() 
{
  pinMode(LED, OUTPUT);
#ifdef COFRE0
  Serial.begin(9600,SERIAL_8N1);
#endif 
#ifdef COFRE1
  Serial.begin(9600,SERIAL_8O1);
#endif
#ifdef COFRE2
  Serial.begin(38400,SERIAL_8E2);
#endif
  msgSize = sizeof(msg)-1;

  for( i=0; i<msgSize; i++ )
  {
    delay(500);
    Serial.write(msg[i]);
    delay(500);
  }

  i = 0;
  c = 0;
  erros = 0;
#ifdef COFRE0
  Serial.begin(9600,SERIAL_8N1);
#endif
#ifdef COFRE1
  Serial.begin(19200,SERIAL_8O1);
#endif
#ifdef COFRE2
  Serial.begin(115200,SERIAL_8E2);
#endif
}

void loop() 
{
  if(Serial.available() > 0 )
  {
    c = Serial.read();
    erros += (c != msg[i]) ? 1:0;
    ++i;
  }

  if( i >= msgSize )
  {
    if( erros )
      Serial.print("Erro: Nao entre em panico!");
    else
      Serial.print("Obrigado pelos peixes!");
    while( 1 )
    {
      if( erros )
      {
        digitalWrite(LED, 1);
        delay(100);
        digitalWrite(LED, 0);
        delay(100);
      }
      else
        digitalWrite(LED, 1);
    }
  }

  for( char j=0; j<i; j++ )
  {
    digitalWrite(LED, 1);
    delay(200);
    digitalWrite(LED, 0);
    delay(100);
  }
  delay(500);
}
