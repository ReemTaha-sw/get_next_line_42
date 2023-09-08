#include "get_next_line.h"


int sum(int nb)
{
    nb ++;
    return (nb);
}
int static_sum()
{
    static int sum = 1;
    sum++;
    return (sum);
}
// int sum(int static nb)
// {
//     return (nb*nb);
// }
int main()
{
    printf("%d\n",static_sum());
    printf("%d\n",static_sum());
    printf("%d\n",static_sum());
    printf("%d\n",static_sum());
    printf("%d\n",sum(2));
    printf("%d\n",sum(2));
    printf("%d\n",sum(2));
}
