#include <iostream>
using namespace std;

int live_up()
{
    static int life = 3;
    return life = life + 3;
}

int main()
{
    int life = 3;
    life = live_up();
    printf("Life: %d \n", life);
    life = live_up();
    unsigned int a = 3;
    printf("Life: %d \n", life);
    return 0;
}