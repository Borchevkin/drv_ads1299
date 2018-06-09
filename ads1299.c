#include "ads1299.h"

void ADS1299_HardReset(ads1299_t * ads1299)
{
	ads1299->SetReset(0);
	ads1299->DelayMs(1000);
	ads1299->SetReset(1);
}

void ADS1299_Init(ads1299_t * ads1299)
{
	ads1299->SetStart(0);

	// Hard reset
	ADS1299_HardReset(ads1299);

	//TODO
}

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

void ADS1299_GetIdState(ads1299_t * ads1299)
{
	uint8_t buffer = 0;
	buffer = ADS1299_ReadReg(ads1299, ADS1299_ID_REG);
	//TODO Parsing
}

void ADS1299_GetConfig1State(ads1299_t * ads1299)
{

}

void ADS1299_GetConfig2State(ads1299_t * ads1299)
{

}

void ADS1299_GetConfig3State(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffState(ads1299_t * ads1299)
{

}

void ADS1299_GetChNSetState(ads1299_t * ads1299)
{

}

void ADS1299_GetBiasSensPState(ads1299_t * ads1299)
{

}

void ADS1299_GetBiasSensNState(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffSensPState(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffSensNState(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffFlipState(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffStatPState(ads1299_t * ads1299)
{

}

void ADS1299_GetLoffStatNState(ads1299_t * ads1299)
{

}

void ADS1299_GetGpioState(ads1299_t * ads1299)
{

}

void ADS1299_GetMisc1State(ads1299_t * ads1299)
{

}

void ADS1299_GetMisc2State(ads1299_t * ads1299)
{

}

void ADS1299_GetCpnfig4State(ads1299_t * ads1299)
{

}
