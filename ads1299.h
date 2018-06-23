#ifndef DRV_ADS1299_ADS1299_H_
#define DRV_ADS1299_ADS1299_H_

#include <stdint.h>

/* ____________________ DEFINE Section ____________________ */
/* Register addresses */
#define ADS1299_ID_REG                   (0x00)
#define ADS1299_CONFIG1_REG              (0x01)
#define ADS1299_CONFIG2_REG              (0x02)
#define ADS1299_CONFIG3_REG              (0x03)
#define ADS1299_LOFF_REG                 (0x04)
#define ADS1299_CH1SET_REG               (0x05)
#define ADS1299_CH2SET_REG               (0x06)
#define ADS1299_CH3SET_REG               (0x07)
#define ADS1299_CH4SET_REG               (0x08)
#define ADS1299_CH5SET_REG               (0x09)
#define ADS1299_CH6SET_REG               (0x0A)
#define ADS1299_CH7SET_REG               (0x0B)
#define ADS1299_CH8SET_REG               (0x0C)
#define ADS1299_BIAS_SENSP_REG           (0x0D)
#define ADS1299_BIAS_SENSN_REG           (0x0E)
#define ADS1299_LOFF_SENSP_REG           (0x0F)
#define ADS1299_LOFF_SENSN_REG           (0x10)
#define ADS1299_LOFF_FLIP_REG            (0x11)
#define ADS1299_LOFF_STATP_REG           (0x12)
#define ADS1299_LOFF_STATN_REG           (0x13)
#define ADS1299_GPIO_REG                 (0x14)
#define ADS1299_MISC1_REG                (0x15)
#define ADS1299_MISC2_REG                (0x16)
#define ADS1299_CONFIG4_REG              (0x17)

/* Register settings */
#define ADS1299_CONFIG1_SETUP_250        (0x96)    // 250 SPS
#define ADS1299_CONFIG1_SETUP_500        (0x95)    // 500 SPS
#define ADS1299_CONFIG1_SETUP_1000       (0x94)    // 1 kSPS
#define ADS1299_CONFIG1_SETUP_2000       (0x93)    // 2 kSPS
#define ADS1299_CONFIG1_SETUP_4000       (0x92)    // 4 kSPS
#define ADS1299_CONFIG1_SETUP_8000       (0x91)    // 8 kSPS
#define ADS1299_CONFIG1_SETUP_16000      (0x90)    // 16 kSPS
#define ADS1299_CONFIG2_SETUP_TEST       (0xD0)    // Test signals are generated internally
#define ADS1299_CONFIG3_SETUP_REFBUF     (0xE0)    // Enable internal reference buffer
#define ADS1299_CONFIG3_SETUP_LOFF_STAT  (0x61)    // BIAS is not connected
#define ADS1299_CONFIG4_SETUP_LOFF_C_EN  (0x02)    // Continuous conversion mode / Lead-Off comp enabled
#define ADS1299_CONFIG4_SETUP_LOFF_S_EN  (0x0A)    // Single-shot mode / Lead-Off comp enabled
#define ADS1299_CONFIG4_SETUP_LOFF_S_DIS (0x08)    // Single-shot mode / Lead-Off comp disabled
#define ADS1299_LOFF_SETUP_TH_92         (0x20)    // Lead-off comp threshold (positive 92.5%)
#define ADS1299_LOFF_SETUP_TH_90         (0x40)    // Lead-off comp threshold (positive 90%)
#define ADS1299_LOFF_SETUP_TH_87         (0x60)    // Lead-off comp threshold (positive 87%)
#define ADS1299_LOFF_SETUP_TH_85         (0x80)    // Lead-off comp threshold (positive 85%)
#define ADS1299_LOFF_SETUP_TH_80         (0xA0)    // Lead-off comp threshold (positive 80%)
#define ADS1299_LOFF_SETUP_TH_75         (0xC0)    // Lead-off comp threshold (positive 75%)
#define ADS1299_LOFF_SETUP_TH_70         (0xE0)    // Lead-off comp threshold (positive 70%)
#define ADS1299_LOFF_SETUP_MAG_24N       (0x04)    // Lead-off curr magnitude 24 nA
#define ADS1299_LOFF_SETUP_MAG_6U        (0x08)    // Lead-off curr magnitude 6 uA
#define ADS1299_LOFF_SETUP_MAG_24U       (0x0C)    // Lead-off curr magnitude 24 uA
#define ADS1299_LOFF_SETUP_FREQ_7        (0x01)    // AC lead-off detection at 7.8 Hz (fCLK / 2^18)
#define ADS1299_LOFF_SETUP_FREQ_31       (0x02)    // AC lead-off detection at 31.2 Hz (fCLK / 2^16)
#define ADS1299_LOFF_SETUP_FREQ_DR       (0x03)    // AC lead-off detection at fDR / 4
#define ADS1299_CH_N_SET_SETUP_NO        (0x00)    // Normal operation
#define ADS1299_CH_N_SET_SETUP_PD        (0x80)    // Channel power-down
#define ADS1299_CH_N_SET_SETUP_GAIN_24   (0x60)    // PGA gain 24
#define ADS1299_CH_N_SET_SETUP_GAIN_12   (0x50)    // PGA gain 12
#define ADS1299_CH_N_SET_SETUP_GAIN_8    (0x40)    // PGA gain 8
#define ADS1299_CH_N_SET_SETUP_GAIN_6    (0x30)    // PGA gain 6
#define ADS1299_CH_N_SET_SETUP_GAIN_4    (0x20)    // PGA gain 4
#define ADS1299_CH_N_SET_SETUP_GAIN_2    (0x10)    // PGA gain 2
#define ADS1299_CH_N_SET_SETUP_GAIN_1    (0x00)    // PGA gain 1
#define ADS1299_CH_N_SET_SETUP_SRB2_OP   (0x00)    // SRB2 Open
#define ADS1299_CH_N_SET_SETUP_SRB2_CL   (0x08)    // SRB2 Closed
#define ADS1299_CH_N_SET_SETUP_MUX_NEI   (0x00)    // Normal electrode input
#define ADS1299_CH_N_SET_SETUP_MUX_IS    (0x01)    // Input shorted
#define ADS1299_CH_N_SET_SETUP_MUX_MEAS  (0x02)    // Used in conjunction with BIAS_MEAS bit
#define ADS1299_CH_N_SET_SETUP_MUX_MVDD  (0x03)    // MVDD for supply measurement
#define ADS1299_CH_N_SET_SETUP_MUX_TEMP  (0x04)    // Temperature sensor
#define ADS1299_CH_N_SET_SETUP_MUX_TEST  (0x05)    // Test signal
#define ADS1299_CH_N_SET_SETUP_MUX_DRP   (0x06)    // BIAS_DRP
#define ADS1299_CH_N_SET_SETUP_MUX_DRN   (0x07)    // BIAS_DRN
#define ADS1299_LOFF_SENSP_SETUP_IN_1_2  (0x03)    // Lead-off detection on IN1P and IN2P
#define ADS1299_LOFF_SENSN_SETUP_IN_1_2  (0x03)    // Lead-off detection on IN1N and IN2N


#define ADS1299_CONFIG1_SETUP_DEFAULT    (0x96)    // Daisy chain mode / Oscillator clock output disabled / 250 SPS
#define ADS1299_CONFIG2_SETUP_DEFAULT    (0xC0)    // Test signals are driven externally / Sig amp 1x / Sig freq 2^21
#define ADS1299_CONFIG3_SETUP_DEFAULT    (0x60)    // Power down ref buffer / BIAS Open / BIAS Power and sense down
#define ADS1299_CONFIG4_SETUP_DEFAULT    (0x00)    // Continuous conversion mode / LOFF comparators disabled
#define ADS1299_LOFF_SETUP_DEFAULT       (0x00)    // 95%/5% / 6nA current magnitude / DC lead-off detection
#define ADS1299_CH_N_SET_SETUP_DEFAULT   (0x61)    // Normal operation / PGA gain 24 / SRB2 Open / Channel input shorted
#define ADS1299_LOFF_SENSP_SETUP_DEFAULT (0x00)    // Lead-off detection disabled
#define ADS1299_LOFF_SENSN_SETUP_DEFAULT (0x00)    // Lead-off detection disabled

/* Commands */
#define ADS1299_WAKEUP_CMD               (0x02)
#define ADS1299_STANDBY_CMD              (0x04)
#define ADS1299_RESET_CMD                (0x06)
#define ADS1299_START_CMD                (0x08)
#define ADS1299_STOP_CMD                 (0x0A)
#define ADS1299_RDATAC_CMD               (0x10)
#define ADS1299_SDATAC_CMD               (0x11)
#define ADS1299_RDATA_CMD                (0x12)
#define ADS1299_READ_REG_CMD             (0x20)
#define ADS1299_WRITE_REG_CMD            (0x40)

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
    void (*SetPWDN)(uint8_t state);

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


/*          Setting Register Data Functions Section          */
void ADS1299_SetConfig1State(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetConfig2State(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetConfig3State(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetConfig4State(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetLoffState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh1SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh2SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh3SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh4SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh5SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh6SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh7SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetCh8SetState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetLoffSensPState(ads1299_t * ads1299, uint8_t regVal);
void ADS1299_SetLoffSensNState(ads1299_t * ads1299, uint8_t regVal);
/* --------------------------------------------------------- */


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
