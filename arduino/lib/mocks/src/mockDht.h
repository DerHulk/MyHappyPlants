#ifdef UNIT_TEST
    #include <stdint.h>
#else
    #include <Arduino.h>
#endif

#ifndef dht
#define dht

#define DHT11 11  /**< DHT TYPE 11 */
#define DHT12 12  /**< DHY TYPE 12 */
#define DHT22 22  /**< DHT TYPE 22 */
#define DHT21 21  /**< DHT TYPE 21 */
#define AM2301 21 /**< AM2301 */

class DHT {
public:
  DHT(uint8_t pin, uint8_t type, uint8_t count = 6) {};
  void begin(uint8_t usec = 55);
  float readTemperature(bool S = false, bool force = false);
  float convertCtoF(float);
  float convertFtoC(float);
  float computeHeatIndex(bool isFahrenheit = true);
  float computeHeatIndex(float temperature, float percentHumidity,
                         bool isFahrenheit = true);
  float readHumidity(bool force = false);
  bool read(bool force = false);

  void setTemperature(float value);
  void setHumidity(float value);
  void setHeatIndex(float value);

  private:
    float _Temperature;
    float _Humidity;
    float _HeatIndex;
};

#endif