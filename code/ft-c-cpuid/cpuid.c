#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * CPUID wrapper.
 * CPUID takes no explicit operands; EAX (and sometimes ECX) select the info
 * leaf. This function queries a CPUID leaf and stores results in the four
 * registers.
 *
 * detailed notes: docs/251113.md (section 2121)
 */
static inline void cpuid(uint32_t leaf, uint32_t *eax, uint32_t *ebx,
                         uint32_t *ecx, uint32_t *edx) {
    __asm__ volatile("cpuid"
                     : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                     : "a" (leaf), "c" (0));
}

/**
 * returns the highest CPUID leaf supported by the CPU
 *
 * CPUID leaf 0 returns:
 *   - EAX = highest valid CPUID leaf
 *   - EBX/ECX/EDX = vendor string fragments
 */
uint32_t cpu_max_leaf(void) {
    uint32_t eax, ebx, ecx, edx;
    cpuid(0, &eax, &ebx, &ecx, &edx);
    return eax;
}

/*
 * returns true if the CPU reports VMX (Intel VT-x) support.
 * CPUID leaf 1: ECX bit 5 = VMX.
 */
bool cpu_supports_vmx(void) {
    uint32_t eax, ebx, ecx, edx;
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (ecx & (1u << 5)) != 0;  // ECX bit 5 = VMX
}

int main() {
    int max_leaves = cpu_max_leaf();
    printf("max_leaves: %d\n", max_leaves);
    if (max_leaves >= 1) printf("cpuid: %d\n", cpu_supports_vmx());
}
