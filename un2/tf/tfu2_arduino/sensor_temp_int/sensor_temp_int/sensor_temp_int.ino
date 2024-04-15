#include <pico/stdlib.h>
#include <hardware/adc.h>

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  
  // Initialize ADC
  adc_init();
  
  // Enable temperature sensor
  adc_set_temp_sensor_enabled(true);
}

void loop() {
  // Select ADC input 4 (temperature sensor)
  adc_select_input(4);

  // Perform an ADC conversion
  uint16_t result = adc_read();
  
  // Calculate voltage from ADC result
  float voltage = result * (3.3f / (1 << 12));

  // Calculate temperature using the formula for RP2040
  float temperature = 27 - (voltage - 0.706) / 0.001721;

  // Print the temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Delay for 2 seconds before the next reading
  delay(2000);
}
