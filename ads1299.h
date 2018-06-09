#ifndef DRV_ADS1299_ADS1299_H_
#define DRV_ADS1299_ADS1299_H_

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

#endif /* DRV_ADS1299_ADS1299_H_ */
