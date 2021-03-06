/*
 * OMAP3 boot
 *
 * Copyright (C) 2015 Paul Kocialkowski <contact@paulk.fr>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <spl.h>

static u32 boot_devices[] = {
	BOOT_DEVICE_ONENAND,
	BOOT_DEVICE_NAND,
	BOOT_DEVICE_ONENAND,
	BOOT_DEVICE_MMC2,
	BOOT_DEVICE_ONENAND,
	BOOT_DEVICE_MMC2,
	BOOT_DEVICE_MMC1,
	BOOT_DEVICE_XIP,
	BOOT_DEVICE_XIPWAIT,
	BOOT_DEVICE_MMC2,
	BOOT_DEVICE_XIP,
	BOOT_DEVICE_XIPWAIT,
	BOOT_DEVICE_NAND,
	BOOT_DEVICE_XIP,
	BOOT_DEVICE_XIPWAIT,
	BOOT_DEVICE_NAND,
	BOOT_DEVICE_ONENAND,
	BOOT_DEVICE_MMC2,
	BOOT_DEVICE_MMC1,
	BOOT_DEVICE_XIP,
	BOOT_DEVICE_XIPWAIT,
	BOOT_DEVICE_NAND,
	BOOT_DEVICE_ONENAND,
	BOOT_DEVICE_MMC2,
	BOOT_DEVICE_MMC1,
	BOOT_DEVICE_XIP,
	BOOT_DEVICE_XIPWAIT,
	BOOT_DEVICE_NAND,
	BOOT_DEVICE_MMC2_2,
};

u32 omap_sys_boot_device(void)
{
	struct ctrl *ctrl_base = (struct ctrl *)OMAP34XX_CTRL_BASE;
	u32 sys_boot;

	/* Grab the first 5 bits of the status register for SYS_BOOT. */
	sys_boot = readl(&ctrl_base->status) & ((1 << 5) - 1);

	if (sys_boot >= (sizeof(boot_devices) / sizeof(u32)))
		return BOOT_DEVICE_NONE;

	return boot_devices[sys_boot];
}
