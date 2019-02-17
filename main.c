#include <stdio.h>
#include <string.h>
#include <math.h>

struct record
{
    char num;    //<lihf> ����
    int  count;  //<lihf> ���ֵĴ���
};

//<lihf> �ҳ�����ֵ��С���±꣬����¼�����������
static int fine_min_num_and_count(char const *array, int len, struct record *result)
{
    int min = 999999;
    
    for(int i=0; i<len; i++)
    {
        if(min > array[i])
        {
            min = array[i];
            
            result->num = i+1;
            result->count = min;
        }
    }
}

static int output_min_num(char const *src, int len)
{
    char signers[11] = {0};  //<lihf> ���src��¼���ַ����ڣ�����signers[]���¼��Ӧ�±�����ֳ��ֵĴ�����0��ʾ��
    char tmp;
    int ret_num = -1;
    
    if( (NULL == src) || (len <=0) )
    {
        printf("�����������");
        return -1;
    }
    
    for(int i=0; i<len; i++)
    {
        if( ('0' < src[i]) && (src[i] <= '9') )
        {
            tmp = src[i] - '0';
            signers[tmp]++;
        }
        else if( '0' == src[i] )
        {
            signers[10]++;
        }
    }
    
    char *ptr = signers;
    struct record result;
    fine_min_num_and_count(ptr+1, 10, &result);
    
    if(10 == result.num)
    {
        ret_num = pow(10, result.count+1);
    }
    else
    {
        ret_num = result.num;
        for(int i=0; i<result.count; i++)
        {
            ret_num = ret_num*10 + result.num;
        }
    }    
    
    return ret_num;
}

int main(void)
{
    int ret;
    char input[1024] = {0};
    int slen;
    
    while(1)
    {
        scanf("%s", input);
        slen =  strlen(input);
        
        if( ('0' == input[0]) && (1 == slen) )
        {
            break;
        }
        
        ret = output_min_num(input, slen);
        if( ret > 0)
        {
            printf("%d\n", ret);
        }
    }
    
    return 0;
}