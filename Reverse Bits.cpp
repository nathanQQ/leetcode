/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/

#define BIT(n) (1 << (n))

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int cnt = 0;
        int toggle = 0;
        
        for (;cnt < 16; cnt++) {
            if (((n & BIT(cnt)) >> cnt) != ((n & BIT(31 - cnt)) >> (31 - cnt))) {
                toggle |= BIT(cnt) | BIT(31 - cnt);
            }
        }
        return (n ^ toggle);
    }
};