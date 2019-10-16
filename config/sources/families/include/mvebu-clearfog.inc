case $BRANCH in

	legacy|current|default|next)

		# Check https://developer.solid-run.com/knowledge-base/a388-u-boot
		# for advanced config options

		BOOTDIR='u-boot-armada'
		BOOTSOURCE='https://github.com/SolidRun/u-boot'
		BOOTBRANCH='branch:v2018.01-solidrun-a38x'
		BOOTSCRIPT='boot-mvebu-next.cmd:boot.cmd'
		BOOTPATCHDIR='u-boot-mvebu'
		UBOOT_TARGET_MAP=";sdhc;u-boot-spl-sdhc.kwb:u-boot.mmc
						  ;mmc;u-boot-spl-mmc.kwb:u-boot.emmc
						  ;spi;u-boot-spl-spi.kwb:u-boot.flash
						  ;sata;u-boot-spl-sata.kwb:u-boot.sata
						  ;uart;u-boot-spl-uart.kwb:u-boot.uart"
		UBOOT_USE_GCC='> 7.0'
		UBOOT_COMPILER='arm-linux-gnueabihf-'

	;;
	dev)
		if [[ $BOARD == clearfogbase ]]; then
			OVERLAY_PREFIX='armada-388-clearfog-base'
		else
			OVERLAY_PREFIX='armada-388-clearfog'
		fi
esac