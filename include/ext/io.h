/*
********************************************
*
* File    : io.h
* By      : dianguai14
* Version : v0.1
* Date    : 2013-06-25
* Descript:
********************************************
*/
#ifndef __IO_H
#define __IO_H

#define get_bvalue(addr)	(*((volatile unsigned char  *)(addr)))
#define put_bvalue(addr, v)	(*((volatile unsigned char  *)(addr)) = (unsigned char)(v))
#define get_hvalue(addr)	(*((volatile unsigned short *)(addr)))
#define put_hvalue(addr, v)	(*((volatile unsigned short *)(addr)) = (unsigned short)(v))
#define get_wvalue(addr)	(*((volatile unsigned long  *)(addr)))
#define put_wvalue(addr, v)	(*((volatile unsigned long  *)(addr)) = (unsigned long)(v))

#define set_bit(addr, v)    (*((volatile unsigned char  *)(addr)) |=  (unsigned char)(v))
#define clr_bit(addr, v)    (*((volatile unsigned char  *)(addr)) &= ~(unsigned char)(v))
#define set_bbit(addr, v)   (*((volatile unsigned char  *)(addr)) |=  (unsigned char)(v))
#define clr_bbit(addr, v)   (*((volatile unsigned char  *)(addr)) &= ~(unsigned char)(v))
#define set_hbit(addr, v)   (*((volatile unsigned short *)(addr)) |=  (unsigned short)(v))
#define clr_hbit(addr, v)   (*((volatile unsigned short *)(addr)) &= ~(unsigned short)(v))
#define set_wbit(addr, v)   (*((volatile unsigned long  *)(addr)) |=  (unsigned long)(v))
#define clr_wbit(addr, v)   (*((volatile unsigned long  *)(addr)) &= ~(unsigned long)(v))

#define cmp_wvalue(addr, v) (v == (*((volatile unsigned long *) (addr))))

#define readb(addr)		(*((volatile unsigned char  *)(addr)))
#define readw(addr)		(*((volatile unsigned short *)(addr)))
#define readl(addr)		(*((volatile unsigned long  *)(addr)))
#define writeb(v, addr)	(*((volatile unsigned char  *)(addr)) = (unsigned char)(v))
#define writew(v, addr)	(*((volatile unsigned short *)(addr)) = (unsigned short)(v))
#define writel(v, addr)	(*((volatile unsigned long  *)(addr)) = (unsigned long)(v))

/**
 * sr32 - clear & set a value in a bit range for a 32 bit address
 */
static __inline void sr32(u32 addr, u32 start_bit, u32 num_bits, u32 value)
{
    u32 tmp, msk = (1 << num_bits) - 1;
    tmp = readl(addr) & ~(msk << start_bit);
    tmp |= value << start_bit;
    writel(tmp, addr);
}

#endif
