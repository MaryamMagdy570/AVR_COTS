#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_



#define  SET_BIT(res,index) res=res|(1<<index)
#define  TOGGLE_BIT(res,index) res=res^(1<<index)
#define  CLR_BIT(res,index) res=res&(~(1<<index))
#define  GET_BIT(res,index) ((res>>index)&1)


#endif 
