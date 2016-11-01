//
//  main.c
//  postfix
//
//  Created by 伟刘 on 16/10/5.
//  Copyright © 2016年 git. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "src.h"


int main(int argc, const char * argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    
    mid_to_postfix();
    
    return EXIT_SUCCESS;
}
