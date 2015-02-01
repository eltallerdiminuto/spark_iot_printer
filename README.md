# spark_iot_printer
CSN-A2 Micro panel thermal printer connected to Spark Core.

Printer doc and specs [here](http://elecfreaks.com/store/download/datasheet/Componnet/Printer/A2-user%20manual.pdf).

Buy the printer [here](https://learn.adafruit.com/mini-thermal-receipt-printer).


##Wiring:

The printer labels TX and RX are *WRONG*. You must exchange positions.

    Spark Core   RX     -->    TX            CSN-A2
    Spark Core   TX     -->    RX            CSN-A2
    Spark Core   VIN    -->    DCIN | VH     CSN-A2
    Spark Core   GND    -->    DCIN | GND    CSN-A2


##Compile:
(from dir below)

    spark cloud compile spark_iot_printer

##Flash:

Using cloud:

    spark cloud flash <your-core-id-here> spark_iot_printer

Using USB:

    spark flash <your-core-id-here> spark_iot_printer



Warning: core hangs after 2-3 requests
