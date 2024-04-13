/*
CÓDIGO UNO

Descripción:
* Define una función llamada 'contador' que toma tres parámetros: valorInicial, rapidezConteo, y factorUD.
* La función ejecuta un contador ascendente o descendente según el valor de 'factorUD' y devuelve una cadena que muestra el progreso del contador en la consola.
* En setup(), se inicializa la comunicación serial a una velocidad de 9600 baudios.
* En el loop(), el programa solicita al usuario ingresar tres valores: valorInicial, rapidezConteo, y factorUD a través de la consola serial. Y se llama a la función contador con los valores ingresados y muestra el resultado en la consola serial.

En resumen, este código permite al usuario configurar y ejecutar un contador ascendente o descendente en función de los valores ingresados a través de la comunicación serial y muestra el progreso del contador en la consola serial. Además, verifica que los valores ingresados sean válidos (positivos) antes de ejecutar el contador.
*/
// Declaración de función
int contador(int valorInicial, int rapidezConteo, double factorUD)
{
  if (valorInicial < 0 || rapidezConteo <= 0)
  {
    Serial.print("Los parámetros deben ser valores positivos.");
    return 0;
  }
  int resultado = valorInicial;

  while (valorInicial >= 0)
  {
   //resultado = valorInicial;
   resultado = resultado + rapidezConteo * factorUD;;
   delay(1000);      //Se agrega un retraso de 1 segundo
    Serial.print(String(resultado) + "\n");
    //return resultado;
  }
Serial.print(String(resultado) + "\n");  
return resultado;
}


// Programa principal
void setup()
{
  Serial.begin(9600);     //Se inicializa la comunicación serial
  Serial.flush();
}


void loop()
{
  int valorInicial, rapidezConteo;
  double factorUD;

  delay(5000);
  Serial.print("Ingrese el valor inicial del contador: \n" );
  delay(1000);
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  valorInicial = Serial.parseInt(); //Lee el valor ingresado
  Serial.print("El valor inicial del contador es" + String(valorInicial)+ "\n");
  
  Serial.print("Ingrese la rapidez de reducción del contador: \n");
  delay(5000);
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  rapidezConteo = Serial.parseInt();  //Lee la rapidez ingresada
  Serial.print("La rapidez de reducción del contador" + String(rapidezConteo)+ "\n");

  
  Serial.print("Ingrese el factor: '-1' para descendente y '1' para ascendente): \n");
  delay(5000);
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  factorUD = Serial.parseFloat();   //Lee el factor ingresado
  Serial.print("EL factor UD es" + String(factorUD)+ "\n");


  
  int resultado = contador(valorInicial, rapidezConteo, factorUD);
  Serial.println(resultado);
  delay(5000);
}
