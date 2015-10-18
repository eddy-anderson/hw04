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

double line_length (struct point a, struct point b);

double line_length (struct point a, struct point b)
{
    double l =
        sqrt (fabs ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));

    return l;
}

double perimeter (struct triangle t);
double perimeter (struct triangle t)
{
    double p =
        line_length (t.a, t.b) + line_length (t.b, t.c) + line_length (t.c,
        t.a);

    return p;
}

int main (void)
{
    struct triangle t = (struct triangle) { {2., 2.}, {-2., 1.}, {0., -3.} };

    double a = area (t);
    double p = perimeter (t);
    double r = ((2 * a) / p);

    printf ("Radius of inscribed circle = %f\n", r);


    return 0;
}
