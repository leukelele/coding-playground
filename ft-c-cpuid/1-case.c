#include <linux/module.h>
#include <asm/msr.h>
#include <asm/msr-index.h>
#include <stdio.h>

bool vmx_bios_enabled(void) {
    u64 value;
    rdmsrl(MSR_IA32_FEATURE_CONTROL, value);
    return (value & 0x5) == 0x5;
}

int main() {
    printf("vmx_bios_enabled: %d\n", vmx_bios_enabled());
}
