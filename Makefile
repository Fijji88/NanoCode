PORT=/dev/ttyUSB0
TARGET=DH11TempRead
MCU=atmega328p
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) -Os
LDFLAGS=-Wl,-gc-sections -Wl,-relax
CC=avr-gcc
OBJECT_FILES=$(TARGET).o

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	avrdude -p atmega328p -c avrisp -b 19200 -P /dev/ttyUSB0 -U flash:w:$(TARGET).hex

