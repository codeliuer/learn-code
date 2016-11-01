//
//  Header.h
//  postfix
//
//  Created by 伟刘 on 16/10/5.
//  Copyright © 2016年 git. All rights reserved.
//

#ifndef __SRC_H__
#define __SRC_H__


/** forever true
 *
 */
#define infinite()      for (;;)

#define BEGIN_DEC       // begin declaration
#define END_DEC         // end declaration

#ifndef true
#define true            (1)
#endif //true

#ifndef false
#define false           (0)
#endif //false

#define HUGE            (0x7FFFFFFFL)

#define ARR_NUM(arr)    (sizeof(arr)/sizeof(arr[0]))


BEGIN_DEC

/** The infix expression into a postfix expression
 *
 */
extern int mid_to_postfix(void);

END_DEC


#endif /* __SRC_H__ */
