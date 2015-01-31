# spark_iot_printer
CSN-A2 Micro panel Thermal printer connected to Spark Core.
Doc here: http://elecfreaks.com/store/download/datasheet/Componnet/Printer/A2-user%20manual.pdf

Printer here: https://learn.adafruit.com/mini-thermal-receipt-printer

=== WARNING
The printer labels TX and RX are WRONG. You must exchange positions.

Spark Core   RX     -->    TX CSN-A2
Spark Core   TX     -->    RX CSN-A2
Spark Core   VIN    -->    DCIN | VH
Spark Core   GND    -->    DCIN | GND

Compile from level below:

park compile spark_iot_printer

Flash it to your core:

spark flash [your core name] spark_iot_printer

Warning: core hangs after 2-3 requests
