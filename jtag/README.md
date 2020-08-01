# JTAG
The device has a 16 pin JTAG interface. Some googling turned up:

- http://sun.hasenbraten.de/~frank/docs/mpc824x_JTAG.html

Which, for the basic signals at least, is the same.

		J4
	TDO   1	* * 2  Gnd
	TDI   3	* * 4  
	      5	* * 6  
	TCK   7	* * 8  
	TMS   9	* * 10 Gnd
	?RST 11	* * 12 Gnd
	?RST 13	* * 14 
	     15	* * 16 Gnd

## UrJTAG
The Ubuntu package was out of date so had to be built from source. Using a J-Link adapter a basic session would start:

```
hostname:~$ ./urjtag-2019.12/src/apps/jtag/jtag 

UrJTAG 2019.12 #
Copyright (C) 2002, 2003 ETC s.r.o.
Copyright (C) 2007, 2008, 2009 Kolja Waschk and the respective authors

UrJTAG is free software, covered by the GNU General Public License, and you are
welcome to change it and/or distribute copies of it under certain conditions.
There is absolutely no warranty for UrJTAG.

warning: UrJTAG may damage your hardware!
Type "quit" to exit, "help" for help.

jtag> cable jlink 
J-Link initial read failed, don't worry (result=0)
Vref = 3.299 TCK=1 TDI=0 TDO=1 TMS=0 TRES=1 TRST=255
J-Link JTAG Interface ready
jtag> bsdl path bsdl
jtag> detect
IR length: 8
Chain length: 1
Device Id: 00110001100101000000000000011101 (0x3194001D)
  Filename:     bsdl/MPC8349E_TBGA.R3A
jtag> initbus mpc837x mux width=8
MUXed 32b address, 8b data bus
jtag> detectflash 0xff000000
Query identification string:
	Primary Algorithm Command Set and Control Interface ID Code: 0x0002 (AMD/Fujitsu Standard Command Set)
	Alternate Algorithm Command Set and Control Interface ID Code: 0x0000 (null)
Query system interface information:
	Vcc Logic Supply Minimum Write/Erase or Write voltage: 2700 mV
	Vcc Logic Supply Maximum Write/Erase or Write voltage: 3600 mV
	Vpp [Programming] Supply Minimum Write/Erase voltage: 0 mV
	Vpp [Programming] Supply Maximum Write/Erase voltage: 0 mV
	Typical timeout per single byte/word program: 64 us
	Typical timeout for maximum-size multi-byte program: 64 us
	Typical timeout per individual block erase: 512 ms
	Typical timeout for full chip erase: 65536 ms
	Maximum timeout for byte/word program: 512 us
	Maximum timeout for multi-byte program: 2048 us
	Maximum timeout per individual block erase: 4096 ms
	Maximum timeout for chip erase: 262144 ms
Device geometry definition:
	Device Size: 16777216 B (16384 KiB, 16 MiB)
	Flash Device Interface Code description: 0x0002 (x8/x16)
	Maximum number of bytes in multi-byte program: 64
	Number of Erase Block Regions within device: 1
	Erase Block Region Information:
		Region 0:
			Erase Block Size: 131072 B (128 KiB)
			Number of Erase Blocks: 128
Primary Vendor-Specific Extended Query:
	Major version number: 1
	Minor version number: 3
	Address Sensitive Unlock: Required
	Process Technology: Bad value
	Erase Suspend: Read/write
	Sector Protect: 1 sectors per group
	Sector Temporary Unprotect: Supported
	Sector Protect/Unprotect Scheme: Bad value
	Simultaneous Operation: Not supported
	Burst Mode Type: Supported
	Page Mode Type: 8 word Page
	ACC (Acceleration) Supply Minimum: 11500 mV
	ACC (Acceleration) Supply Maximum: 12500 mV
	Top/Bottom Sector Flag: Uniform bottom boot device
	Program Suspend: Not supported
jtag> cable jlink 
J-Link initial read failed, don't worry (result=0)
Vref = 3.299 TCK=1 TDI=0 TDO=1 TMS=0 TRES=1 TRST=255
J-Link JTAG Interface ready
jtag> bsdl path bsdl
jtag> detect
IR length: 8
Chain length: 1
Device Id: 00110001100101000000000000011101 (0x3194001D)
  Filename:     bsdl/MPC8349E_TBGA.R3A
```
__N.B.__ - If flash ROM detection fails, trying again usually succeeds.

### U-boot Sector Protection
U-boot uses Persistent Protection Bit (PPB) locking for sector protection. UrJTAG does not support this unfortunately, so if you want to erase (and 
presumably reflash) a sector you'll need to remove this protection. This can be acheived using UrJTAG's peek and poke commands. There's a script to do
this in the scripts directory. If the ROM isn't a Spansion S29GL128, then it's worth checking it's command definitions (thou it's almost certainly part
of the CFI specification therefore it will be the same).
