

#include "Std_Types.h"
#include "Utilites.h"
#include "I2C_Int.h"
#include "EEPROM_init.h"

void EEPROM_Init(){
	I2c_Init_Master();
}

u8 EEPROM_READ_DATA(u16 address){

	u16 row_address = 0;

	I2c_Start();

	if((address >= 0) && (address < 256)){
		row_address = address - 0;

		I2c_Send_slave_address_with_write_req(0b01010000);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

		I2c_Send_slave_address_with_read_req(0b01010000);

	} else if((address >= 256) && (address < 512)){
		row_address = address - 256;

		I2c_Send_slave_address_with_write_req(0b01010010);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

		I2c_Send_slave_address_with_read_req(0b01010010);
	} else if((address >= 512) && (address < 768)){
		row_address = address - 512;

		I2c_Send_slave_address_with_write_req(0b01010100);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01010100);

	} else if((address >= 768) && (address < 1024)){
		row_address = address - 768;

		I2c_Send_slave_address_with_write_req(0b01010110);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01010110);
	} else if((address >= 1024) && (address < 1280)){
		row_address = address - 1024;

		I2c_Send_slave_address_with_write_req(0b01011000);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01011000);
	} else if((address >= 1280) && (address < 1536)){
		row_address = address - 1280;

		I2c_Send_slave_address_with_write_req(0b01011010);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01011010);
	}else if((address >= 1536) && (address < 1792)){
		row_address = address - 1536;

		I2c_Send_slave_address_with_write_req(0b01011100);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01011100);
	}else if((address >= 1792) && (address < 2048)){
		row_address = address - 1792;

		I2c_Send_slave_address_with_write_req(0b01011110);

		I2c_Write_byte(row_address);

		I2c_Repeated_start();

				I2c_Send_slave_address_with_read_req(0b01011110);
	}

//	I2c_Send_slave_address_with_write_req(0b01010000);
//
//	I2c_Write_byte(address);
//
//	I2c_Write_byte(data);

	u8 data = I2c_Read_byte();

		I2c_Stop();

		return data;

}

void EEPROM_WRITE_DATA(u16 address, u8 data){


	u16 row_address = 0;

		I2c_Start();

		if((address >= 0) && (address < 256)){
			row_address = address - 0;

			I2c_Send_slave_address_with_write_req(0b01010000);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);

		} else if((address >= 256) && (address < 512)){
			row_address = address - 256;

			I2c_Send_slave_address_with_write_req(0b01010010);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);

		} else if((address >= 512) && (address < 768)){
			row_address = address - 512;

			I2c_Send_slave_address_with_write_req(0b01010100);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		} else if((address >= 768) && (address < 1024)){
			row_address = address - 768;

			I2c_Send_slave_address_with_write_req(0b01010110);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		} else if((address >= 1024) && (address < 1280)){
			row_address = address - 1024;

			I2c_Send_slave_address_with_write_req(0b01011000);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		} else if((address >= 1280) && (address < 1536)){
			row_address = address - 1280;

			I2c_Send_slave_address_with_write_req(0b01011010);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		}else if((address >= 1536) && (address < 1792)){
			row_address = address - 1536;

			I2c_Send_slave_address_with_write_req(0b01011100);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		}else if((address >= 1792) && (address < 2048)){
			row_address = address - 1792;

			I2c_Send_slave_address_with_write_req(0b01011110);

			I2c_Write_byte(row_address);

			I2c_Write_byte(data);
		}

//	I2c_Start();
//
//	I2c_Send_slave_address_with_write_req(0b01010000);

//	I2c_Write_byte(address);
//
////	I2c_Stop();
////
////	I2c_Start();
//
//	I2c_Repeated_start();
//
//	I2c_Send_slave_address_with_read_req(0b01010000);

		I2c_Stop();


}














