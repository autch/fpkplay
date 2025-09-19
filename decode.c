#include "pcestdint.h"
#include <string.h>

#include "lzss.h"

static uint8_t pTemp[N];

void decodeLZSS(const uint8_t* pSrc, uint8_t* pDest)
{
    int r = N - F;
    uint8_t flags = 0;
    int flagCount = 0;
    uint32_t decodedCount = 0;
    uint32_t decodedSize = pSrc[0] | (pSrc[1] << 8) | (pSrc[2] << 16) | (pSrc[3] << 24);

    pSrc += 4;

    memset(pTemp, 0, sizeof(pTemp));
    while (decodedCount < decodedSize) {
        if (flagCount == 0) {
            flags = *pSrc++;
            flagCount = 8;
        }

        if (flags & 0x80) {
            // Literal byte
            pTemp[r++] = pDest[decodedCount++] = *pSrc++;
            r &= (N - 1);
        } else {
            // Reference
            uint8_t b1 = *pSrc++;
            uint8_t b2 = *pSrc++;
            int i;

            unsigned offset = b1 | ((b2 & 0xF0) << 4);
            unsigned length = (b2 & 0x0F) + 3;

            for (i = 0; i < length && decodedCount < decodedSize; i++) {
                pTemp[r++] = pDest[decodedCount++] = pTemp[(offset + i) & (N - 1)];
                r &= (N - 1);
            }
        }

        flags <<= 1;
        flagCount--;
    }
}
