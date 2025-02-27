#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT)     ( (REG) |=  (1<<(BIT)) )
#define CLEAR_BIT(REG, BIT)   ( (REG) &= ~(1<<(BIT)) )
#define TOGGLE_BIT(REG, BIT)  ( (REG) ^=  (1<<(BIT)) )
#define GET_BIT(REG, BIT)     ( ( (REG) >> (BIT) ) & 1 )



#define WRITE_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )






#endif
