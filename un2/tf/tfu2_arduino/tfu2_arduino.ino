/*
CÓDIGO UNO

Descripción:
* Define una función llamada 'contador' que toma tres parámetros: valorInicial, rapidezConteo, y factorUD.
* La función ejecuta un contador ascendente o descendente según el valor de 'factorUD' y devuelve una cadena que muestra el progreso del contador en la consola.
* En setup(), se inicializa la comunicación serial a una velocidad de 9600 baudios.
* En el loop(), el programa solicita al usuario ingresar tres valores: valorInicial, rapidezConteo, y factorUD a través de la consola serial. Y se llama a la función contador con los valores ingresados y muestra el resultado en la consola serial.

En resumen, este código permite al usuario configurar y ejecutar un contador ascendente o descendente en función de los valores ingresados a través de la comunicación serial y muestra el progreso del contador en la consola serial. Además, verifica que los valores ingresados sean válidos (positivos) antes de ejecutar el contador.
*/

String contador(int valorInicial, int rapidezConteo, double factorUD)
{
  if (valorInicial < 0 || rapidezReduccion <= 0)
  {
    return "Los parámetros deben ser valores positivos.";
  }

  String resultado = "Contador ";

  if (factorUD < 0)
  {
    resultado += "descendente ";
  }
  else
  {
    resultado += "ascendente ";
  }
  resultado += "Contador desde " + String(valorInicial) + " a una rapidez de " + String(rapidezConteo) + " por segundo\n";

  while (valorInicial >= 0)
  {
    resultado += String(valorInicial) + "\n";
    valorInicial += rapidezConteo * factorUD;
    delay(1000);      //Se agrega un retraso de 1 segundo
  }

  return resultado;
}


void setup()
{
  Serial.begin(9600);     //Se inicializa la comunicación serial
}


void loop()
{
  int valorInicial, rapidezConteo;
  double factorUD;

  Serial.print("Ingrese el valor inicial del contador: ");
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  valorInicial = Serial.parseInt(); //Lee el valor ingresado
  
  Serial.print("Ingrese la rapidez de reducción del contador: ");
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  rapidezConteo = Serial.parseInt();  //Lee la rapidez ingresada

  Serial.print("Ingrese el factor: '-1' para descendente y '1' para ascendente): ");
  while (!Serial.available()) {}    //Espera hasta que se ingrese un valor
  factorUD = Serial.parseFloat();   //Lee el factor ingresado

  String resultado = contador(valorInicial, rapidezConteo, factorUD);
  Serial.println(resultado);
}
