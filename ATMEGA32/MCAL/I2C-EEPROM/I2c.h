
#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte req is received

void i2c_init_master(void);
void i2c_init_slave(void);
void i2c_start(void);
void i2c_repeated_start(void);
void i2c_send_slave_address_with_write_req(unsigned char slave_address);
void i2c_send_slave_address_with_read_req(unsigned char slave_address);
void i2c_write_byte(unsigned char byte);
unsigned char i2c_read_byte(void);
void i2c_stop(void);
void i2c_slave_check_slave_address_received_with_write_req(void);
void i2c_slave_check_slave_address_received_with_read_req(void);
unsigned char i2c_slave_read_byte(void);
void i2c_slave_write_byte(unsigned char byte);

#endif

