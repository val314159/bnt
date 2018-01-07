/*
 * Modified in 2018 by Joel M Ward "@val314159" <jmward@gmail.com>
 */
/*
 *
 *  RIPEMD160.c : RIPEMD-160 implementation
 *
 * Written in 2008 by Dwayne C. Litzenberger <dlitz@dlitz.net>
 *
 * ===================================================================
 * The contents of this file are dedicated to the public domain.  To
 * the extent that dedication to the public domain is not available,
 * everyone is granted a worldwide, perpetual, royalty-free,
 * non-exclusive license to exercise all rights associated with the
 * contents of this file for any purpose whatsoever.
 * No rights are reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ===================================================================
 *
 * Country of origin: Canada
 *
 * This implementation (written in C) is based on an implementation the author
 * wrote in Python.
 *
 * This implementation was written with reference to the RIPEMD-160
 * specification, which is available at:
 * http://homes.esat.kuleuven.be/~cosicart/pdf/AB-9601/
 *
 * It is also documented in the _Handbook of Applied Cryptography_, as
 * Algorithm 9.55.  It's on page 30 of the following PDF file:
 * http://www.cacr.math.uwaterloo.ca/hac/about/chap9.pdf
 *
 * The RIPEMD-160 specification doesn't really tell us how to do padding, but
 * since RIPEMD-160 is inspired by MD4, you can use the padding algorithm from
 * RFC 1320.
 *
 * According to http://www.users.zetnet.co.uk/hopwood/crypto/scan/md.html:
 *   "RIPEMD-160 is big-bit-endian, little-byte-endian, and left-justified."
 */

#include <stdint.h>
#include <assert.h>
#include <string.h>

#define RIPEMD160_DIGEST_SIZE 20
#define BLOCK_SIZE 64

#define RIPEMD160_MAGIC 0x9f19dd68u
typedef struct {
    uint32_t magic;
    uint32_t h[5];      /* The current hash state */
    uint64_t length;    /* Total number of _bits_ (not bytes) added to the
                           hash.  This includes bits that have been buffered
                           but not not fed through the compression function yet. */
    union {
        uint32_t w[16];
        uint8_t b[64];
    } buf;
    uint8_t bufpos;     /* number of bytes currently in the buffer */
} ripemd160_state;

ripemd160_state ripemd160_init(ripemd160_state *self);
void ripemd160_update(ripemd160_state *self, const unsigned char *p, int length);
//void ripemd160_copy(const ripemd160_state *source, ripemd160_state *dest);
int  ripemd160_digest(const ripemd160_state *self, unsigned char *out);

void ripemd160_load(const char*const filename, ripemd160_state *source);
void ripemd160_save(const ripemd160_state *dest, const char*const filename);
void ripemd160_dump(const ripemd160_state*self);
