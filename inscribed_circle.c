#include <stdio.h>
#include <math.h>


struct point
{
    double x;
    double y;
};


struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}

double distance (struct point a, struct point b);

double distance (struct point a, struct point b)
{
    double line = sqrt(fabs ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));

    return line;
}

double perimeter (struct triangle t);

double perimeter (struct triangle t)
{
    double p = (distance (t.a , t.b)) + (distance (t.a , t.c)) + (distance (t.b , t.c));

    return p;
}


int main (void)
{
    struct triangle t = (struct triangle) { {0, 0.}, {3., 0}, {0., 4.} };

    double a = area (t);

    double p = perimeter (t);
    
    double r = ((2 * a) / p) ;
    double d = distance (t.a , t.b);
    printf("distance = %d\n" , d);
 
    printf("radius = %d\n", r);
    printf("perimeter = %d\n", p);

    return 0;
}
