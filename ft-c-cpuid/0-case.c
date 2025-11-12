#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static inline void cpuid(uint32_t leaf, uint32_t *eax, uint32_t *ebx,
                         uint32_t *ecx, uint32_t *edx) {
    __asm__ volatile("cpuid"
                     : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                     : "a" (leaf), "c" (0));
}

bool cpu_supports_vmx(void) {
    uint32_t eax, ebx, ecx, edx;
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (ecx & (1u << 5)) != 0;  // ECX bit 5 = VMX
}

int main() {
    printf("CPUID: %d\n", cpu_supports_vmx());
}

