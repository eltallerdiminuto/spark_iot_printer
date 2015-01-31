// This #include statement was automatically added by the Spark IDE.
#include "Adafruit_Thermal.h"
#include "HttpClient.h"

Adafruit_Thermal printer;
unsigned int nextTime = 0;    // Next time to contact the server
HttpClient http;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    { "Content-Type", "application/json" },
    { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
  Serial.begin(9600);
  Serial1.begin(19200);
  delay(2000);
  Serial.println("Begin");
  printer.begin(&Serial1);
  // The following function calls are in setup(), but do not need to be.
  // Use them anywhere!  They're just here so they're run only one time
  // and not printed over and over.
  // Some functions will feed a line when called to 'solidify' setting.
  // This is normal.
}

void loop() {
  if (nextTime > millis()) {
    return;
  }

  Serial.println();
  Serial.println("Application>\tStart of Loop.");
  // Request path and body can be set at runtime or at setup.
  request.hostname = "eltallerdiminuto.com";
  request.port = 80;
  request.path = "/spark_iot_printer";

  // The library also supports sending a body with your request:
  //request.body = "{\"key\":\"value\"}";

  // Get request
  http.get(request, response, headers);
  Serial.print("Application>\tResponse status: ");
  Serial.println(response.status);

  Serial.print("Application>\tHTTP Response Body: ");
  Serial.println(response.body);
  if (response.body !=""){
    printer.println(response.body);
    printer.println("= = = = = = = = = = = = = = = =");
    printer.feed(3);
  }
  nextTime = millis() + 10000;
}
