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
\brief Function for reset.
*/
void ADS1299_Reset(ads1299_t * ads1299)
{
    uint8_t writeCmd[3] = {0};
    uint8_t rx[3] = {0};

    writeCmd[0] = ADS1299_RESET_CMD;
    writeCmd[1] = 0x00;
    writeCmd[2] = 0x00;

    ads1299->SetCS(0);
    ads1299->Transfer(writeCmd, rx, 3);
    ads1299->SetCS(1);
}

/*!
\brief Function for exit from low-power standby mode.
*/
void ADS1299_WakeUp(ads1299_t * ads1299)
{
    uint8_t writeCmd[3] = {0};
    uint8_t rx[3] = {0};

    writeCmd[0] = ADS1299_WAKEUP_CMD;
    writeCmd[1] = 0x00;
    writeCmd[2] = 0x00;

    ads1299->SetCS(0);
    ads1299->Transfer(writeCmd, rx, 3);
    ads1299->SetCS(1);
}

/*!
\brief Function for low-power standby mode.
*/
void ADS1299_StandBy(ads1299_t * ads1299)
{
    uint8_t writeCmd[3] = {0};
    uint8_t rx[3] = {0};

    writeCmd[0] = ADS1299_STANDBY_CMD;
    writeCmd[1] = 0x00;
    writeCmd[2] = 0x00;

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
    ADS1299_ParseIdReg(ads1299, buffer);
}

/*!
\brief Function for getting Configuration Register 1 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig1State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG1_REG);
    ADS1299_ParseConfig1Reg(ads1299, buffer);
}

/*!
\brief Function for getting Configuration Register 2 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig2State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG2_REG);
    ADS1299_ParseConfig2Reg(ads1299, buffer);
}

/*!
\brief Function for getting Configuration Register 3 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig3State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG3_REG);
    ADS1299_ParseConfig3Reg(ads1299, buffer);
}

/*!
\brief Function for getting Configuration Register 4 data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetConfig4State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CONFIG4_REG);
    ADS1299_ParseConfig4Reg(ads1299, buffer);
}

/*!
\brief Function for getting Lead-Off Control Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_REG);
    ADS1299_ParseLoffReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh1SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH1SET_REG);
    ADS1299_ParseCh1SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh2SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH2SET_REG);
    ADS1299_ParseCh2SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh3SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH3SET_REG);
    ADS1299_ParseCh3SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh4SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH4SET_REG);
    ADS1299_ParseCh4SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh5SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH5SET_REG);
    ADS1299_ParseCh5SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh6SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH6SET_REG);
    ADS1299_ParseCh6SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh7SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH7SET_REG);
    ADS1299_ParseCh7SetReg(ads1299, buffer);
}

/*!
\brief Function for getting Individual Channel Settings Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetCh8SetState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_CH8SET_REG);
    ADS1299_ParseCh8SetReg(ads1299, buffer);
}

/*!
\brief Function for getting BIAS Drive Positive Derivation Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetBiasSensPState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_BIAS_SENSP_REG);
    ADS1299_ParseBiasSensPReg(ads1299, buffer);
}

/*!
\brief Function for getting BIAS Drive Negative DerivationRegister data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetBiasSensNState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_BIAS_SENSN_REG);
    ADS1299_ParseBiasSensNReg(ads1299, buffer);
}

/*!
\brief Function for getting Positive Signal Lead-Off Detection Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffSensPState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_SENSP_REG);
    ADS1299_ParseLoffSensPReg(ads1299, buffer);
}

/*!
\brief Function for getting Negative Signal Lead-Off Detection Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffSensNState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_SENSN_REG);
    ADS1299_ParseLoffSensNReg(ads1299, buffer);
}

/*!
\brief Function for getting Lead-Off Flip Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffFlipState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_FLIP_REG);
    ADS1299_ParseLoffFlipReg(ads1299, buffer);
}

/*!
\brief Function for getting Lead-Off Positive Signal Status Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffStatPState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_STATP_REG);
    ADS1299_ParseLoffStatPReg(ads1299, buffer);
}

/*!
\brief Function for getting Lead-Off Negative Signal Status Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetLoffStatNState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_LOFF_STATN_REG);
    ADS1299_ParseLoffStatNReg(ads1299, buffer);
}

/*!
\brief Function for getting General-Purpose I/O Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetGpioState(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_GPIO_REG);
    ADS1299_ParseGpioReg(ads1299, buffer);
}

/*!
\brief Function for getting Miscellaneous 1 Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetMisc1State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_MISC1_REG);
    ADS1299_ParseMisc1Reg(ads1299, buffer);
}

/*!
\brief Function for getting Miscellaneous 2 Register data
\param [out] ads1299 Initialized variable of type ads1299_t
*/
void ADS1299_GetMisc2State(ads1299_t * ads1299)
{
    uint8_t buffer = 0;
    buffer = ADS1299_ReadReg(ads1299, ADS1299_MISC2_REG);
    //No Parsing
}


/* ---------------------------------------------------------- */


/* --------------- Parsing Functions Section --------------- */

/*!
\brief Parsing of ID Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal ID Register value
*/
void ADS1299_ParseIdReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->id.revId = (regVal & 0xE0) >> 5;
    ads1299->id.devId = (regVal & 0x0C) >> 2;
    ads1299->id.nuCh  = (regVal & 0x03);
}

/*!
\brief Parsing of Configuration 1 Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Configuration 1 Register value
*/
void ADS1299_ParseConfig1Reg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->config1.daisyEn   = (regVal & 0x40) >> 6;
    ads1299->config1.clkEn     = (regVal & 0x20) >> 5;
    ads1299->config1.dataRate  = (regVal & 0x07);
}

/*!
\brief Parsing of Configuration 2 Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Configuration 2 Register value
*/
void ADS1299_ParseConfig2Reg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->config2.intCal   = (regVal & 0x10) >> 4;
    ads1299->config2.calAmp   = (regVal & 0x04) >> 2;
    ads1299->config2.calFreq  = (regVal & 0x03);
}

/*!
\brief Parsing of Configuration 3 Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Configuration 3 Register value
*/
void ADS1299_ParseConfig3Reg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->config3.pdRefBuf      = (regVal & 0x80) >> 7;
    ads1299->config3.biasMeas      = (regVal & 0x10) >> 4;
    ads1299->config3.biasRefInt    = (regVal & 0x08) >> 3;
    ads1299->config3.pdBias        = (regVal & 0x04) >> 2;
    ads1299->config3.biasLoffSens  = (regVal & 0x02) >> 1;
    ads1299->config3.biasStat      = (regVal & 0x01);
}

/*!
\brief Parsing of Configuration 4 Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Configuration 4 Register value
*/
void ADS1299_ParseConfig4Reg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->config4.singleShot   = (regVal & 0x08) >> 3;
    ads1299->config4.pdLoffComp   = (regVal & 0x02) >> 1;
}

/*!
\brief Parsing of Lead-Off Control Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Lead-Off Control Register value
*/
void ADS1299_ParseLoffReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loff.compTh    = (regVal & 0xE0) >> 5;
    ads1299->loff.ileadOff  = (regVal & 0x0C) >> 2;
    ads1299->loff.fleadOff  = (regVal & 0x03);
}

/*!
\brief Parsing of Individual Channel 1 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh1SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch1set.pd1    = (regVal & 0x80) >> 7;
    ads1299->ch1set.gain1  = (regVal & 0x70) >> 4;
    ads1299->ch1set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch1set.mux1   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 2 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh2SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch2set.pd2    = (regVal & 0x80) >> 7;
    ads1299->ch2set.gain2  = (regVal & 0x70) >> 4;
    ads1299->ch2set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch2set.mux2   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 3 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh3SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch3set.pd3    = (regVal & 0x80) >> 7;
    ads1299->ch3set.gain3  = (regVal & 0x70) >> 4;
    ads1299->ch3set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch3set.mux3   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 4 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh4SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch4set.pd4    = (regVal & 0x80) >> 7;
    ads1299->ch4set.gain4  = (regVal & 0x70) >> 4;
    ads1299->ch4set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch4set.mux4   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 5 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh5SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch5set.pd5    = (regVal & 0x80) >> 7;
    ads1299->ch5set.gain5  = (regVal & 0x70) >> 4;
    ads1299->ch5set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch5set.mux5   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 6 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh6SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch6set.pd6    = (regVal & 0x80) >> 7;
    ads1299->ch6set.gain6  = (regVal & 0x70) >> 4;
    ads1299->ch6set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch6set.mux6   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 7 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh7SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch7set.pd7    = (regVal & 0x80) >> 7;
    ads1299->ch7set.gain7  = (regVal & 0x70) >> 4;
    ads1299->ch7set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch7set.mux7   = (regVal & 0x07);
}

/*!
\brief Parsing of Individual Channel 8 Settings Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Individual Channel Settings Register value
*/
void ADS1299_ParseCh8SetReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->ch8set.pd8    = (regVal & 0x80) >> 7;
    ads1299->ch8set.gain8  = (regVal & 0x70) >> 4;
    ads1299->ch8set.srb2   = (regVal & 0x08) >> 3;
    ads1299->ch8set.mux8   = (regVal & 0x07);
}

/*!
\brief Parsing of Bias Drive Positive Derivation Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Bias Drive Positive Derivation Register value
*/
void ADS1299_ParseBiasSensPReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->biassensp.biasP8    = (regVal & 0x80) >> 7;
    ads1299->biassensp.biasP7    = (regVal & 0x40) >> 6;
    ads1299->biassensp.biasP6    = (regVal & 0x20) >> 5;
    ads1299->biassensp.biasP5    = (regVal & 0x10) >> 4;
    ads1299->biassensp.biasP4    = (regVal & 0x08) >> 3;
    ads1299->biassensp.biasP3    = (regVal & 0x04) >> 2;
    ads1299->biassensp.biasP2    = (regVal & 0x02) >> 1;
    ads1299->biassensp.biasP1    = (regVal & 0x01);
}

/*!
\brief Parsing of Bias Drive Negative Derivation Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Bias Drive Negative Derivation Register value
*/
void ADS1299_ParseBiasSensNReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->biassensn.biasN8    = (regVal & 0x80) >> 7;
    ads1299->biassensn.biasN7    = (regVal & 0x40) >> 6;
    ads1299->biassensn.biasN6    = (regVal & 0x20) >> 5;
    ads1299->biassensn.biasN5    = (regVal & 0x10) >> 4;
    ads1299->biassensn.biasN4    = (regVal & 0x08) >> 3;
    ads1299->biassensn.biasN3    = (regVal & 0x04) >> 2;
    ads1299->biassensn.biasN2    = (regVal & 0x02) >> 1;
    ads1299->biassensn.biasN1    = (regVal & 0x01);
}

/*!
\brief Parsing of Positive Signal Lead-Off Detection Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Positive Signal Lead-Off Detection Register value
*/
void ADS1299_ParseLoffSensPReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loffsensp.loffP8    = (regVal & 0x80) >> 7;
    ads1299->loffsensp.loffP7    = (regVal & 0x40) >> 6;
    ads1299->loffsensp.loffP6    = (regVal & 0x20) >> 5;
    ads1299->loffsensp.loffP5    = (regVal & 0x10) >> 4;
    ads1299->loffsensp.loffP4    = (regVal & 0x08) >> 3;
    ads1299->loffsensp.loffP3    = (regVal & 0x04) >> 2;
    ads1299->loffsensp.loffP2    = (regVal & 0x02) >> 1;
    ads1299->loffsensp.loffP1    = (regVal & 0x01);
}

/*!
\brief Parsing of Negative Signal Lead-Off Detection Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Negative Signal Lead-Off Detection Register value
*/
void ADS1299_ParseLoffSensNReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loffsensn.loffN8    = (regVal & 0x80) >> 7;
    ads1299->loffsensn.loffN7    = (regVal & 0x40) >> 6;
    ads1299->loffsensn.loffN6    = (regVal & 0x20) >> 5;
    ads1299->loffsensn.loffN5    = (regVal & 0x10) >> 4;
    ads1299->loffsensn.loffN4    = (regVal & 0x08) >> 3;
    ads1299->loffsensn.loffN3    = (regVal & 0x04) >> 2;
    ads1299->loffsensn.loffN2    = (regVal & 0x02) >> 1;
    ads1299->loffsensn.loffN1    = (regVal & 0x01);
}

/*!
\brief Parsing of Lead-Off Flip Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Lead-Off Flip Register value
*/
void ADS1299_ParseLoffFlipReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loffflip.loffFlip8  = (regVal & 0x80) >> 7;
    ads1299->loffflip.loffFlip7  = (regVal & 0x40) >> 6;
    ads1299->loffflip.loffFlip6  = (regVal & 0x20) >> 5;
    ads1299->loffflip.loffFlip5  = (regVal & 0x10) >> 4;
    ads1299->loffflip.loffFlip4  = (regVal & 0x08) >> 3;
    ads1299->loffflip.loffFlip3  = (regVal & 0x04) >> 2;
    ads1299->loffflip.loffFlip2  = (regVal & 0x02) >> 1;
    ads1299->loffflip.loffFlip1  = (regVal & 0x01);
}

/*!
\brief Parsing of Lead-Off Positive Signal Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Lead-Off Positive Signal Register value
*/
void ADS1299_ParseLoffStatPReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loffstatp.in8pOff   = (regVal & 0x80) >> 7;
    ads1299->loffstatp.in7pOff   = (regVal & 0x40) >> 6;
    ads1299->loffstatp.in6pOff   = (regVal & 0x20) >> 5;
    ads1299->loffstatp.in5pOff   = (regVal & 0x10) >> 4;
    ads1299->loffstatp.in4pOff   = (regVal & 0x08) >> 3;
    ads1299->loffstatp.in3pOff   = (regVal & 0x04) >> 2;
    ads1299->loffstatp.in2pOff   = (regVal & 0x02) >> 1;
    ads1299->loffstatp.in1pOff   = (regVal & 0x01);
}

/*!
\brief Parsing of Lead-Off Negative Signal Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Lead-Off Negative Signal Register value
*/
void ADS1299_ParseLoffStatNReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->loffstatn.in8nOff   = (regVal & 0x80) >> 7;
    ads1299->loffstatn.in7nOff   = (regVal & 0x40) >> 6;
    ads1299->loffstatn.in6nOff   = (regVal & 0x20) >> 5;
    ads1299->loffstatn.in5nOff   = (regVal & 0x10) >> 4;
    ads1299->loffstatn.in4nOff   = (regVal & 0x08) >> 3;
    ads1299->loffstatn.in3nOff   = (regVal & 0x04) >> 2;
    ads1299->loffstatn.in2nOff   = (regVal & 0x02) >> 1;
    ads1299->loffstatn.in1nOff   = (regVal & 0x01);
}

/*!
\brief Parsing of GPIO Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal GPIO Register value
*/
void ADS1299_ParseGpioReg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->gpio.gpioD  = (regVal & 0xF0) >> 4;
    ads1299->gpio.gpioC  = (regVal & 0x0F);
}

/*!
\brief Parsing of Miscellaneous 1 Register result
\param [out] ads1299 Initialized variable of type ads1299_t
\param [in] regVal Miscellaneous 1 Register value
*/
void ADS1299_ParseMisc1Reg(ads1299_t * ads1299, uint8_t regVal)
{
    ads1299->misc1.srb1  = (regVal & 0x20) >> 5;
}

/* ---------------------------------------------------------- */


/* -------- Setting Register Value Functions Section -------- */

/*!
\brief Function for setting Configuration 1 Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetConfig1State(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CONFIG1_REG , regVal);
}

/*!
\brief Function for setting Configuration 2 Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetConfig2State(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CONFIG2_REG , regVal);
}

/*!
\brief Function for setting Lead-Off Control Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetLoffState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_LOFF_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh1SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH1SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh2SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH2SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh3SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH3SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh4SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH4SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh5SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH5SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh6SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH6SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh7SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH7SET_REG , regVal);
}

/*!
\brief Function for setting Individual Channel Settings Register value
\param [in] regVal Value of register to set
*/
void ADS1299_SetCh8SetState(ads1299_t * ads1299, uint8_t regVal)
{
    ADS1299_WriteReg(ads1299, ADS1299_CH8SET_REG , regVal);
}
/* ---------------------------------------------------------- */
