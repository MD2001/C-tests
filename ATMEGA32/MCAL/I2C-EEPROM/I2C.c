#include <avr/io.h>

#include "I2C.h"



void i2c_init_master(void)
{
	TWBR = 0x07;              //bit rate = 400.000 kbps, F_CPU = 12M   SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
	TWSR &= ~((1<< TWPS1) | (1<< TWPS0));    //baud rate
	TWCR = (1<< TWEN);                       //enable I2C
	return;
}

void i2c_init_slave(void)
{
	TWAR = (1<< 1);          // my address = 0x01
	TWCR = (1<< TWEN);       //enable I2C
	return;
}


void i2c_start(void)
{
	TWCR = (1<< TWINT) | (1<< TWSTA) | (1<< TWEN);   // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(!(TWCR & (1<<TWINT)));                     // Wait till start condition is transmitted
	while((TWSR & 0xF8) != START_ACK);               // Check for the acknowledgment
	return;
}




void i2c_repeated_start(void)
{
	TWCR = (1<< TWINT) | (1<< TWSTA) | (1<< TWEN);      // Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(!(TWCR & (1<< TWINT)));                       // wait till restart condition is transmitted
	while((TWSR & 0xF8) != REP_START_ACK);              // Check for the acknowledgment
	return;
}




void i2c_send_slave_address_with_write_req(unsigned char slave_address)
{
	TWDR = (slave_address<< 1);                    //Address and write instruction
	TWCR = (1<<TWINT) | (1<<TWEN);                 // Clear TWI interrupt flag, Enable TWI
	while (!(TWCR & (1<<TWINT)));                  // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK);  // Check for the acknowledgment
	return;
}




void i2c_send_slave_address_with_read_req(unsigned char slave_address)
{
	TWDR = (slave_address<< 1);                     // Address
	TWDR |= (1<< 0);                                // read instruction
	TWCR = (1<< TWINT) | (1<< TWEN);                // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<< TWINT)));                  // Wait till complete TWDR byte received
	while((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK);   // Check for the acknowledgment
}





void i2c_write_byte(unsigned char byte)
{
	TWDR = byte;                            // put data in TWDR
	TWCR = (1<< TWINT) | (1<< TWEN);        // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<< TWINT)));          // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != WR_BYTE_ACK);    // Check for the acknowledgment
	return;
}




unsigned char i2c_read_byte(void)
{
	TWCR = (1<< TWINT) | (1<< TWEN);             // Clear TWI interrupt flag,Enable TWI
	while(!(TWCR & (1<< TWINT)));                // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != RD_BYTE_WITH_NACK);   // Check for the acknowledgment
	return TWDR;
}




void i2c_stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);  // Clear TWI interrupt flag, Put stop condition on SDA,Enable TWI
	return;
}



void i2c_slave_check_slave_address_received_with_write_req(void)
{
	TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT);       // enable acknowledgment after receive, Enable TWI, Clear TWI interrupt flag
	while (!(TWCR & (1<<TWINT)));                    // Wait for TWINT flag
	while((TWSR & 0xF8) != SLAVE_ADD_RCVD_WR_REQ) ;
	return;
}



void i2c_slave_check_slave_address_received_with_read_req(void)
{
	TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT);    // enable acknowledgment after receive, Enable TWI, Clear TWI interrupt flag
	while (!(TWCR & (1<<TWINT)));                 // Wait for TWINT flag
	while((TWSR & 0xF8) != SLAVE_ADD_RCVD_RD_REQ);
	return;
}



unsigned char i2c_slave_read_byte(void)
{
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);     // Clear TWI interrupt flag,Get enable acknowledgment, Enable TWI
	while(!(TWCR & (1<<TWINT)));                   // Wait for TWINT flag
	while((TWSR & 0xF8) != SLAVE_DATA_RECEIVED);
	return TWDR;
}




void i2c_slave_write_byte(unsigned char byte)
{
	TWDR = byte;
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);        // Clear TWI interrupt flag,Get enable acknowledgment, Enable TWI
	while(!(TWCR & (1<<TWINT)));                      // Wait for TWINT flag
	while((TWSR & 0xF8) != SLAVE_BYTE_TRANSMITTED);   // Data byte in TWDR has been transmitted
	return;
}
