// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) Freescale Semiconductor, Inc. 2006.
 *
 * Celliwig - 2020
 */

//#define DEBUG
//#undef CONFIG_LOGLEVEL
//#define CONFIG_LOGLEVEL 8

#include <common.h>
#include <fdt_support.h>
#include <init.h>
#include <ioports.h>
#include <log.h>
#include <mpc83xx.h>
#include <i2c.h>
#include <miiphy.h>
#include <led.h>
#ifdef CONFIG_PCI
#include <asm/mpc8349_pci.h>
#include <pci.h>
#endif
#include <spd_sdram.h>
#include <asm/bitops.h>
#include <asm/mmu.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#include <linux/delay.h>

#include "../../../arch/powerpc/cpu/mpc83xx/hrcw/hrcw.h"
#include "../../../arch/powerpc/cpu/mpc83xx/elbc/elbc.h"

DECLARE_GLOBAL_DATA_PTR;

#ifndef CONFIG_SPD_EEPROM
/*************************************************************************
 *  fixed sdram init -- doesn't use serial presence detect.
 ************************************************************************/
int fixed_sdram(void)
{
	volatile immap_t *im = (immap_t *) CONFIG_SYS_IMMR;
	/* The size of RAM, in bytes */
	u32 ddr_size = CONFIG_SYS_DDR_SIZE << 20;
	u32 ddr_size_log2 = __ilog2(ddr_size);

	im->sysconf.ddrlaw[0].ar =
	    LAWAR_EN | ((ddr_size_log2 - 1) & LAWAR_SIZE);
	im->sysconf.ddrlaw[0].bar = CONFIG_SYS_SDRAM_BASE & 0xfffff000;

#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
	im->ddr.csbnds[0].csbnds =
		((CONFIG_SYS_SDRAM_BASE >> CSBNDS_SA_SHIFT) & CSBNDS_SA) |
		(((CONFIG_SYS_SDRAM_BASE + ddr_size - 1) >>
				CSBNDS_EA_SHIFT) & CSBNDS_EA);
	im->ddr.cs_config[0] = CONFIG_SYS_DDR_CS0_CONFIG;

	/* Only one CS for DDR */
	im->ddr.cs_config[1] = 0;
	im->ddr.cs_config[2] = 0;
	im->ddr.cs_config[3] = 0;

	debug("cs0_bnds = 0x%08x\n", im->ddr.csbnds[0].csbnds);
	debug("cs0_config = 0x%08x\n", im->ddr.cs_config[0]);

	debug("DDR:bar=0x%08x\n", im->sysconf.ddrlaw[0].bar);
	debug("DDR:ar=0x%08x\n", im->sysconf.ddrlaw[0].ar);

	im->ddr.timing_cfg_0 = CONFIG_SYS_DDR_TIMING_0;
	im->ddr.timing_cfg_1 = CONFIG_SYS_DDR_TIMING_1;
	im->ddr.timing_cfg_2 = CONFIG_SYS_DDR_TIMING_2;
	im->ddr.sdram_cfg = CONFIG_SYS_DDR_SDRAM_CFG;
	im->ddr.sdram_cfg2 = CONFIG_SYS_DDR_SDRAM_CFG2;
	im->ddr.sdram_mode = CONFIG_SYS_DDR_SDRAM_MODE;
//	im->ddr.sdram_mode2 = CONFIG_SYS_DDR_SDRAM_MODE2;
	im->ddr.sdram_interval = CONFIG_SYS_DDR_SDRAM_INTERVAL;
	im->ddr.sdram_clk_cntl = CONFIG_SYS_DDR_SDRAM_CLK_CNTL;

	udelay(200);

	im->ddr.sdram_cfg |= SDRAM_CFG_MEM_EN;

	debug("DDR:timing_cfg_0=0x%08x\n", im->ddr.timing_cfg_0);
	debug("DDR:timing_cfg_1=0x%08x\n", im->ddr.timing_cfg_1);
	debug("DDR:timing_cfg_2=0x%08x\n", im->ddr.timing_cfg_2);
	debug("DDR:sdram_mode=0x%08x\n", im->ddr.sdram_mode);
	debug("DDR:sdram_mode2=0x%08x\n", im->ddr.sdram_mode2);
	debug("DDR:sdram_interval=0x%08x\n", im->ddr.sdram_interval);
	debug("DDR:sdram_cfg=0x%08x\n", im->ddr.sdram_cfg);
	debug("DDR:sdram_cfg2=0x%08x\n", im->ddr.sdram_cfg2);

	return CONFIG_SYS_DDR_SIZE;
}
#endif

#ifdef CONFIG_PCI
/*
 * Initialize PCI Devices, report devices found
 */
#ifndef CONFIG_PCI_PNP
static struct pci_config_table pci_meru_ap320_config_table[] = {
	{
	 PCI_ANY_ID,
	 PCI_ANY_ID,
	 PCI_ANY_ID,
	 PCI_ANY_ID,
	 0x0f,
	 PCI_ANY_ID,
	 pci_cfgfunc_config_device,
	 {
	  PCI_ENET0_IOADDR,
	  PCI_ENET0_MEMADDR,
	  PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER}
	 },
	{}
}
#endif

volatile static struct pci_controller hose[] = {
	{
#ifndef CONFIG_PCI_PNP
	      config_table:pci_meru_ap320_config_table,
#endif
	 },
	{
#ifndef CONFIG_PCI_PNP
	      config_table:pci_meru_ap320_config_table,
#endif
	 }
};
#endif				/* CONFIG_PCI */

int dram_init(void)
{
	volatile immap_t *im = (immap_t *) CONFIG_SYS_IMMR;
	u32 msize = 0;
//#ifdef CONFIG_DDR_ECC
//	volatile ddr83xx_t *ddr = &im->ddr;
//#endif

	if ((im->sysconf.immrbar & IMMRBAR_BASE_ADDR) != (u32) im)
		return -ENXIO;

	/* DDR SDRAM - Main SODIMM */
	im->sysconf.ddrlaw[0].bar = CONFIG_SYS_SDRAM_BASE & LAWBAR_BAR;
	msize = fixed_sdram();

//#ifdef CONFIG_DDR_ECC
//	if (ddr->sdram_cfg & SDRAM_CFG_ECC_EN)
//		/* Unlike every other board, on the 83xx spd_sdram() returns
//		   megabytes instead of just bytes.  That's why we need to
//		   multiple by 1MB when calling ddr_enable_ecc(). */
//		ddr_enable_ecc(msize * 1048576);
//#endif

	/* return total bus RAM size(bytes) */
	gd->ram_size = msize * 1024 * 1024;

	return 0;
}

int checkboard(void)
{
	puts("Board: Meru Networks AP320\n");
	return 0;
}

/*
 * Implement a work-around for a hardware problem with compact
 * flash.
 *
 * Program the UPM if compact flash is enabled.
 */
int misc_init_f(void)
{
	unsigned int *gpio_reg = 0xE0000c08;
	*gpio_reg = 0x3d800000;			// Status LED to green

	return 0;
}

/*
 * Miscellaneous late-boot configurations
 *
 * Make sure the EEPROM has the HRCW correctly programmed.
 * Make sure the RTC is correctly programmed.
 *
 * The MPC8349E-mITX can be configured to load the HRCW from
 * EEPROM instead of flash.  This is controlled via jumpers
 * LGPL0, 1, and 3.  Normally, these jumpers are set to 000 (all
 * jumpered), but if they're set to 001 or 010, then the HRCW is
 * read from the "I2C EEPROM".
 *
 * This function makes sure that the I2C EEPROM is programmed
 * correctly.
 *
 * If a VSC7385 microcode image is present, then upload it.
 */
int misc_init_r(void)
{
	int rc = 0;
	bd_t *bd = gd->bd;

	// Should have been setup in board_f but fails there
	checkcpu();				// Load DM CPU
	// Part of setup_board_part2
	bd->bi_intfreq = gd->cpu_clk;		/* Internal Freq, in Hz */
	bd->bi_busfreq = gd->bus_clk;		/* Bus Freq,      in Hz */

#ifdef CONFIG_LED
	led_default_state();			// Status LED to blue
#endif /* CONFIG_LED */

#if defined(CONFIG_SYS_I2C)
	unsigned int orig_bus = i2c_get_bus_num();
	u8 i2c_data;

//	printf("Board revision: ");
//	i2c_set_bus_num(1);
//	if (i2c_read(CONFIG_SYS_I2C_8574A_ADDR2, 0, 0, &i2c_data, sizeof(i2c_data)) == 0)
//		printf("%u.%u (PCF8475A)\n", (i2c_data & 0x02) >> 1, i2c_data & 0x01);
//	else if (i2c_read(CONFIG_SYS_I2C_8574_ADDR2, 0, 0, &i2c_data, sizeof(i2c_data)) == 0)
//		printf("%u.%u (PCF8475)\n",  (i2c_data & 0x02) >> 1, i2c_data & 0x01);
//	else {
//		printf("Unknown\n");
//		rc = 1;
//	}

	i2c_set_bus_num(orig_bus);
#endif

	return rc;
}

#if defined(CONFIG_OF_BOARD_SETUP)
int ft_board_setup(void *blob, bd_t *bd)
{
	ft_cpu_setup(blob, bd);
#ifdef CONFIG_PCI
	ft_pci_setup(blob, bd);
#endif

	return 0;
}
#endif
