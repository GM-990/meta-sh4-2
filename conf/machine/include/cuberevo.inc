require conf/machine/include/oem-sh4.inc
require conf/machine/include/normal-sh4-image.inc

BOX_BRAND = "cuberevo"

MTD_KERNEL = "mtd3"
MTD_ROOTFS = "mtd4"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-${BOX_BRAND}"

IMAGE_FSTYPES = "tar.gz"

AUDIOELF = "audio_7100.elf"
VIDEOELF = "video_7109.elf"

SOC_FAMILY = "sti7109"

DVB1FIRMWARE = "dvb-fe-cx24116.fw"
DVB2FIRMWARE = "dvb-fe-stv6306.fw"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	${@bb.utils.contains("MACHINE", "cuberevo_9500hd", "", "eeprom-dgs", d)} \
	firmware-sh4 \
	fp-control \
	stlinux24-sh4-stx7109-fdma-firmware \
	"

MACHINE_FEATURES += "ci SCART"

EXTRA_OECONF_append_pn-enigma2 = " --with-cuberevostb"

CAN_USE_ENIGMA2_IN_FLASH = "0"

RCTYPE ?= "13"
RCNAME ?= "cuberevo_uni"
