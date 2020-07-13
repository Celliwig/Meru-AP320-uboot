// SPDX-License-Identifier: GPL-2.0+

#include <common.h>
#include <exports.h>

//MIIMCFG: 3
//MIIMCOM: 1
//MIIMADD: 1c1c
//MIIMCON: 1240
//MIIMSTAT: a036
//MIIMIND: 0

unsigned int volatile read_mii_phy(unsigned int mii_phy_reg);
void select_mii_phy_regs(unsigned int mii_phy_reg_bank);

int read_mpc8347_mii_phy(int argc, char *const argv[])
{
//	int i = 0;
//	/* Print the ABI version */
//	app_startup(argv);
//	printf ("Example expects ABI version %d\n", XF_VERSION);
//	printf ("Actual U-Boot ABI version %d\n", (int)get_version());
//
//	printf ("Hello World\n");
//
//	printf ("argc = %d\n", argc);
//
//	for (i=0; i<=argc; ++i) {
//		printf ("argv[%d] = \"%s\"\n", i, argv[i] ? argv[i] : "<NULL>");
//	}
//
//	printf ("Hit any key to exit ... ");
//	while (!tstc())
//		;
//	/* consume input */
//	(void) getc();

	unsigned int rslt;

	printf("\nMii PHY\n");
	printf("\tStandard Registers\n");
	rslt = read_mii_phy(0x00);
	printf("\tPHY Mode Control[0x00]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x01);
	printf("\tPHY Mode Status[0x01]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x02);
	printf("\tPHY OUI[0x02]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x03);
	printf("\tPHY OUI[0x03]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x04);
	printf("\tPHY Auto-Neg Advert[0x04]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x05);
	printf("\tPHY Auto-Neg Link-Partner[0x05]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x06);
	printf("\tPHY Auto-Neg Expansion[0x06]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x07);
	printf("\tPHY Auto-Neg Next Page[0x07]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x08);
	printf("\tPHY Auto-Neg Next Page LP[0x08]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x09);
	printf("\tPHY 1000Base-T Control[0x09]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x0a);
	printf("\tPHY 1000Base-T Status[0x0a]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x0f);
	printf("\tPHY 1000Base-T Status Ext[0x0b]: 0x%x\n", rslt);

	// Select main registers
	select_mii_phy_regs(0);

	printf("\n\tMain Registers\n");
	rslt = read_mii_phy(0x10);
	printf("\tPHY 100Base-T Status Ext[0x10]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x11);
	printf("\tPHY 100Base-T Status Ext2[0x11]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x12);
	printf("\tPHY Bypass Control[0x12]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x13);
	printf("\tPHY Receive Error Count[0x13]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x14);
	printf("\tPHY False Carrier Sense Counter[0x14]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x15);
	printf("\tPHY Disconnect Counter[0x15]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x16);
	printf("\tPHY Extended Control and Status[0x16]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x17);
	printf("\tPHY Extended Phy Control1[0x17]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x18);
	printf("\tPHY Extended Phy Control2[0x18]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x19);
	printf("\tPHY Interrupt Mask[0x19]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1a);
	printf("\tPHY Interrupt Status[0x1a]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1b);
	printf("\tPHY LED Control[0x1b]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1c);
	printf("\tPHY Auxiliary Control and Status[0x1c]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1d);
	printf("\tPHY Delay Skew Status[0x1d]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1f);
	printf("\tPHY Extended Page Access[0x1f]: 0x%x\n", rslt);

	// Select extended registers
	select_mii_phy_regs(1);

	printf("\n\tExtended Registers\n");
	rslt = read_mii_phy(0x10);
	printf("\tPHY Enhanced LED Method Select[0x10]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x11);
	printf("\tPHY Enhanced LED Behaviour[0x11]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x12);
	printf("\tPHY CRC Good Counter[0x12]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x13);
	printf("\tPHY MAC Resistor Calibration Control[0x13]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x14);
	printf("\tPHY Extended PHY Control3[0x14]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x15);
	printf("\tPHY EEPROM Interface Status and Control[0x15]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x16);
	printf("\tPHY EEPROM Data Read/Write[0x16]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x17);
	printf("\tPHY Extended PHY Control4[0x17]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1b);
	printf("\tPHY Extended PHY Control7[0x1b]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1c);
	printf("\tPHY RGMII Skew Control[0x1c]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1d);
	printf("\tPHY Ethernet Packer Generator1[0x1d]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1e);
	printf("\tPHY Ethernet Packer Generator2[0x1e]: 0x%x\n", rslt);
	rslt = read_mii_phy(0x1f);
	printf("\tPHY Extended Page Access[0x1f]: 0x%x\n", rslt);

	// Select main registers
	select_mii_phy_regs(0);

	printf ("\n\n");
	return (0);
}

unsigned int volatile read_mii_phy(unsigned int mii_phy_reg) {
	unsigned int volatile tmp_mii;
	uint32_t volatile *miimcom_reg = 0xE0024524;
	uint32_t volatile *miimadd_reg = 0xE0024528;
	//uint32_t volatile *miimcon_reg = 0xE002452c;
	uint32_t volatile *miistat_reg = 0xE0024530;
	uint32_t volatile *miimind_reg = 0xE0024534;

	unsigned int debug = 0, loop;

	if (debug) printf("Debug: Checking MII status.\n");
	loop = 1;
	while (loop > 0) {
		tmp_mii = *miimind_reg;
		//if (debug) printf("Debug: MII status: 0x%x\n", tmp_mii);
		if ((tmp_mii & 1) == 0) loop = 0;
	}

	tmp_mii = 0x00001c00 | (mii_phy_reg & 0x1f);
	if (debug) printf("Debug: Loading PHY/REG address: 0x%x\n", tmp_mii);
	*miimadd_reg = tmp_mii;			// Set PHY address/Register address

	tmp_mii = *miimcom_reg;			// Read Management command register
	if (debug) printf("Debug: Management command register: 0x%x\n", tmp_mii);
	if (tmp_mii & 1) {
		if (debug) printf("Debug: Clearing management command register bit.\n");
		*miimcom_reg = 0xfffffffe & tmp_mii;
	}
	tmp_mii = tmp_mii | 1;			// Read command
	if (debug) printf("Debug: Sending read command.\n");
	*miimcom_reg = tmp_mii;			// Issue command

	if (debug) printf("Debug: Checking MII status.\n");
	loop = 1;
	while (loop > 0) {
		tmp_mii = *miimind_reg;
		//if (debug) printf("Debug: MII status: 0x%x\n", tmp_mii);
		if ((tmp_mii & 5) == 0) loop = 0;
	}

	mdelay(1);
	tmp_mii = *miistat_reg;
	if (debug) printf("Debug: MII PHY read: 0x%x\n", tmp_mii);
	return tmp_mii;
}

void select_mii_phy_regs(unsigned int mii_phy_reg_bank) {
	unsigned int volatile tmp_mii;
	//uint32_t volatile *miimcom_reg = 0xE0024524;
	uint32_t volatile *miimadd_reg = 0xE0024528;
	uint32_t volatile *miimcon_reg = 0xE002452c;
	//uint32_t volatile *miistat_reg = 0xE0024530;
	uint32_t volatile *miimind_reg = 0xE0024534;

	unsigned int debug = 0, loop;

	if (debug) printf("Debug: Checking MII status.\n");
	loop = 1;
	while (loop > 0) {
		tmp_mii = *miimind_reg;
		//if (debug) printf("Debug: MII status: 0x%x\n", tmp_mii);
		if ((tmp_mii & 1) == 0) loop = 0;
	}

	tmp_mii = 0x00001c00 | 0x1f;
	if (debug) printf("Debug: Loading PHY/REG address: 0x%x\n", tmp_mii);
	*miimadd_reg = tmp_mii;			// Set PHY address/Register address

	tmp_mii = mii_phy_reg_bank & 0x1;
	*miimcon_reg = tmp_mii;			// Select register bank

	if (debug) printf("Debug: Checking MII status.\n");
	loop = 1;
	while (loop > 0) {
		tmp_mii = *miimind_reg;
		//if (debug) printf("Debug: MII status: 0x%x\n", tmp_mii);
		if ((tmp_mii & 5) == 0) loop = 0;
	}

	mdelay(1);
}
