#define MAXLEN 255     //预定义最大串长为255

//--------------------------------存储结构--------------------------------

//1. 定长顺序字符表示
typedef struct{
    char ch[MAXLEN];    //每个变量存储一个字符
    int length;         //串的实际长度
}SString;

//2. 堆分配存储表示
typedef struct{
    char *ch;   //按串长分配存储区
    int length; //串的长度
}HString;

//--------------------------------模式匹配--------------------------------
//若主串S中存在与串T值相同的字串，则返回他在主串S中第一次出现的位置；否则函数值为0。

//1. 简单的模式匹配算法
int Index(SString S, SString T){
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length){
        if(S.ch[i] == T.ch[j]){
            //继续比较后继字符
            ++i;
            ++j;
        }else{
            //指针后退重新开始匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.length){
        return i - T.length;
    }else{
        return 0;
    }
}

//2. KMP算法
void get_next(SString T, int next[]){
    int i,j = 0;
    next[1] = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            //若P(i) = P(j), 则next[j+1] = next[j] + 1
            next[i] = j;
        }else{
            //否则令j = next[j],循环继续
            j = next[j];
        }
    }
}

int Index_KMP(SString S, SString T, int next[]){
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length){
        if(j == 0 || S.ch[i] == T.ch[j]){
            //继续比较后继字符
            ++i;
            ++j;
        }else{
            //模式串向右移动
            j = next[j];
        }
        if( j > T.length){
            //匹配成功
            return i - T.length;
        }else{
            return 0;
        }
    }
}

//3. KMP算法的优化

void get_nextval(SString T, int nextval[]){
    int i,j = 0;
    nextval[1] = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            if(T.ch[i] != T.ch[j]){
                nextval[i] = j;
            }else{
                nextval[i] = nextval[j]; 
            }
        }else{
            //否则令j = next[j],循环继续
            j = nextval[j];
        }
    }    
}