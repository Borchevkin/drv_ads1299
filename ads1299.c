#include "ads1299.h"

/*!
\brief Reset ADS1299 by control RESET pin
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_HardReset(ads1299_t * ads1299)
{
	ads1299->SetReset(0);
	ads1299->DelayMs(1000);
	ads1299->SetReset(1);
}

/*!
\brief Init ADS1299 according to datasheet's sequence
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_Init(ads1299_t * ads1299)
{
	ads1299->SetStart(0);

	// Hard reset
	ADS1299_HardReset(ads1299);

	//TODO
}

/*!
\brief Function for reading register data
\param [in] regAddress Address of register to read
\return Value of wanted register
*/
uint8_t ADS1299_ReadReg(ads1299_t * ads1299, uint8_t regAddress)
{
	uint8_t data = 0;
	uint8_t readCmd[4] = {0};
	uint8_t rx[4] = {0};

	readCmd[0] = ADS1299_READ_REG_CMD | regAddress;
	readCmd[1] = 0x00;
	readCmd[2] = 0x00;
	readCmd[3] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(readCmd, rx, 4);
	ads1299->SetCS(1);

	data = rx[2];

	return data;
}

/*!
\brief Function for writing data to register
\param [in] regAddress Address of register to read
\param [in] data[] Data
*/
void ADS1299_WriteReg(ads1299_t * ads1299, uint8_t regAddress, uint8_t data)
{
	uint8_t writeCmd[3] = {0};
	uint8_t rx[3] = {0};

	writeCmd[0] = ADS1299_WRITE_REG_CMD | regAddress;
	writeCmd[1] = 0x00;
	writeCmd[2] = data;

	ads1299->SetCS(0);
	ads1299->Transfer(writeCmd, rx, 3);
	ads1299->SetCS(1);
}

/*!
\brief Function for triggering ADC conversion.
*/
void ADS1299_StartAdc(ads1299_t * ads1299)
{
	uint8_t writeCmd[3] = {0};
	uint8_t rx[3] = {0};

	writeCmd[0] = ADS1299_START_CMD;
	writeCmd[1] = 0x00;
	writeCmd[2] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(writeCmd, rx, 3);
	ads1299->SetCS(1);
}

/*!
\brief Function for stopping ADC conversion.
*/
void ADS1299_StopAdc(ads1299_t * ads1299)
{
	uint8_t writeCmd[3] = {0};
	uint8_t rx[3] = {0};

	writeCmd[0] = ADS1299_STOP_CMD;
	writeCmd[1] = 0x00;
	writeCmd[2] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(writeCmd, rx, 3);
	ads1299->SetCS(1);
}

/*!
\brief Function for reading the ADC value from the register.
*/
uint32_t ADS1299_ReadAdc(ads1299_t * ads1299)
{
	int32_t msg = 0;
	uint8_t readCmd[7] = {0};
	uint8_t rx[7] = {0};

	readCmd[0] = ADS1299_RDATA_CMD;
	readCmd[1] = 0x00;
	readCmd[2] = 0x00;
	readCmd[3] = 0x00;
	readCmd[4] = 0x00;
	readCmd[5] = 0x00;
	readCmd[6] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(readCmd, rx, 7);
	ads1299->SetCS(1);

	//TODO calculate how much data we have to receive
	//msg |= rx[2] << 24;
	//msg |= rx[3] << 16;
	//msg |= rx[4] << 8;
	//msg |= rx[5];

	return msg;
}

/*!
\brief Function, that enable Read Data Continuous mode
*/
void ADS1299_EnableContRead(ads1299_t * ads1299)
{
	uint8_t writeCmd[3] = {0};
	uint8_t rx[3] = {0};

	writeCmd[0] = ADS1299_RDATAC_CMD;
	writeCmd[1] = 0x00;
	writeCmd[2] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(writeCmd, rx, 3);
	ads1299->SetCS(1);
}

/*!
\brief Function, that disable Read Data Continuous mode
*/
void ADS1299_DisableContRead(ads1299_t * ads1299)
{
	uint8_t writeCmd[3] = {0};
	uint8_t rx[3] = {0};

	writeCmd[0] = ADS1299_SDATAC_CMD;
	writeCmd[1] = 0x00;
	writeCmd[2] = 0x00;

	ads1299->SetCS(0);
	ads1299->Transfer(writeCmd, rx, 3);
	ads1299->SetCS(1);
}


/* -------- Reading Register Data Functions Section -------- */

/*!
\brief Function for getting Device Identification Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetIdState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_ID_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Configuration Register 1 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig1State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG1_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Configuration Register 2 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig2State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG2_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Configuration Register 3 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig3State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG3_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Lead-Off Control Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetChNSetState(ads1299_t * ads1299, uint8_t chRegAddress)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, chRegAddress);
	//TODO Parsing
}

/*!
\brief Function for getting BIAS Drive Positive Derivation Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetBiasSensPState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_BIAS_SENSP_REG);
	//TODO Parsing
}

/*!
\brief Function for getting BIAS Drive Negative DerivationRegister data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetBiasSensNState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_BIAS_SENSN_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Positive Signal Lead-Off Detection Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffSensPState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_SENSP_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Negative Signal Lead-Off Detection Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffSensNState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_SENSN_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Lead-Off Flip Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffFlipState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_FLIP_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Lead-Off Positive Signal Status Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffStatPState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_STATP_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Lead-Off Negative Signal Status Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffStatNState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_STATN_REG);
	//TODO Parsing
}

/*!
\brief Function for getting General-Purpose I/O Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetGpioState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_GPIO_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Miscellaneous 1 Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetMisc1State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_MISC1_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Miscellaneous 2 Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetMisc2State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_MISC2_REG);
	//TODO Parsing
}

/*!
\brief Function for getting Configuration Register 4 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCpnfig4State(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG4_REG);
	//TODO Parsing
}

/* ---------------------------------------------------------- */


/* --------------- Parsing Functions Section --------------- */

/*!
\brief Parsing of ID Register result
\param [out] ads1263 Initialized variable of type ads1263_t
\param [in] regVal ID Register value
*/

void ADS1299_ParseIdReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->id.devId = (regVal & 0xE0) >> 5;
    ads1299->id.revId = (regVal & 0x1F);
}

/* ---------------------------------------------------------- */


/* -------- Setting Register Value Functions Section -------- */

/* ---------------------------------------------------------- */
