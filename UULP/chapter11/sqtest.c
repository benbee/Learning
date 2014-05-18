typedef int SElemType;

typedef struct SqStack

{
    char *base;
    char *top;
    char stacksize;
}SqStack;



void InitStack (SqStack &S)

{
    S.base=(char *) malloc (STACK_INIT_SIZE *sizeof(char));
    if (!S.base)
        exit (OVERFLOW); //为栈S分配存储空间失败
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;

}

int Push(SqStack &S,char ch)

// 将元素e插入到栈S中，成为新的栈顶元素

{

    if (S.top-S.base>S.stacksize) //Stack==full?

    { S.base=(char *)realloc(S.base,(S.stacksize+STACKINCREMENT *sizeof(char)));

        if (!S.base)

        { printf("Failure to reallocate the Memory units!:\n");

            exit(OVERFLOW);

        }

        S.top=S.base+S.stacksize; //To Modify pointer of Satck top

        S.stacksize+=STACKINCREMENT; //To modify the size of stack

    } // end of if

    *S.top++=ch; //先将e送入栈顶指针所指向的单元，再将栈顶指针加1

    return(OK);

} //end of Push() subfunction

int Pop(SqStack &S,char &ch)

{
    if (S.top==S.base)

    {
        printf("下溢！");

            return (ERROR);
    }

    ch=*--S.top;
    return (OK);
}

void Translation()

{//将算术表达式转化为逆波兰表达式，num为算术表达式的字符总个数

    int i,j;

    char str[100],exp[100],ch;

    SqStack S;

    InitStack(S);

    i=1;

    printf(" 请输入算术表达式字符串，求其逆波兰表达式，以＃为结束标志，如a-b*c/(3+6)#:\n");

    do

    {

        scanf("%c",&str);

        i++;

    }while(str[i-1]!='#');

    str[0]='('; //将表达式放在（）内

    str[i-1]=')';

    str='#';

    i=0;

    j=0;

    while(str!='#')

    {
        if((str>='0' &&str<='9')||(str>='a' &&str<='z'))

        {

            exp[j]=str;

            j++;

        } //end of if

        else if(str=="(")

            Push(S.str);

        else if(str==')')

        {
            while(*(S.top-1)!='(')

//将S中左括弧"（"以前的所有字符依次弹出并存入数组exp中

            { Pop(S,ch); exp[j]=ch; j++; }

            S.top--;

        } //end of elseif

        else if(str=='+'||str=='-') //如果判定为"＋"号或"-"号，则做如下操作

        { while((s.top!=S.base)&&(*(S.top-1)!='('))

//将S中左括弧"（"以前字符依次弹出并存入数组exp 中

            { Pop(S,ch); exp[j]=ch; j++; }

            Push(S,str);

        } //end of else if

        else if (str=='*'||str=='/')

        {

            while((*(S.top-1)=='*')||(*(S.top-1)=='/'))

            { Pop(S,ch); exp[j]=ch; j++; }

            Push(S,str);

        } //end of else if

        i++;

    } //end of while

    exp[j]='#';

    printf("\n\n输入的算术表达式");

    i=1;

    while(str[i+1]!='#')

    { printf("%c",str);

        i++;

    } //end of while

    printf(" 逆波兰表达式为：\n");

    i=0;

    while(exp!='#')

    { printf("%c",exp); i++; }

}

void main()

{

    Translation();

    printf("\n");

    printf("…OK…!");


}
