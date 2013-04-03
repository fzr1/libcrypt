#ifndef MD5_HEAD
#define MD5_HEAD

#include <iostream>
#include <cstdint>

#define MD5_F(x,y,z) (((x) & (y)) | ((~(x)) & (z)))
#define MD5_G(x,y,z) (((x) & (z)) | ((~(z)) & (y)))
#define MD5_H(x,y,z) ((x) ^ (y) ^ (z))
#define MD5_I(x,y,z) ((y) ^ ( (x) | (~(z)) )) 

typedef struct MD5Hash
{
	uint32_t a,b,c,d;
} MD5Hash;

const uint32_t MD5_S[64] = {7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
				 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
				 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
				 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};


const uint32_t MD5_K[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
					   0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
				       0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
				       0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
				       0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
				       0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
				       0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
				       0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
				       0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
				       0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
				       0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
				       0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
				       0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
				       0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
				       0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
				       0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

const uint32_t  a0 = 0x67452301,
				b0 = 0xefcdab89,
				c0 = 0x98badcfe,
				d0 = 0x10325476;

void		md5_private(uint8_t* str, size_t size, MD5Hash*);
std::string md5(std::string);
void		md5hash2littleEndian(MD5Hash*);
uint32_t	littleEndian(uint32_t);
std::string	md5hash2string(MD5Hash);

#endif
