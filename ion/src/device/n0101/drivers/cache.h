#ifndef ION_DEVICE_CACHE_H
#define ION_DEVICE_CACHE_H

#include <regs/regs.h>

namespace Ion {
namespace Device {
namespace Cache {

/* Data synchronisation barrier
 * Ensures that the processor stalls until the memory write is complete */
inline void dsb() {
  asm volatile("dsb 0xF":::"memory");
}

/* Instructions synchronisation barrier
 * Ensures that the subsequent instructions are loaded in the new context */
inline void isb() {
  asm volatile("isb 0xF":::"memory");
}

void invalidateDCache();
void enableDCache();
void disableDCache();

void invalidateICache();
void enableICache();
void disableICache();

void privateCleanInvalidateDisableDCache(bool clean, bool invalidate, bool disable);

}
}
}

#endif