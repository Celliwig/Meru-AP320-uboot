# Meru AP320 U-boot

## WARNING!!!
This has been produced by examining the configuration of the device while the original U-boot was running, not by reversing the binary image.
The upshot of this is that all configuration has been for my device, and any variation in the chipsets (DRAM/PHY/etc) will not have been taken
in to account. So whether this will work on any other device is hard to say (YMMV). So the usual boilerplate applies, no warranties implied or given.

### JTAG
It is highly recommended to have access to a JTAG adapter in case of failure. There is __NO WAY TO RECOVER A BRICKED DEVICE__ without one (well that,
or using a soldering iron and device programmer). Before starting, backing up the existing ROM is recommended, or at the very least everything from 
__0xfff00000__ to capture U-boot and environment.

## Compilation
Assuming cross compilation:
```
 CROSS_COMPILE=<_cross compiler prefix_> ARCH=powerpc make meru_ap320_defconfig
 CROSS_COMPILE=<_cross compiler prefix_> ARCH=powerpc make
```

## Installation
If there are no errors it should produce '__u-boot.bin__', which needs to be copied on to the device either over the serial link (eg:__loady__),
or by TFTP (eg:__tftp__). Once the binary is in memory, the U-boot flash sectors need their protection disabled and then the sectors need erasing.
After that the binary can be copied from RAM in to flash ROM. So, using __loady__ as an example:

```
javelin > protect off 0xfff00000 0xfff7ffff
Un-Protected 4 sectors
javelin > erase 0xfff00000 0xfff7ffff

.... done
Erased 4 sectors
javelin > loady
## Ready for binary (ymodem) download to 0x01200000 at 115200 bps...
Cde, 3210(SOH)/0(STX)/0(CAN) packets, 5 retries
## Total Size      = 0x000643b6 = 410550 Bytes
javelin > cp.b 0x01200000 0xfff00000 0x000643b6
Copy to Flash... done
```
 - __0xfff00000__ is the start address of U-boot in the flash ROM (__It is not the start address of the flash ROM__).
 - __0xfff7ffff__ end address of last sector to be unlocked/erased given the new binaries size. (sector size = 128k, 384k < __410k__ < 512k, so 4 sectors)
