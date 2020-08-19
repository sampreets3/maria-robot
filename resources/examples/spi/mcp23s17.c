#include "mcp23s17.h"
#include "spi.h"

// function to write value in SPI register
void writeReg(regName reg, uint8_t val)
{
    uint8_t opcode = 0x40;
    beginTransaction();
    transfer8(opcode);	//Send device opcode
    transfer8(reg);		//Send register address
    transfer8(val);		//Send value for register
    endTransaction();
}

// function to read the value of SPI register.
uint8_t readReg(regName reg)
{
    beginTransaction();

    uint8_t value = 0;
    uint8_t opcode = 0x41;
    transfer8(opcode);          //Send device opcode
    transfer8(reg);              //Send register address
    value = transfer8(0x55);	//Catch the value from the slave
    endTransaction();

    return value;
}

// function to set bit in GPIO 
void setBitInReg(regName reg, uint8_t bitNum)
{   // read the value of corresponding GPIO
    uint8_t mask = readReg(reg);
	//add a proper mask to set a bit.
    mask |= 1 << bitNum;
	// write corresponding GPIO with new mask.
    writeReg(reg, mask);
}

// function to clear a bit in GPIO.
void clearBitInReg(regName reg, uint8_t bitNum)
{   
   // read the value of corresponding GPIO
    uint8_t mask = readReg(reg);
	//add a proper mask to clear a bit.
    mask &= ~(1 << bitNum);
	// write corresponding GPIO with new mask.
    writeReg(reg, mask);
}

void begin()                                     
{   // configure SPI for communication.
    setupSPI();                                 
}

// function to write value in the bit of corresponding GPIO register
void mcpDigitalWrite(port p, uint8_t bitNum, value val) 
{   
   // select appropriate GPIO register
    uint8_t regCh;
    if (p == PORTA){
        regCh = MCPGPIOA;
    } else {
        regCh = MCPGPIOB;
    }
    switch(val)
    {   
	    // call setBitInReg() function to set the bit to HIGH.
        case HIGH: setBitInReg(regCh, bitNum);
            break;
			
        // call clearBitInReg() to set the bit to LOW    
        case LOW: clearBitInReg(regCh, bitNum);
            break;
    }
}

// function to set mode of particular bit in the register.
void mcpPinMode(port p, uint8_t bitNum, mode m)     
    uint8_t regDir, regMod;    
	
     // select the correct register based on user input.    
    if (p == PORTA) {    

       // IODIR register Controls the direction of the data I/O.	
        regDir = IODIRA;  
        
      //The GPPU register controls the pull-up resistors for the port pins.		
        regMod = GPPUA;                          
    } else {
        regDir = IODIRB;                        
        regMod = GPPUB;
    }
    switch(m)                                  
    {   
	   // based on the mode call the appropriate low level functions
        case OUTPUT:       
       
       //  for OUTPUT mode call clearBitInReg() to clear the bit in the IODIR register. This makes it set to OUTPUT.	   
            clearBitInReg(regDir, bitNum);  
			writeReg(regMod, 0x00);		//so that it is reset  
            break;
        
      //   for INPUT mode call setBitInReg() to set the bit in the IODIR register. This makes it set to INPUT.	   		
        case INPUT:                          
            setBitInReg(regDir, bitNum);
			writeReg(regMod, 0x00);		//so that it is reset
            break;
			
      //   for INPUT_PULLUP mode call setBitInReg() to set the bit in the IODIR register and again call setBitInReg() to set the bit in the GPPU register This makes it set to INPUT_PULLUP.     
        case INPUT_PULLUP:                  
            setBitInReg(regDir, bitNum);
            setBitInReg(regMod, bitNum);
            break;
    }
}


// function to read PORT value
uint8_t readBits(port p)           
    uint8_t regCh;
	
	// select correct GPIO register from user input
    if (p == PORTA){              
        regCh = MCPGPIOA;
    } else {
        regCh = MCPGPIOB;
    }
    
	// call readReg() function to read value of register
    uint8_t readVal = readReg(regCh);
	
	// return the value so that it can be used outside.
	return readVal;                   
}



