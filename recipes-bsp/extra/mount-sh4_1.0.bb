DESCRIPTION = "Mount sh4 root as usb."
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://${OPENPLI_BASE}/LICENSE;md5=eb723b61539feef013de476e68b5c50a"

RDEPENDS_${PN} = "kernel-module-yaffs"

SRC_URI = "file://mountsh4"

FILES_${PN} = "${sysconfdir}"

do_install () {
    install -d ${D}${sysconfdir}/init.d
    install ${WORKDIR}/mountsh4 ${D}${sysconfdir}/init.d
}

INITSCRIPT_NAME = "mountsh4"
INITSCRIPT_PARAMS = "start 39 S ."

inherit update-rc.d
