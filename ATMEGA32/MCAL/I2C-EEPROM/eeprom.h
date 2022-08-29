

#ifndef EEPROM_H_
#define EEPROM_H_


void EEpromInit(void);
void EEpromWriteByte(unsigned short address, unsigned char data);
unsigned char EEpromReadByte(unsigned short address);
 
#endif








