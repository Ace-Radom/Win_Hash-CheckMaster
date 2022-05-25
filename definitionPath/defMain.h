#ifndef _DEFMAIN_H_
#define _DEFMAIN_H_

#define _ERROR_ 0x00  /* define error signal */
#define _Worklist_LengthMAX 1000  /* define the maximum length of the worklist */

#define NOT_READY false
#define READY true

/* define hash type NUM */
#define NO_HASHTYPE 0x00
#define MD5 0x01
#define SHA1 0x02
#define SHA256 0x03
#define SHA512 0x04

/* set hash type bits in use */
#define MD5_CHECK 32
#define SHA1_CHECK 40
#define SHA256_CHECK 64
#define SHA512_CHECK 128

/* define command NUM */
#define Program_Start 0x05

/* define display color NUM */
#define RED 0x20
#define YELLOW 0x21
#define WHITE 0x22
#define GREEN 0x23
#define PURPIL 0x24
#define FOREGROUND_PURPIL 0x05

#endif