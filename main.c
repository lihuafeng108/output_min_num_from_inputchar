#include <stdio.h>
#include <string.h>

struct record
{
    char num;    //<lihf> 数字
    int  count;  //<lihf> 出现的次数
};

//<lihf> 找出数组值最小的下标，并记录到输入参数中
static int fine_min_num_and_count(char const *array, int len, struct record *result)
{
    int min = 999999;
    
    for(int i=0; i<len; i++)
    {
        if(min > array[i])
        {
            min = array[i];
            
            result->num = i;
            result->count = min;
        }
    }
}

static int output_min_num(char const *src, int len)
{
    char signers[10] = {0};  //<lihf> 如果src记录的字符存在，数组signers[]则记录对应下标的数字出现的次数，0表示无
    char tmp;
    int ret_num = -1;
    
    if( (NULL == src) || (len <=0) )
    {
        printf("输入参数有误");
        return -1;
    }
    
    for(int i=0; i<len; i++)
    {
        if( ('0' <= src[i]) && (src[i] <= '9') )
        {
            tmp = src[i] - '0';
            signers[tmp]++;
        }
    }
    
    struct record result;
    fine_min_num_and_count(signers, 10, &result);
    
    //(1) 当0出现的个数为0的时候
    if( (0 == result.num) &&  (0 == result.count) )
    {
        struct record result_tmp;
        fine_min_num_and_count(signers+1, 9, &result_tmp);
        if(0 == result_tmp.count)
        {//其他某个数字也出现0个
            
            ret_num = result_tmp.num+1;
        }
        else
        {
            ret_num = 1*10*(result.count+1);
        }
    }
    else
    {//非零的值出现的个数为0
        ret_num = result.num*(result.count+1);
    }
    
    return ret_num;
}

int main(void)
{
    int ret;
    char input[1024] = {0};
    int slen;
    
    scanf("%c", input);
    slen =  strlen(input);
    
    ret = output_min_num(input, slen);
    if( ret > 0)
    {
        printf("%d\n", ret);
    }
     
    return 0;
}