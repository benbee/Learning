#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define C1 2
#define C2 2
#define VMAX 10
#define MAX_ITERATIONS 1000


double rand0_1(void) {
    return rand()/(RAND_MAX + 1.0);
}

struct particle {
    double current;
    double pbest;
};

double fitness(double x)
{
    return x*x - 20*x + 100;
}

double gbest = 1000000;
struct particle p[10];
double v[10] = {0};

void particle_init(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        p[i].current = -2 + i;
        p[i].pbest = p[i].current;
    }
}

void find_gbest(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (fitness(gbest) > fitness(p[i].current)) {
            gbest = p[i].current;
        }
    }
}

void adjust_v(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        v[i] = v[i] + C1 * rand0_1() * (p[i].pbest - p[i].current) +
            C2 * rand0_1() * (gbest - p[i].current);
        if (v[i] > VMAX) {
            v[i] = VMAX;
        }
    }
}

void pso(void)
{
    int i, iter_num;
    iter_num = 1;

    while (iter_num < MAX_ITERATIONS) {
        for (i = 0 ; i < 10; i++) {
            if (fitness(p[i].current) < fitness(p[i].pbest)) {
                p[i].pbest = p[i].current;
            }
        }

        find_gbest();
        adjust_v();
        for (i = 0; i < 10; i++) {
            p[i].current += v[i];
        }

        iter_num++;
    }
}

int main(int argc, char *argv[])
{
    srand((unsigned) time(NULL));

    particle_init();
    pso();
    printf("gbest: %f\n", gbest);

    for (int i = 0; i < 10; i++) {
        printf("rand%d: %f\n", i, rand0_1());
    }

    printf("rand: %f\n", rand0_1());
    printf("rand: %f\n", rand0_1());

    return 0;
}
