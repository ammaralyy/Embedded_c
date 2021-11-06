#ifndef utilities.h
#define utilities.h

#define set_bit(register, bit_number) register |= (1 << bit_number)

#define clear_bit(register, bit_number) register &= ~(1 << bit_number)

#define toggle_bit(register, bit_number) register ^= (1 << bit_number)

#define get_bit(register, bit_number) (register >> bit_number) & 1

#endif