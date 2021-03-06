// SPDX-License-Identifier: GPL-2.0+

#include <common.h>
#include <exports.h>

int read_mpc8347_immr(int argc, char *const argv[])
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
////	for (i=0; i<=argc; ++i) {
////		printf ("wibble\n");
////		printf ("argv[%d] = \"%s\"\n", i, argv[i] ? argv[i] : "<NULL>");
////	}
//
//	printf ("Hit any key to exit ... ");
//	while (!tstc())
//		;
//	/* consume input */
//	(void) getc();

	uint32_t tmp_reg;
	unsigned int *tmp_ptr;

	printf("\nRegisters\n");
	asm("mfmsr %0" : "=r" (tmp_reg));
	printf("\tMSR: %x\n", tmp_reg);
	asm("mfspr %0, 0x3f0" : "=r" (tmp_reg));
	printf("\tHID0: %x\n", tmp_reg);
	asm("mfspr %0, 0x3f3" : "=r" (tmp_reg));
	printf("\tHID2: %x\n", tmp_reg);
	asm("mfspr %0, 0x137" : "=r" (tmp_reg));
	printf("\tMBAR: %x\n", tmp_reg);
	asm("mfspr %0, 0x110" : "=r" (tmp_reg));
	printf("\tSPRG0: %x\n", tmp_reg);
	asm("mfspr %0, 0x111" : "=r" (tmp_reg));
	printf("\tSPRG1: %x\n", tmp_reg);
	asm("mfspr %0, 0x112" : "=r" (tmp_reg));
	printf("\tSPRG2: %x\n", tmp_reg);
	asm("mfspr %0, 0x113" : "=r" (tmp_reg));
	printf("\tSPRG3: %x\n", tmp_reg);
	asm("mfspr %0, 0x114" : "=r" (tmp_reg));
	printf("\tSPRG4: %x\n", tmp_reg);
	asm("mfspr %0, 0x115" : "=r" (tmp_reg));
	printf("\tSPRG5: %x\n", tmp_reg);
	asm("mfspr %0, 0x116" : "=r" (tmp_reg));
	printf("\tSPRG6: %x\n", tmp_reg);
	asm("mfspr %0, 0x117" : "=r" (tmp_reg));
	printf("\tSPRG7: %x\n", tmp_reg);
	asm("mfspr %0, 0x11E" : "=r" (tmp_reg));
	printf("\tSVR: %x\n", tmp_reg);
	asm("mfspr %0, 0x11F" : "=r" (tmp_reg));
	printf("\tPVR: %x\n", tmp_reg);

	printf("\nMMU reg\n");
	asm("mfspr %0, 0x210" : "=r" (tmp_reg));
	printf("\tIBAT0U: %x\n", tmp_reg);
	asm("mfspr %0, 0x211" : "=r" (tmp_reg));
	printf("\tIBAT0L: %x\n", tmp_reg);
	asm("mfspr %0, 0x212" : "=r" (tmp_reg));
	printf("\tIBAT1U: %x\n", tmp_reg);
	asm("mfspr %0, 0x213" : "=r" (tmp_reg));
	printf("\tIBAT1L: %x\n", tmp_reg);
	asm("mfspr %0, 0x214" : "=r" (tmp_reg));
	printf("\tIBAT2U: %x\n", tmp_reg);
	asm("mfspr %0, 0x215" : "=r" (tmp_reg));
	printf("\tIBAT2L: %x\n", tmp_reg);
	asm("mfspr %0, 0x216" : "=r" (tmp_reg));
	printf("\tIBAT3U: %x\n", tmp_reg);
	asm("mfspr %0, 0x217" : "=r" (tmp_reg));
	printf("\tIBAT3L: %x\n", tmp_reg);
	asm("mfspr %0, 0x230" : "=r" (tmp_reg));
	printf("\tIBAT4U: %x\n", tmp_reg);
	asm("mfspr %0, 0x231" : "=r" (tmp_reg));
	printf("\tIBAT4L: %x\n", tmp_reg);
	asm("mfspr %0, 0x232" : "=r" (tmp_reg));
	printf("\tIBAT5U: %x\n", tmp_reg);
	asm("mfspr %0, 0x233" : "=r" (tmp_reg));
	printf("\tIBAT5L: %x\n", tmp_reg);
	asm("mfspr %0, 0x234" : "=r" (tmp_reg));
	printf("\tIBAT6U: %x\n", tmp_reg);
	asm("mfspr %0, 0x235" : "=r" (tmp_reg));
	printf("\tIBAT6L: %x\n", tmp_reg);
	asm("mfspr %0, 0x236" : "=r" (tmp_reg));
	printf("\tIBAT7U: %x\n", tmp_reg);
	asm("mfspr %0, 0x237" : "=r" (tmp_reg));
	printf("\tIBAT7L: %x\n", tmp_reg);
	asm("mfspr %0, 0x218" : "=r" (tmp_reg));
	printf("\tDBAT0U: %x\n", tmp_reg);
	asm("mfspr %0, 0x219" : "=r" (tmp_reg));
	printf("\tDBAT0L: %x\n", tmp_reg);
	asm("mfspr %0, 0x21a" : "=r" (tmp_reg));
	printf("\tDBAT1U: %x\n", tmp_reg);
	asm("mfspr %0, 0x21b" : "=r" (tmp_reg));
	printf("\tDBAT1L: %x\n", tmp_reg);
	asm("mfspr %0, 0x21c" : "=r" (tmp_reg));
	printf("\tDBAT2U: %x\n", tmp_reg);
	asm("mfspr %0, 0x21d" : "=r" (tmp_reg));
	printf("\tDBAT2L: %x\n", tmp_reg);
	asm("mfspr %0, 0x21e" : "=r" (tmp_reg));
	printf("\tDBAT3U: %x\n", tmp_reg);
	asm("mfspr %0, 0x21f" : "=r" (tmp_reg));
	printf("\tDBAT3L: %x\n", tmp_reg);
	asm("mfspr %0, 0x238" : "=r" (tmp_reg));
	printf("\tDBAT4U: %x\n", tmp_reg);
	asm("mfspr %0, 0x239" : "=r" (tmp_reg));
	printf("\tDBAT4L: %x\n", tmp_reg);
	asm("mfspr %0, 0x23a" : "=r" (tmp_reg));
	printf("\tDBAT5U: %x\n", tmp_reg);
	asm("mfspr %0, 0x23b" : "=r" (tmp_reg));
	printf("\tDBAT5L: %x\n", tmp_reg);
	asm("mfspr %0, 0x23c" : "=r" (tmp_reg));
	printf("\tDBAT6U: %x\n", tmp_reg);
	asm("mfspr %0, 0x23d" : "=r" (tmp_reg));
	printf("\tDBAT6L: %x\n", tmp_reg);
	asm("mfspr %0, 0x23e" : "=r" (tmp_reg));
	printf("\tDBAT7U: %x\n", tmp_reg);
	asm("mfspr %0, 0x23f" : "=r" (tmp_reg));
	printf("\tDBAT7L: %x\n", tmp_reg);
	asm("mfspr %0, 0x19" : "=r" (tmp_reg));
	printf("\tSDR1: %x\n", tmp_reg);
	asm("mfsr %0, 0x0" : "=r" (tmp_reg));
	printf("\tSR0: %x\n", tmp_reg);
	asm("mfsr %0, 0x1" : "=r" (tmp_reg));
	printf("\tSR1: %x\n", tmp_reg);
	asm("mfsr %0, 0x2" : "=r" (tmp_reg));
	printf("\tSR2: %x\n", tmp_reg);
	asm("mfsr %0, 0x3" : "=r" (tmp_reg));
	printf("\tSR3: %x\n", tmp_reg);
	asm("mfsr %0, 0x4" : "=r" (tmp_reg));
	printf("\tSR4: %x\n", tmp_reg);
	asm("mfsr %0, 0x5" : "=r" (tmp_reg));
	printf("\tSR5: %x\n", tmp_reg);
	asm("mfsr %0, 0x6" : "=r" (tmp_reg));
	printf("\tSR6: %x\n", tmp_reg);
	asm("mfsr %0, 0x7" : "=r" (tmp_reg));
	printf("\tSR7: %x\n", tmp_reg);
	asm("mfsr %0, 0x8" : "=r" (tmp_reg));
	printf("\tSR8: %x\n", tmp_reg);
	asm("mfsr %0, 0x9" : "=r" (tmp_reg));
	printf("\tSR9: %x\n", tmp_reg);
	asm("mfsr %0, 0xa" : "=r" (tmp_reg));
	printf("\tSR10: %x\n", tmp_reg);
	asm("mfsr %0, 0xb" : "=r" (tmp_reg));
	printf("\tSR11: %x\n", tmp_reg);
	asm("mfsr %0, 0xc" : "=r" (tmp_reg));
	printf("\tSR12: %x\n", tmp_reg);
	asm("mfsr %0, 0xd" : "=r" (tmp_reg));
	printf("\tSR13: %x\n", tmp_reg);
	asm("mfsr %0, 0xe" : "=r" (tmp_reg));
	printf("\tSR14: %x\n", tmp_reg);
	asm("mfsr %0, 0xf" : "=r" (tmp_reg));
	printf("\tSR15: %x\n", tmp_reg);

//	printf("\nLocal Access Register\n");
//	tmp_ptr = 0xE0000000;
//	tmp_reg = *tmp_ptr;
//	printf("\tIMMR: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000008;
//	tmp_reg = *tmp_ptr;
//	printf("\tALTCBAR: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000020;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWBAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000024;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000028;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWBAR1: %x\n", tmp_reg);
//	tmp_ptr = 0xE000002c;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWAR1: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000030;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWBAR2: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000034;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWAR2: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000038;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWBAR3: %x\n", tmp_reg);
//	tmp_ptr = 0xE000003c;
//	tmp_reg = *tmp_ptr;
//	printf("\tLBLAWAR3: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000060;
//	tmp_reg = *tmp_ptr;
//	printf("\tPCILAWBAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000064;
//	tmp_reg = *tmp_ptr;
//	printf("\tPCILAWAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE0000068;
//	tmp_reg = *tmp_ptr;
//	printf("\tPCILAWBAR1: %x\n", tmp_reg);
//	tmp_ptr = 0xE000006c;
//	tmp_reg = *tmp_ptr;
//	printf("\tPCILAWAR1: %x\n", tmp_reg);
//	tmp_ptr = 0xE00000a0;
//	tmp_reg = *tmp_ptr;
//	printf("\tDDRLAWBAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE00000a4;
//	tmp_reg = *tmp_ptr;
//	printf("\tDDRLAWAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE00000a8;
//	tmp_reg = *tmp_ptr;
//	printf("\tDDRLAWBAR0: %x\n", tmp_reg);
//	tmp_ptr = 0xE00000ac;
//	tmp_reg = *tmp_ptr;
//	printf("\tDDRLAWAR0: %x\n", tmp_reg);

	printf("\nSystem configuration\n");
	tmp_ptr = 0xE0000100;
	tmp_reg = *tmp_ptr;
	printf("\tSGPRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0000104;
	tmp_reg = *tmp_ptr;
	printf("\tSGPRH: %x\n", tmp_reg);
	tmp_ptr = 0xE0000108;
	tmp_reg = *tmp_ptr;
	printf("\tSPRIDR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000110;
	tmp_reg = *tmp_ptr;
	printf("\tSPCR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000114;
	tmp_reg = *tmp_ptr;
	printf("\tSICRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0000118;
	tmp_reg = *tmp_ptr;
	printf("\tSICRH: %x\n", tmp_reg);
	tmp_ptr = 0xE0000128;
	tmp_reg = *tmp_ptr;
	printf("\tDDRCDR: %x\n", tmp_reg);
	tmp_ptr = 0xE000012c;
	tmp_reg = *tmp_ptr;
	printf("\tDDRDSR: %x\n", tmp_reg);

	printf("\nWatchdog\n");
	tmp_ptr = 0xE0000204;
	tmp_reg = *tmp_ptr;
	printf("\tWDT cfg: %x\n", tmp_reg);

	printf("\nPeriodic Interval Timer\n");
	tmp_ptr = 0xE0000400;
	tmp_reg = *tmp_ptr;
	printf("\tPTCNR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000404;
	tmp_reg = *tmp_ptr;
	printf("\tPTLDR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000408;
	tmp_reg = *tmp_ptr;
	printf("\tPTPSR: %x\n", tmp_reg);
	tmp_ptr = 0xE000040C;
	tmp_reg = *tmp_ptr;
	printf("\tPTCTR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000410;
	tmp_reg = *tmp_ptr;
	printf("\tPTEVR: %x\n", tmp_reg);

/*
	unsigned char *gtm_char_ptr;
	unsigned char gtm_char;
	unsigned short *gtm_short_ptr;
	unsigned short gtm_short;
	printf("\nGlobal Timer Module 1\n");
	gtm_char_ptr = 0xE0000500;
	gtm_char = *gtm_char_ptr;
	printf("\tGTCFR1: %x\n", gtm_char);
	gtm_char_ptr = 0xE0000504;
	gtm_char = *gtm_char_ptr;
	printf("\tGTCFR2: %x\n", gtm_char);
	gtm_short_ptr = 0xE0000510;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000512;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000514;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000516;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000518;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000051a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE000051c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000051e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000520;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000522;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000524;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000526;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000528;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000052a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE000052c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000052e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000530;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000532;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000534;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000536;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000538;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000053a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE000053c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000053e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR4: %x\n", gtm_short);
	printf("Global Timer Module 2\n");
	gtm_char_ptr = 0xE0000600;
	gtm_char = *gtm_char_ptr;
	printf("\tGTCFR1: %x\n", gtm_char);
	gtm_char_ptr = 0xE0000604;
	gtm_char = *gtm_char_ptr;
	printf("\tGTCFR2: %x\n", gtm_char);
*/
/*
	gtm_short_ptr = 0xE0000610;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000612;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000614;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000616;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000618;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000061a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE000061c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000061e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000620;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000622;
	gtm_short = *gtm_short_ptr;
	printf("\tGTMDR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000624;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000626;
	gtm_short = *gtm_short_ptr;
	printf("\tGTRFR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000628;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000062a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCPR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE000062c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000062e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTCNR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000630;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000632;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000634;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000636;
	gtm_short = *gtm_short_ptr;
	printf("\tGTEVR4: %x\n", gtm_short);
	gtm_short_ptr = 0xE0000638;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR1: %x\n", gtm_short);
	gtm_short_ptr = 0xE000063a;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR2: %x\n", gtm_short);
	gtm_short_ptr = 0xE000063c;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR3: %x\n", gtm_short);
	gtm_short_ptr = 0xE000063e;
	gtm_short = *gtm_short_ptr;
	printf("\tGTPSR4: %x\n", gtm_short);
*/

	printf("\nReset Configuration\n");
	tmp_ptr = 0xE0000900;
	tmp_reg = *tmp_ptr;
	printf("\tRCWLR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000904;
	tmp_reg = *tmp_ptr;
	printf("\tRCWHR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000910;
	tmp_reg = *tmp_ptr;
	printf("\tRSR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000914;
	tmp_reg = *tmp_ptr;
	printf("\tRMR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000918;
	tmp_reg = *tmp_ptr;
	printf("\tRPR: %x\n", tmp_reg);
	tmp_ptr = 0xE000091c;
	tmp_reg = *tmp_ptr;
	printf("\tRCR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000920;
	tmp_reg = *tmp_ptr;
	printf("\tRCER: %x\n", tmp_reg);

	printf("\nClock Configuration\n");
	tmp_ptr = 0xE0000A00;
	tmp_reg = *tmp_ptr;
	printf("\tSPMR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000A04;
	tmp_reg = *tmp_ptr;
	printf("\tOCCR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000A08;
	tmp_reg = *tmp_ptr;
	printf("\tSCCR: %x\n", tmp_reg);
	tmp_ptr = 0xE0000010;
	tmp_reg = *tmp_ptr;
	printf("\tMCKENR: %x\n", tmp_reg);

	tmp_ptr = 0xE0000c00;
	printf("\nGPIO0: \n");
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000c04;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000c08;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000c0c;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000c10;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000c14;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	printf("GPIO1: \n");
	tmp_ptr = 0xE0000d00;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000d04;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000d08;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000d0c;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000d10;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);
	tmp_ptr = 0xE0000d14;
	tmp_reg = *(tmp_ptr);
	printf("\t%x\n", tmp_reg);

	printf("\nDDR Memory Controller\n");
	tmp_ptr = 0xE0002000;
	tmp_reg = *tmp_ptr;
	printf("\tCS0 BNDS: %x\n", tmp_reg);
	tmp_ptr = 0xE0002008;
	tmp_reg = *tmp_ptr;
	printf("\tCS1 BNDS: %x\n", tmp_reg);
	tmp_ptr = 0xE00020010;
	tmp_reg = *tmp_ptr;
	printf("\tCS2 BNDS: %x\n", tmp_reg);
	tmp_ptr = 0xE0002018;
	tmp_reg = *tmp_ptr;
	printf("\tCS3 BNDS: %x\n", tmp_reg);
	tmp_ptr = 0xE0002080;
	tmp_reg = *tmp_ptr;
	printf("\tCS0 CONFIG: %x\n", tmp_reg);
	tmp_ptr = 0xE0002084;
	tmp_reg = *tmp_ptr;
	printf("\tCS1 CONFIG: %x\n", tmp_reg);
	tmp_ptr = 0xE0002088;
	tmp_reg = *tmp_ptr;
	printf("\tCS2 CONFIG: %x\n", tmp_reg);
	tmp_ptr = 0xE000208c;
	tmp_reg = *tmp_ptr;
	printf("\tCS3 CONFIG: %x\n", tmp_reg);
	tmp_ptr = 0xE0002100;
	tmp_reg = *tmp_ptr;
	printf("\tTIMING CFG 3: %x\n", tmp_reg);
	tmp_ptr = 0xE0002104;
	tmp_reg = *tmp_ptr;
	printf("\tTIMING CFG 0: %x\n", tmp_reg);
	tmp_ptr = 0xE0002108;
	tmp_reg = *tmp_ptr;
	printf("\tTIMING CFG 1: %x\n", tmp_reg);
	tmp_ptr = 0xE000210c;
	tmp_reg = *tmp_ptr;
	printf("\tTIMING CFG 2: %x\n", tmp_reg);
	tmp_ptr = 0xE0002110;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM CFG: %x\n", tmp_reg);
	tmp_ptr = 0xE0002114;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM CFG2: %x\n", tmp_reg);
	tmp_ptr = 0xE0002118;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM MODE: %x\n", tmp_reg);
	tmp_ptr = 0xE000211c;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM MODE2: %x\n", tmp_reg);
	tmp_ptr = 0xE0002120;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM MD CNTL: %x\n", tmp_reg);
	tmp_ptr = 0xE0002124;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM INTERVAL: %x\n", tmp_reg);
	tmp_ptr = 0xE0002128;
	tmp_reg = *tmp_ptr;
	printf("\tDDR DATA INIT: %x\n", tmp_reg);
	tmp_ptr = 0xE0002130;
	tmp_reg = *tmp_ptr;
	printf("\tDDR SDRAM CLK CNTL: %x\n", tmp_reg);
	tmp_ptr = 0xE0002148;
	tmp_reg = *tmp_ptr;
	printf("\tDDR INIT ADDR: %x\n", tmp_reg);
	tmp_ptr = 0xE0002bf8;
	tmp_reg = *tmp_ptr;
	printf("\tDDR IP REV1: %x\n", tmp_reg);
	tmp_ptr = 0xE0002bfc;
	tmp_reg = *tmp_ptr;
	printf("\tDDR IP REV2: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e00;
	tmp_reg = *tmp_ptr;
	printf("\tDATA ERR INJECT HI: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e04;
	tmp_reg = *tmp_ptr;
	printf("\tDATA ERR INJECT LO: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e08;
	tmp_reg = *tmp_ptr;
	printf("\tECC ERR INJECT: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e20;
	tmp_reg = *tmp_ptr;
	printf("\tCAPTURE DATA HI: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e24;
	tmp_reg = *tmp_ptr;
	printf("\tCAPTURE DATA LO: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e28;
	tmp_reg = *tmp_ptr;
	printf("\tCAPTURE ECC: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e40;
	tmp_reg = *tmp_ptr;
	printf("\tERR DETECT: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e44;
	tmp_reg = *tmp_ptr;
	printf("\tERR DISABLE: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e48;
	tmp_reg = *tmp_ptr;
	printf("\tERR INT EN: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e4c;
	tmp_reg = *tmp_ptr;
	printf("\tCAPTURE ATTRIBUTES: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e50;
	tmp_reg = *tmp_ptr;
	printf("\tCAPTURE ADDRESS: %x\n", tmp_reg);
	tmp_ptr = 0xE0002e58;
	tmp_reg = *tmp_ptr;
	printf("\tCS0 ERR SBE: %x\n", tmp_reg);

	printf("\nLocal Bus Controller\n");
	tmp_ptr = 0xE0005000;
	tmp_reg = *tmp_ptr;
	printf("\tBR0: %x\n", tmp_reg);
	tmp_ptr = 0xE0005004;
	tmp_reg = *tmp_ptr;
	printf("\tOR0: %x\n", tmp_reg);
	tmp_ptr = 0xE0005008;
	tmp_reg = *tmp_ptr;
	printf("\tBR1: %x\n", tmp_reg);
	tmp_ptr = 0xE000500c;
	tmp_reg = *tmp_ptr;
	printf("\tOR1: %x\n", tmp_reg);
	tmp_ptr = 0xE0005010;
	tmp_reg = *tmp_ptr;
	printf("\tBR2: %x\n", tmp_reg);
	tmp_ptr = 0xE0005014;
	tmp_reg = *tmp_ptr;
	printf("\tOR2: %x\n", tmp_reg);
	tmp_ptr = 0xE0005018;
	tmp_reg = *tmp_ptr;
	printf("\tBR3: %x\n", tmp_reg);
	tmp_ptr = 0xE000501c;
	tmp_reg = *tmp_ptr;
	printf("\tOR3: %x\n", tmp_reg);
	tmp_ptr = 0xE0005020;
	tmp_reg = *tmp_ptr;
	printf("\tBR4: %x\n", tmp_reg);
	tmp_ptr = 0xE0005024;
	tmp_reg = *tmp_ptr;
	printf("\tOR4: %x\n", tmp_reg);
	tmp_ptr = 0xE0005028;
	tmp_reg = *tmp_ptr;
	printf("\tBR5: %x\n", tmp_reg);
	tmp_ptr = 0xE000502c;
	tmp_reg = *tmp_ptr;
	printf("\tOR5: %x\n", tmp_reg);
	tmp_ptr = 0xE0005030;
	tmp_reg = *tmp_ptr;
	printf("\tBR6: %x\n", tmp_reg);
	tmp_ptr = 0xE0005034;
	tmp_reg = *tmp_ptr;
	printf("\tOR6: %x\n", tmp_reg);
	tmp_ptr = 0xE0005038;
	tmp_reg = *tmp_ptr;
	printf("\tBR7: %x\n", tmp_reg);
	tmp_ptr = 0xE000503c;
	tmp_reg = *tmp_ptr;
	printf("\tOR7: %x\n", tmp_reg);
	tmp_ptr = 0xE0005068;
	tmp_reg = *tmp_ptr;
	printf("\tMAR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005070;
	tmp_reg = *tmp_ptr;
	printf("\tMAMR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005074;
	tmp_reg = *tmp_ptr;
	printf("\tMBMR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005078;
	tmp_reg = *tmp_ptr;
	printf("\tMCMR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005084;
	tmp_reg = *tmp_ptr;
	printf("\tMRTPR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005088;
	tmp_reg = *tmp_ptr;
	printf("\tMDR: %x\n", tmp_reg);
	tmp_ptr = 0xE0005094;
	tmp_reg = *tmp_ptr;
	printf("\tLSDMR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050A0;
	tmp_reg = *tmp_ptr;
	printf("\tLURT: %x\n", tmp_reg);
	tmp_ptr = 0xE00050A4;
	tmp_reg = *tmp_ptr;
	printf("\tLSRT: %x\n", tmp_reg);
	tmp_ptr = 0xE00050B0;
	tmp_reg = *tmp_ptr;
	printf("\tLTESR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050B4;
	tmp_reg = *tmp_ptr;
	printf("\tLTEDR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050B8;
	tmp_reg = *tmp_ptr;
	printf("\tLTEIR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050BC;
	tmp_reg = *tmp_ptr;
	printf("\tLTEATR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050C0;
	tmp_reg = *tmp_ptr;
	printf("\tLTEAR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050D0;
	tmp_reg = *tmp_ptr;
	printf("\tLBCR: %x\n", tmp_reg);
	tmp_ptr = 0xE00050D4;
	tmp_reg = *tmp_ptr;
	printf("\tLCRR: %x\n", tmp_reg);

	printf("\nTSEC1\n");
	printf("\tGeneral Control/Status Registers\n");
	tmp_ptr = 0xE0024010;
	tmp_reg = *tmp_ptr;
	printf("\tIEVENT: %x\n", tmp_reg);
	tmp_ptr = 0xE0024014;
	tmp_reg = *tmp_ptr;
	printf("\tIMASK: %x\n", tmp_reg);
	tmp_ptr = 0xE0024018;
	tmp_reg = *tmp_ptr;
	printf("\tEDIS: %x\n", tmp_reg);
	tmp_ptr = 0xE0024020;
	tmp_reg = *tmp_ptr;
	printf("\tECNTRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0024024;
	tmp_reg = *tmp_ptr;
	printf("\tMINFLR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024028;
	tmp_reg = *tmp_ptr;
	printf("\tPTV: %x\n", tmp_reg);
	tmp_ptr = 0xE002402c;
	tmp_reg = *tmp_ptr;
	printf("\tDMACTRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0024030;
	tmp_reg = *tmp_ptr;
	printf("\tTBIPA: %x\n", tmp_reg);
	printf("\tFIFO Control/Status Registers\n");
	tmp_ptr = 0xE002408c;
	tmp_reg = *tmp_ptr;
	printf("\tFIFO_TX_THR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024094;
	tmp_reg = *tmp_ptr;
	printf("\t:FIFO_TX_SP: %x\n", tmp_reg);
	tmp_ptr = 0xE0024098;
	tmp_reg = *tmp_ptr;
	printf("\tFIFO_TX_STARVE: %x\n", tmp_reg);
	tmp_ptr = 0xE002409c;
	tmp_reg = *tmp_ptr;
	printf("\tFIFO_TX_STARVE_SHUTOFF: %x\n", tmp_reg);
	printf("\tTransmit Control/Status Registers\n");
	tmp_ptr = 0xE0024100;
	tmp_reg = *tmp_ptr;
	printf("\tTCTRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0024104;
	tmp_reg = *tmp_ptr;
	printf("\tTSTAT: %x\n", tmp_reg);
	tmp_ptr = 0xE002410c;
	tmp_reg = *tmp_ptr;
	printf("\tTBDLEN: %x\n", tmp_reg);
	tmp_ptr = 0xE0024110;
	tmp_reg = *tmp_ptr;
	printf("\tTXIC: %x\n", tmp_reg);
	tmp_ptr = 0xE0024124;
	tmp_reg = *tmp_ptr;
	printf("\tCTBPTR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024184;
	tmp_reg = *tmp_ptr;
	printf("\tTBPTR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024204;
	tmp_reg = *tmp_ptr;
	printf("\tTBASE: %x\n", tmp_reg);
	tmp_ptr = 0xE00242b0;
	tmp_reg = *tmp_ptr;
	printf("\tOSTBD: %x\n", tmp_reg);
	tmp_ptr = 0xE00242b4;
	tmp_reg = *tmp_ptr;
	printf("\tOSTBDP: %x\n", tmp_reg);
	printf("\tReceive Control/Status Registers\n");
	tmp_ptr = 0xE0024300;
	tmp_reg = *tmp_ptr;
	printf("\tRCTRL: %x\n", tmp_reg);
	tmp_ptr = 0xE0024304;
	tmp_reg = *tmp_ptr;
	printf("\tRSTAT: %x\n", tmp_reg);
	tmp_ptr = 0xE002430c;
	tmp_reg = *tmp_ptr;
	printf("\tRBDLEN: %x\n", tmp_reg);
	tmp_ptr = 0xE0024310;
	tmp_reg = *tmp_ptr;
	printf("\tRXIC: %x\n", tmp_reg);
	tmp_ptr = 0xE0024324;
	tmp_reg = *tmp_ptr;
	printf("\tCRBPTR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024340;
	tmp_reg = *tmp_ptr;
	printf("\tMRBLR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024384;
	tmp_reg = *tmp_ptr;
	printf("\tRBPTR: %x\n", tmp_reg);
	tmp_ptr = 0xE0024404;
	tmp_reg = *tmp_ptr;
	printf("\tRBASE: %x\n", tmp_reg);
	printf("\tMAC Registers\n");
	tmp_ptr = 0xE0024500;
	tmp_reg = *tmp_ptr;
	printf("\tMACCFG1: %x\n", tmp_reg);
	tmp_ptr = 0xE0024504;
	tmp_reg = *tmp_ptr;
	printf("\tMACCFG2: %x\n", tmp_reg);
	tmp_ptr = 0xE0024508;
	tmp_reg = *tmp_ptr;
	printf("\tIPGIFG: %x\n", tmp_reg);
	tmp_ptr = 0xE002450c;
	tmp_reg = *tmp_ptr;
	printf("\tHAFDUP: %x\n", tmp_reg);
	tmp_ptr = 0xE0024510;
	tmp_reg = *tmp_ptr;
	printf("\tMAXFRM: %x\n", tmp_reg);
	tmp_ptr = 0xE0024520;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMCFG: %x\n", tmp_reg);
	tmp_ptr = 0xE0024524;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMCOM: %x\n", tmp_reg);
	tmp_ptr = 0xE0024528;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMADD: %x\n", tmp_reg);
	tmp_ptr = 0xE002452c;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMCON: %x\n", tmp_reg);
	tmp_ptr = 0xE0024530;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMSTAT: %x\n", tmp_reg);
	tmp_ptr = 0xE0024534;
	tmp_reg = *tmp_ptr;
	printf("\tMIIMIND: %x\n", tmp_reg);
	tmp_ptr = 0xE002453c;
	tmp_reg = *tmp_ptr;
	printf("\tIFSTAT: %x\n", tmp_reg);
	tmp_ptr = 0xE0024540;
	tmp_reg = *tmp_ptr;
	printf("\tMACSTNADDR1: %x\n", tmp_reg);
	tmp_ptr = 0xE0024544;
	tmp_reg = *tmp_ptr;
	printf("\tMACSTNADDR2: %x\n", tmp_reg);

	printf ("\n\n");
	return (0);
}
