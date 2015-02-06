/* linux/arch/arm/mach-msm/board-spade.h
 *
 * Copyright (C) 2010-2011 HTC Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ARCH_ARM_MACH_MSM_BOARD_VIGOR_H
#define __ARCH_ARM_MACH_MSM_BOARD_VIGOR_H

#include <mach/board.h>
#include <mach/msm_memtypes.h>
#include <mach/rpm-regulator.h>
#include <linux/regulator/pmic8901-regulator.h>
#include <mach/board-msm8660.h>

#define VIGOR_PROJECT_NAME	"vigor"

#define MSM_RAM_CONSOLE_BASE	MSM_HTC_RAM_CONSOLE_PHYS
#define MSM_RAM_CONSOLE_SIZE	MSM_HTC_RAM_CONSOLE_SIZE

/*** Memory map ***/
#define MSM_SMI_BASE         0x38000000
#define MSM_SMI_SIZE         0x4000000

#ifdef CONFIG_FB_MSM_TRIPLE_BUFFER
#define MSM_FB_PRIM_BUF_SIZE (960 * 544 * 4 * 3) /* 4 bpp x 3 pages */
#else
#define MSM_FB_PRIM_BUF_SIZE (960 * 544 * 4 * 2) /* 4 bpp x 2 pages */
#endif


#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
#define MSM_FB_EXT_BUF_SIZE (1920 * 1088 * 2 * 1) /* 2 bpp x 1 page */
#elif defined(CONFIG_FB_MSM_TVOUT)
#define MSM_FB_EXT_BUF_SIZE (720 * 576 * 2 * 2) /* 2 bpp x 2 pages */
#else
#define MSM_FB_EXT_BUF_SIZE 0
#endif

/* Note: must be multiple of 4096 */
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + MSM_FB_EXT_BUF_SIZE, 4096)

#ifdef CONFIG_FB_MSM_OVERLAY0_WRITEBACK
#define MSM_FB_OVERLAY0_WRITEBACK_SIZE roundup((960 * 544 * 3 * 2), 4096)
#else
#define MSM_FB_OVERLAY0_WRITEBACK_SIZE (0)
#endif  /* CONFIG_FB_MSM_OVERLAY0_WRITEBACK */

#ifdef CONFIG_FB_MSM_OVERLAY1_WRITEBACK
#define MSM_FB_OVERLAY1_WRITEBACK_SIZE roundup((1920 * 1088 * 3 * 2), 4096)
#else
#define MSM_FB_OVERLAY1_WRITEBACK_SIZE (0)
#endif  /* CONFIG_FB_MSM_OVERLAY1_WRITEBACK */

#define PHY_BASE_ADDR1       0x48000000
#define SIZE_ADDR1           0x28000000

#define MSM_ION_MM_FW_SIZE   0x200000
#define MSM_ION_MM_SIZE      0x3D00000
#define MSM_ION_MFC_SIZE     0x100000
#define MSM_ION_SF_SIZE      0x2A00000
#define MSM_ION_WB_SIZE      0x500000
#define MSM_ION_AUDIO_SIZE   0x4CF000

#define MSM_ION_HEAP_NUM     7

#define MSM_ION_MM_FW_BASE   0x38000000
#define MSM_ION_MM_BASE      0x38200000
#define MSM_ION_MFC_BASE     0x3BF00000
#define MSM_ION_SF_BASE      0x40400000
#define MSM_ION_WB_BASE      0x45C00000
/*** END Memory map ***/

/* GPIO definition */

/* Direct Keys */
#define VIGOR_GPIO_KEY_POWER          (125)

/* Battery */
#define VIGOR_GPIO_MBAT_IN            (61)
#define VIGOR_GPIO_CHG_INT		(126)

/* Wifi */
#define VIGOR_GPIO_WIFI_IRQ              (46)
#define VIGOR_GPIO_WIFI_SHUTDOWN_N       (96)
/* Sensors */
#define VIGOR_SENSOR_I2C_SDA		(72)
#define VIGOR_SENSOR_I2C_SCL		(73)
#define VIGOR_GYRO_INT               (127)
#define VIGOR_ECOMPASS_INT           (128)
#define VIGOR_GSENSOR_INT           (129)

/* Microp */

/* TP */
#define VIGOR_TP_I2C_SDA           (51)
#define VIGOR_TP_I2C_SCL           (52)
#define VIGOR_TP_ATT_N             (65)
#define VIGOR_TP_ATT_N_XB       (50)

/* LCD */
#define GPIO_LCD_TE	28
#define GPIO_LCM_RST_N			(66)
#define GPIO_LCM_ID			(50)

/* Audio */
#define VIGOR_AUD_CODEC_RST        (67)

/* BT */
#define VIGOR_GPIO_BT_HOST_WAKE      (45)
#define VIGOR_GPIO_BT_UART1_TX       (53)
#define VIGOR_GPIO_BT_UART1_RX       (54)
#define VIGOR_GPIO_BT_UART1_CTS      (55)
#define VIGOR_GPIO_BT_UART1_RTS      (56)
#define VIGOR_GPIO_BT_SHUTDOWN_N     (100)
#define VIGOR_GPIO_BT_CHIP_WAKE      (130)
#define VIGOR_GPIO_BT_RESET_N        (142)

/* USB */
#define VIGOR_GPIO_USB_ID        (63)
#define VIGOR_GPIO_MHL_RESET        (70)
#define VIGOR_GPIO_MHL_INT        (71)
#define VIGOR_GPIO_MHL_USB_SWITCH        (99)

/* Camera */
#define VIGOR_CAM_CAM1_ID           (10)
#define VIGOR_CAM_I2C_SDA           (47)
#define VIGOR_CAM_I2C_SCL           (48)
#define VIGOR_CAM_MCLK     	 (32)
#define VIGOR_CAM_VCM_PD      (58)
#define VIGOR_CAM1_RSTz       (137)
#define VIGOR_CAM2_RSTz       (138)
#define VIGOR_CAM2_PWDN       (140)
#define VIGOR_MCLK_SWITCH     (141)


/* General */
#define VIGOR_GENERAL_I2C_SDA		(59)
#define VIGOR_GENERAL_I2C_SCL		(60)

/* Flashlight */
#define VIGOR_FLASH_EN             (29)
#define VIGOR_TORCH_EN             (30)

/* Accessory */
#define VIGOR_GPIO_AUD_HP_DET        (31)

/* SPI */
#define VIGOR_SPI_DO                 (33)
#define VIGOR_SPI_DI                 (34)
#define VIGOR_SPI_CS                 (35)
#define VIGOR_SPI_CLK                (36)

/* PMIC */

/* PMIC GPIO definition */
#define PMGPIO(x) (x-1)
#define VIGOR_VOL_UP             PMGPIO(16)
#define VIGOR_VOL_DN             PMGPIO(17)
#define VIGOR_AUD_HP_EN          PMGPIO(18)
#define VIGOR_HAP_ENABLE         PMGPIO(19)
#define VIGOR_AUD_QTR_RESET      PMGPIO(21)
#define VIGOR_TP_RST             PMGPIO(23)
#define VIGOR_GREEN_LED          PMGPIO(24)
#define VIGOR_AMBER_LED          PMGPIO(25)
#define VIGOR_AUD_MIC_SEL        PMGPIO(26)
#define VIGOR_CHG_STAT	   PMGPIO(33)
#define VIGOR_SDC3_DET           PMGPIO(34)
#define VIGOR_PLS_INT            PMGPIO(35)
#define VIGOR_AUD_REMO_PRES      PMGPIO(37)
#define VIGOR_WIFI_BT_SLEEP_CLK  PMGPIO(38)

extern struct regulator_init_data msm_saw_regulator_pdata_s0;
extern struct regulator_init_data msm_saw_regulator_pdata_s1;
extern struct rpm_regulator_platform_data vigor_rpm_regulator_early_pdata __devinitdata;
extern struct rpm_regulator_platform_data vigor_rpm_regulator_pdata __devinitdata;
extern struct platform_device msm8x60_8901_mpp_vreg __devinitdata;
extern struct pm8901_vreg_pdata pm8901_regulator_pdata[];
extern int pm8901_regulator_pdata_len;
extern struct platform_device msm_adc_device;

void __init vigor_init_mmc(void);
int __init vigor_init_wifi_mmc(void);
void __init vigor_audio_init(void);
int __init vigor_init_keypad(void);
void __init vigor_init_fb(void);
void __init vigor_init_pmic(void);
int __init vigor_wifi_init(void);
void __init vigor_gpio_mpp_init(void);
void vigor_init_gpiomux(void);
void __init msm8x60_allocate_fb_region(void);
void __init vigor_pm8901_gpio_mpp_init(void);
void msm8x60_mdp_writeback(struct memtype_reserve *reserve_table);
#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
int hdmi_enable_5v(int on);
#endif
#define _GET_REGULATOR(var, name) do {					\
	if (var == NULL) {						\
		var = regulator_get(NULL, name);			\
		if (IS_ERR(var)) {					\
			pr_err("'%s' regulator not found, rc=%ld\n",	\
				name, PTR_ERR(var));			\
			var = NULL;					\
		}							\
	}								\
} while (0)

#endif /* __ARCH_ARM_MACH_MSM_BOARD_VIGOR_H */
