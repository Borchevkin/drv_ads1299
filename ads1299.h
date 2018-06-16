#ifndef DRV_ADS1299_ADS1299_H_
#define DRV_ADS1299_ADS1299_H_

#include <stdint.h>

/* ____________________ DEFINE Section ____________________ */
/* Register addresses */
#define ADS1299_ID_REG                  (0x00)
#define ADS1299_CONFIG1_REG             (0x01)
#define ADS1299_CONFIG2_REG             (0x02)
#define ADS1299_CONFIG3_REG             (0x03)
#define ADS1299_LOFF_REG                (0x04)
#define ADS1299_CH1SET_REG              (0x05)
#define ADS1299_CH2SET_REG              (0x06)
#define ADS1299_CH3SET_REG              (0x07)
#define ADS1299_CH4SET_REG              (0x08)
#define ADS1299_CH5SET_REG              (0x09)
#define ADS1299_CH6SET_REG              (0x0A)
#define ADS1299_CH7SET_REG              (0x0B)
#define ADS1299_CH8SET_REG              (0x0C)
#define ADS1299_BIAS_SENSP_REG          (0x0D)
#define ADS1299_BIAS_SENSN_REG          (0x0E)
#define ADS1299_LOFF_SENSP_REG          (0x0F)
#define ADS1299_LOFF_SENSN_REG          (0x10)
#define ADS1299_LOFF_FLIP_REG           (0x11)
#define ADS1299_LOFF_STATP_REG          (0x12)
#define ADS1299_LOFF_STATN_REG          (0x13)
#define ADS1299_GPIO_REG                (0x14)
#define ADS1299_MISC1_REG               (0x15)
#define ADS1299_MISC2_REG               (0x16)
#define ADS1299_CONFIG4_REG             (0x17)

/* Commands */
#define ADS1299_WAKEUP_CMD              (0x02)
#define ADS1299_STANDBY_CMD             (0x04)
#define ADS1299_RESET_CMD               (0x06)
#define ADS1299_START_CMD               (0x08)
#define ADS1299_STOP_CMD                (0x0A)
#define ADS1299_RDATAC_CMD              (0x10)
#define ADS1299_SDATAC_CMD              (0x11)
#define ADS1299_RDATA_CMD               (0x12)
#define ADS1299_READ_REG_CMD            (0x20)
#define ADS1299_WRITE_REG_CMD           (0x40)

/* ________________________________________________________ */

/* ____________________ Types  Section ____________________ */

typedef struct {
	uint8_t revId;
	uint8_t devId;
	uint8_t nuCh;
} id_t;

typedef struct {
	uint8_t daisyEn;
	uint8_t clkEn;
	uint8_t dataRate;
} config1_t;

typedef struct {
	uint8_t intCal;
	uint8_t calAmp;
	uint8_t calFreq;
} config2_t;

typedef struct {
	uint8_t pdRefBuf;
	uint8_t biasMeas;
	uint8_t biasRefInt;
	uint8_t pdBias;
	uint8_t biasLoffSens;
	uint8_t biasStat;
} config3_t;

typedef struct {
	uint8_t singleShot;
	uint8_t pdLoffComp;
} config4_t;

typedef struct {
	uint8_t compTh;
	uint8_t ileadOff;
	uint8_t fleadOff;
} loff_t;

typedef struct {
	uint8_t pd1;
	uint8_t gain1;
	uint8_t srb2;
	uint8_t mux1;
} ch1set_t;

typedef struct {
	uint8_t pd2;
	uint8_t gain2;
	uint8_t srb2;
	uint8_t mux2;
} ch2set_t;

typedef struct {
	uint8_t pd3;
	uint8_t gain3;
	uint8_t srb2;
	uint8_t mux3;
} ch3set_t;

typedef struct {
	uint8_t pd4;
	uint8_t gain4;
	uint8_t srb2;
	uint8_t mux4;
} ch4set_t;

typedef struct {
	uint8_t pd5;
	uint8_t gain5;
	uint8_t srb2;
	uint8_t mux5;
} ch5set_t;

typedef struct {
	uint8_t pd6;
	uint8_t gain6;
	uint8_t srb2;
	uint8_t mux6;
} ch6set_t;

typedef struct {
	uint8_t pd7;
	uint8_t gain7;
	uint8_t srb2;
	uint8_t mux7;
} ch7set_t;

typedef struct {
	uint8_t pd8;
	uint8_t gain8;
	uint8_t srb2;
	uint8_t mux8;
} ch8set_t;

typedef struct {
	uint8_t biasP8;
	uint8_t biasP7;
	uint8_t biasP6;
	uint8_t biasP5;
	uint8_t biasP4;
	uint8_t biasP3;
	uint8_t biasP2;
	uint8_t biasP1;
} biassensp_t;

typedef struct {
	uint8_t biasN8;
	uint8_t biasN7;
	uint8_t biasN6;
	uint8_t biasN5;
	uint8_t biasN4;
	uint8_t biasN3;
	uint8_t biasN2;
	uint8_t biasN1;
} biassensn_t;

typedef struct {
	uint8_t loffP8;
	uint8_t loffP7;
	uint8_t loffP6;
	uint8_t loffP5;
	uint8_t loffP4;
	uint8_t loffP3;
	uint8_t loffP2;
	uint8_t loffP1;
} loffsensp_t;

typedef struct {
	uint8_t loffN8;
	uint8_t loffN7;
	uint8_t loffN6;
	uint8_t loffN5;
	uint8_t loffN4;
	uint8_t loffN3;
	uint8_t loffN2;
	uint8_t loffN1;
} loffsensn_t;

typedef struct {
	uint8_t loffFlip8;
	uint8_t loffFlip7;
	uint8_t loffFlip6;
	uint8_t loffFlip5;
	uint8_t loffFlip4;
	uint8_t loffFlip3;
	uint8_t loffFlip2;
	uint8_t loffFlip1;
} loffflip_t;

typedef struct {
	uint8_t in8pOff;
	uint8_t in7pOff;
	uint8_t in6pOff;
	uint8_t in5pOff;
	uint8_t in4pOff;
	uint8_t in3pOff;
	uint8_t in2pOff;
	uint8_t in1pOff;
} loffstatp_t;

typedef struct {
	uint8_t in8nOff;
	uint8_t in7nOff;
	uint8_t in6nOff;
	uint8_t in5nOff;
	uint8_t in4nOff;
	uint8_t in3nOff;
	uint8_t in2nOff;
	uint8_t in1nOff;
} loffstatn_t;

typedef struct {
	uint8_t gpioD;
	uint8_t gpioC;
} gpio_t;

typedef struct {
	uint8_t srb1;
} misc1_t;

typedef struct {
} misc2_t;

typedef struct {
    void (*DelayMs)(uint32_t delay);
    void (*Transfer)(uint8_t tx[], uint8_t rx[], uint8_t len);
    void (*SetCS)(uint8_t state);
    void (*SetReset)(uint8_t state);
    void (*SetStart)(uint8_t state);

    id_t id;
    config1_t config1;
    config2_t config2;
    config3_t config3;
    loff_t loff;
    ch1set_t ch1set;
    ch2set_t ch2set;
    ch3set_t ch3set;
    ch4set_t ch4set;
    ch5set_t ch5set;
    ch6set_t ch6set;
    ch7set_t ch7set;
    ch8set_t ch8set;
    biassensp_t biassensp;
    biassensn_t biassensn;
    loffsensp_t loffsensp;
    loffsensn_t loffsensn;
    loffflip_t loffflip;
    loffstatp_t loffstatp;
    loffstatn_t loffstatn;
    gpio_t gpio;
    misc1_t misc1;
    misc2_t misc2;
    config4_t config4;

} ads1299_t;

/* ________________________________________________________ */

/* __________________ Prototypes Section __________________ */
void ADS1299_HardReset(ads1299_t * ads1299);
void ADS1299_Init(ads1299_t * ads1299);

void ADS1299_Reset(ads1299_t * ads1299);
void ADS1299_WakeUp(ads1299_t * ads1299);
void ADS1299_StandBy(ads1299_t * ads1299);
void ADS1299_StartAdc(ads1299_t * ads1299);
void ADS1299_StopAdc(ads1299_t * ads1299);
uint32_t ADS1299_ReadAdc(ads1299_t * ads1299);
void ADS1299_EnableContRead(ads1299_t * ads1299);
void ADS1299_DisableContRead(ads1299_t * ads1299);

uint8_t ADS1299_ReadReg(ads1299_t * ads1299, uint8_t regAddress);
void ADS1299_WriteReg(ads1299_t * ads1299, uint8_t regAddress, uint8_t data);

/*          Reading Register Data Functions Section          */
void ADS1299_GetIdState(ads1299_t * ads1299);
void ADS1299_GetConfig1State(ads1299_t * ads1299);
void ADS1299_GetConfig2State(ads1299_t * ads1299);
void ADS1299_GetConfig3State(ads1299_t * ads1299);
void ADS1299_GetConfig4State(ads1299_t * ads1299);
void ADS1299_GetLoffState(ads1299_t * ads1299);
void ADS1299_GetCh1SetState(ads1299_t * ads1299);
void ADS1299_GetCh2SetState(ads1299_t * ads1299);
void ADS1299_GetCh3SetState(ads1299_t * ads1299);
void ADS1299_GetCh4SetState(ads1299_t * ads1299);
void ADS1299_GetCh5SetState(ads1299_t * ads1299);
void ADS1299_GetCh6SetState(ads1299_t * ads1299);
void ADS1299_GetCh7SetState(ads1299_t * ads1299);
void ADS1299_GetCh8SetState(ads1299_t * ads1299);
void ADS1299_GetBiasSensPState(ads1299_t * ads1299);
void ADS1299_GetBiasSensNState(ads1299_t * ads1299);
void ADS1299_GetLoffSensPState(ads1299_t * ads1299);
void ADS1299_GetLoffSensNState(ads1299_t * ads1299);
void ADS1299_GetLoffFlipState(ads1299_t * ads1299);
void ADS1299_GetLoffStatPState(ads1299_t * ads1299);
void ADS1299_GetLoffStatNState(ads1299_t * ads1299);
void ADS1299_GetGpioState(ads1299_t * ads1299);
void ADS1299_GetMisc1State(ads1299_t * ads1299);
void ADS1299_GetMisc2State(ads1299_t * ads1299);
/* --------------------------------------------------------- */

/*                 Parsing Functions Section                 */
void ADS1299_ParseIdReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseConfig1Reg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseConfig2Reg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseConfig3Reg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseConfig4Reg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh1SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh2SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh3SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh4SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh5SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh6SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh7SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseCh8SetReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseBiasSensPReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseBiasSensNReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffSensPReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffSensNReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffFlipReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffStatPReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseLoffStatNReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseGpioReg(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_ParseMisc1Reg(ads1299_t * ads1299, uint8_t regVal);
/* --------------------------------------------------------- */


/* ________________________________________________________ */

#endif /* DRV_ADS1299_ADS1299_H_ */
