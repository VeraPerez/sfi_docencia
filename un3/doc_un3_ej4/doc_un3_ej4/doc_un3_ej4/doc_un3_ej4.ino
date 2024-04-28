/*// Método 1 para transmitir un número en punto flotante en little endian

void setup() {
    Serial.begin(115200);
}

void loop() {
    // 45 60 55 d5 (ASCII en hexa)= E ` U ! (ASCII en símbolo)
    // https://www.h-schmidt.net/FloatConverter/IEEE754.html
    static float num = 3589.3645;

    if(Serial.available()){
        if(Serial.read() == 's'){
            Serial.write ( (uint8_t *) &num,4);
        }
    }
}
*/



/*// Método 2 para transmitir un número en punto flotante en little endian
void setup() {
    Serial.begin(115200);
}

void loop() {
// 45 60 55 d5// https://www.h-schmidt.net/FloatConverter/IEEE754.htmlstatic
float num = 3589.3645;
static uint8_t arr[4] = {0};

if(Serial.available()){
if(Serial.read() == 's'){
            memcpy(arr,(uint8_t *)&num,4);
            Serial.write(arr,4);
        }
    }
}
*/



// Envío en big endian

void setup() {
    Serial.begin(115200);
}

void loop() 
{
// 45 60 55 d5// https://www.h-schmidt.net/FloatConverter/IEEE754.htmlstatic 
float num = 3589.3645;
static uint8_t arr[4] = {0};

if(Serial.available())
  {
    if(Serial.read() == 's')
      {
       memcpy(arr,(uint8_t *)&num,4);
        for(int8_t i = 4; i >= 0; i--)
          {
          Serial.write(arr[i]);
          }
       }
  }
}
