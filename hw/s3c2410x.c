/* hw/s3c2410x.c
 *
 * Samsung S3C2410X emulation
 *
 * Copyright 2009 Daniel Silverstone and Vincent Sanders
 *
 * This file is under the terms of the GNU General Public
 * License Version 2
 */

#include "hw.h"

#include "s3c2410x.h"

/* Integrated peripherals */
#define CPU_S3C2410X_SRAM_BASE (CPU_S3C2410X_PERIPHERAL + 0x00000000)
#define CPU_S3C2410X_SRAM_SIZE 4096

/* Initialise a Samsung S3C2410X SOC ARM core and internal peripherals. */
S3CState *
s3c2410x_init(int sdram_size)
{
    ram_addr_t offset;
    S3CState *s = (S3CState *)qemu_mallocz(sizeof(S3CState));

    /* Prepare the ARM 920T core */
    s->cpu_env = cpu_init("arm920t");

    /* S3C2410X SDRAM memory is always at the same physical location */
    offset = qemu_ram_alloc(NULL, "s3c2410x.sdram", sdram_size);
    cpu_register_physical_memory(CPU_S3C2410X_DRAM,
                                 ram_size,
                                 offset | IO_MEM_RAM);

    /* S3C2410X SRAM */
    offset = qemu_ram_alloc(NULL, "s3c2410x.sdram", CPU_S3C2410X_SRAM_SIZE);
    cpu_register_physical_memory(CPU_S3C2410X_SRAM_BASE,
                                 CPU_S3C2410X_SRAM_SIZE,
                                 offset | IO_MEM_RAM);

    return s;
}
