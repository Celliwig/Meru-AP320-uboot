/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Based on MPC8349E-mITX and MPC8349E-mITX-GP board configuration file
 * Copyright (C) Freescale Semiconductor, Inc. 2006.
 *
 * Celliwig - 2020.
 */

/*
 Meru Networks AP320

 Memory map:

 0x0000_0000-0x07FF_FFFF DDR SDRAM (256 MB)
 0x8000_0000-0x9FFF_FFFF PCI1 memory space (512 MB)
 0xE000_0000-0xEFFF_FFFF IMMR (1 MB)
 0xE200_0000-0xE2FF_FFFF PCI1 I/O space (16 MB)
 0xFF00_0000-0xFFFF_FFFF First 16MB bank of Flash memory

*/

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MISC_INIT_F

/*
 * On-board devices
 */

#include <linux/stringify.h>
#define CONFIG_SYS_I2C

/*
 * Device configurations
 */
/* I2C */
#ifdef CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_FSL
#define CONFIG_SYS_FSL_I2C_SPEED	400000
#define CONFIG_SYS_FSL_I2C_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C_OFFSET	0x3000
#define CONFIG_SYS_FSL_I2C2_SPEED	400000
#define CONFIG_SYS_FSL_I2C2_SLAVE	0x7F
#define CONFIG_SYS_FSL_I2C2_OFFSET	0x3100

#endif

/*
 * DDR Setup
 *
 * Copied from existing uboot setup.
 */
#define CONFIG_SYS_SDRAM_BASE		0x00000000 	/* DDR is system memory*/
#define CONFIG_SYS_83XX_DDR_USES_CS0

#define CONFIG_SYS_DDR_SDRAM_CLK_CNTL	(DDR_SDRAM_CLK_CNTL_SS_EN \
					| DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05)

#define CONFIG_VERY_BIG_RAM
#define CONFIG_MAX_MEM_MAPPED		((phys_size_t)128 << 20)

/* No SPD? Then manually set up DDR parameters */
#define CONFIG_SYS_DDR_SIZE		128		/* Mb */
#define CONFIG_SYS_DDR_CS0_CONFIG	(CSCONFIG_EN \
						| CSCONFIG_AP \
						| CSCONFIG_ODT_WR_ONLY_CURRENT \
						| CSCONFIG_ROW_BIT_13 \
						| CSCONFIG_COL_BIT_9)
#define CONFIG_SYS_DDR_TIMING_0		0x00220902
#define CONFIG_SYS_DDR_TIMING_1		0x6f65c653
#define CONFIG_SYS_DDR_TIMING_2		0x0f9028ca
#define CONFIG_SYS_DDR_SDRAM_CFG	(SDRAM_CFG_SREN | SDRAM_CFG_SDRAM_TYPE_DDR2)
#define CONFIG_SYS_DDR_SDRAM_CFG2	0x00401000
#define CONFIG_SYS_DDR_SDRAM_MODE	0x24400232
//#define CONFIG_SYS_DDR_SDRAM_MODE2	0x40006000
#define CONFIG_SYS_DDR_SDRAM_INTERVAL	0x08200100

#define CONFIG_SYS_DDRCDR		DDRCDR_EN | \
					DDRCDR_PZ_NOMZ | \
					DDRCDR_NZ_NOMZ | \
					DDRCDR_M_ODR

/*
 *Flash on the Local Bus
 */
#define CONFIG_SYS_FLASH_BASE		0xFF000000	/* start of FLASH   */
#define CONFIG_SYS_FLASH_EMPTY_INFO
/* 127 64KB sectors + 8 8KB sectors per device */
#define CONFIG_SYS_MAX_FLASH_SECT	135
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000		/* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500		/* Flash Write Timeout (ms) */
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_8BIT

#define CONFIG_SYS_MAX_FLASH_BANKS	1		/* number of banks */
#define CONFIG_SYS_FLASH_BANKS_LIST	{ CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_FLASH_SIZE		16		/* FLASH size in MB */

/*
 * U-Boot memory configuration
 */
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_TEXT_BASE	/* start of monitor */

#if (CONFIG_SYS_MONITOR_BASE < CONFIG_SYS_FLASH_BASE)
#define CONFIG_SYS_RAMBOOT
#else
#undef	CONFIG_SYS_RAMBOOT
#endif

#define CONFIG_SYS_INIT_RAM_LOCK
#define CONFIG_SYS_INIT_RAM_ADDR	0xE4010000	/* Initial RAM addr (From previous version) */
#define CONFIG_SYS_INIT_RAM_SIZE	0x4000		/* Size of used area in RAM*/
//#define CONFIG_SYS_MALLOC_F_LEN		0x3000		/* 8k for simple malloc */

#define CONFIG_SYS_GBL_DATA_OFFSET	\
			(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_OFFSET	CONFIG_SYS_GBL_DATA_OFFSET

/* CONFIG_SYS_MONITOR_LEN must be a multiple of CONFIG_ENV_SECT_SIZE */
#define CONFIG_SYS_MONITOR_LEN		(768 * 1024)	/* Reserve 512 kB for Mon */
#define CONFIG_SYS_MALLOC_LEN		(256 * 1024)	/* Reserved for malloc */

/*
 * Serial Port
 */
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
//#define CONFIG_SYS_NS16550_CLK		get_bus_freq(0)

#define CONFIG_SYS_BAUDRATE_TABLE  \
		{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 115200}

#define CONSOLE				ttyS0

#define CONFIG_SYS_NS16550_COM1		(CONFIG_SYS_IMMR + 0x4500)
#define CONFIG_SYS_NS16550_COM2		(CONFIG_SYS_IMMR + 0x4600)

/*
 * PCI
 */
#ifdef CONFIG_PCI
#define CONFIG_PCI_INDIRECT_BRIDGE

//#define CONFIG_MPC83XX_PCI2

/*
 * General PCI
 * Addresses are mapped 1-1.
 */
#define CONFIG_SYS_PCI1_MEM_BASE	0x80000000
#define CONFIG_SYS_PCI1_MEM_PHYS	CONFIG_SYS_PCI1_MEM_BASE
#define CONFIG_SYS_PCI1_MEM_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCI1_MMIO_BASE	\
			(CONFIG_SYS_PCI1_MEM_BASE + CONFIG_SYS_PCI1_MEM_SIZE)
#define CONFIG_SYS_PCI1_MMIO_PHYS	CONFIG_SYS_PCI1_MMIO_BASE
#define CONFIG_SYS_PCI1_MMIO_SIZE	0x10000000	/* 256M */
#define CONFIG_SYS_PCI1_IO_BASE		0x00000000
#define CONFIG_SYS_PCI1_IO_PHYS		0xE2000000
#define CONFIG_SYS_PCI1_IO_SIZE		0x01000000	/* 16M */

//#ifdef CONFIG_MPC83XX_PCI2
//#define CONFIG_SYS_PCI2_MEM_BASE	\
//			(CONFIG_SYS_PCI1_MMIO_BASE + CONFIG_SYS_PCI1_MMIO_SIZE)
//#define CONFIG_SYS_PCI2_MEM_PHYS	CONFIG_SYS_PCI2_MEM_BASE
//#define CONFIG_SYS_PCI2_MEM_SIZE	0x10000000	/* 256M */
//#define CONFIG_SYS_PCI2_MMIO_BASE	\
//			(CONFIG_SYS_PCI2_MEM_BASE + CONFIG_SYS_PCI2_MEM_SIZE)
//#define CONFIG_SYS_PCI2_MMIO_PHYS	CONFIG_SYS_PCI2_MMIO_BASE
//#define CONFIG_SYS_PCI2_MMIO_SIZE	0x10000000	/* 256M */
//#define CONFIG_SYS_PCI2_IO_BASE		0x00000000
//#define CONFIG_SYS_PCI2_IO_PHYS		\
//			(CONFIG_SYS_PCI1_IO_PHYS + CONFIG_SYS_PCI1_IO_SIZE)
//#define CONFIG_SYS_PCI2_IO_SIZE		0x01000000	/* 16M */
//#endif

#ifndef CONFIG_PCI_PNP
    #define PCI_ENET0_IOADDR		0x00000000
    #define PCI_ENET0_MEMADDR		CONFIG_SYS_PCI2_MEM_BASE
    #define PCI_IDSEL_NUMBER		0x0f		/* IDSEL = AD15 */
#endif

#define CONFIG_PCI_SCAN_SHOW				/* show pci devices on startup */

#endif

/* TSEC */
#ifdef CONFIG_TSEC_ENET
#define CONFIG_TSEC1

#ifdef CONFIG_TSEC1
#define CONFIG_HAS_ETH0
#define CONFIG_TSEC1_NAME		"TSEC0"
#define CONFIG_SYS_TSEC1_OFFSET		0x24000
#define TSEC1_PHY_ADDR			0x1c		/* Vitesse 8601 uses address 0x1c */
#define TSEC1_PHYIDX			0
#define TSEC1_FLAGS			TSEC_GIGABIT
#endif

#ifdef CONFIG_TSEC2
#define CONFIG_HAS_ETH1
#define CONFIG_TSEC2_NAME		"TSEC1"
#define CONFIG_SYS_TSEC2_OFFSET		0x25000
#define TSEC2_PHY_ADDR			4
#define TSEC2_PHYIDX			0
#define TSEC2_FLAGS			TSEC_GIGABIT
#endif

#define CONFIG_ETHPRIME			"Freescale TSEC"

#endif

/*
 * Environment
 */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_LOADS_ECHO				/* echo on for serial download */
#define CONFIG_SYS_LOADS_BAUD_CHANGE			/* allow baudrate change */

///*
// * BOOTP options
// */
//#define CONFIG_BOOTP_BOOTFILESIZE

/* Watchdog */
//#define CONFIG_WATCHDOG					/* watchdog enabled */
#define CONFIG_SYS_WATCHDOG_VALUE	0xFFFF
#define CONFIG_SYS_WATCHDOG_FREQ	(CONFIG_SYS_HZ / 2)

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LOAD_ADDR		0x2000000	/* default load address */
#define CONFIG_LOADADDR			0x2000000	/* default location for tftp and bootm */

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 256 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
/* Initial Memory map for Linux*/
#define CONFIG_SYS_BOOTMAPSZ		(256 << 20)
#define CONFIG_SYS_BOOTM_LEN		(64 << 20)	/* Increase max gunzip size */

/*
 * System performance
 */
#define CONFIG_SYS_SCCR_TSEC1CM		3		/* TSEC1 clock mode (0-3) */
#define CONFIG_SYS_SCCR_TSEC2CM		3		/* TSEC2 & I2C0 clock mode (0-3) */
//#define CONFIG_SYS_SCCR_USBMPHCM 	3		/* USB MPH controller's clock */
//#define CONFIG_SYS_SCCR_USBDRCM	0		/* USB DR controller's clock */

/*
 * System IO Config
 */
/* Needed for gigabit to work on TSEC 1 */
#define CONFIG_SYS_SICRL		SICRL_LDP_A
#define CONFIG_SYS_SICRH		SICRH_TSEC1_A | \
					SICRH_TSEC1_B | \
					SICRH_TSEC1_C | \
					SICRH_TSEC1_D | \
					SICRH_TSEC1_E | \
					SICRH_TSEC1_F | \
					SICRH_TSEC2_A | \
					SICRH_TSEC2_B | \
					SICRH_TSEC2_C | \
					SICRH_TSEC2_D | \
					SICRH_TSEC2_E | \
					SICRH_TSEC2_F | \
					SICRH_TSEC2_G | \
					SICRH_TSEC2_H | \
					SICRH_TSOBI1 | \
					SICRH_TSOBI2

/* USB DR as device + USB MPH as host */
//#define CONFIG_SYS_SICRL	(SICRL_LDP_A | SICRL_USB1)
//
//#if defined(CONFIG_CMD_KGDB)
//#define CONFIG_KGDB_BAUDRATE	230400	/* speed of kgdb serial port */
//#endif

/*
 * Environment Configuration
 */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_NETDEV			"eth0"

/* Default path and filenames */
#define CONFIG_ROOTPATH			"/nfsroot/rootfs"
#define CONFIG_BOOTFILE			"uImage"
/* U-Boot image on TFTP server */
#define CONFIG_UBOOTPATH		"u-boot.bin"
#define CONFIG_FDTFILE			"meru-ap320.dtb"


#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=" __stringify(CONSOLE) "\0"				\
	"netdev=" CONFIG_NETDEV "\0"					\
	"mtdids=nor0=ff000000.flash\0"					\
	"mtdparts=mtdparts=ff000000.flash:128k(hwrc)ro,128k(DTB),4096k(kernel),11008k(rootfs),512k(U-boot)ro,256k(env0)ro,256k(env1)ro\0"

//#define CONFIG_NFSBOOTCOMMAND						\
//	"setenv bootargs root=/dev/nfs rw nfsroot=$serverip:$rootpath"	\
//	" ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname:$netdev:off "\
//	" console=$console,$baudrate $othbootargs; "			\
//	"tftp $loadaddr $bootfile;"					\
//	"tftp $fdtaddr $fdtfile;"					\
//	"bootm $loadaddr - $fdtaddr"
//
//#define CONFIG_RAMBOOTCOMMAND						\
//	"setenv bootargs root=/dev/ram rw"				\
//	" console=$console,$baudrate $othbootargs; "			\
//	"tftp $ramdiskaddr $ramdiskfile;"				\
//	"tftp $loadaddr $bootfile;"					\
//	"tftp $fdtaddr $fdtfile;"					\
//	"bootm $loadaddr $ramdiskaddr $fdtaddr"

#endif
