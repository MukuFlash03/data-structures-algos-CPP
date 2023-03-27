#include <stdio.h>

double m[10] ; double c[10];
double tout[1<<12]; double vin[1<<12];
double x[11]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
double y[11]= {5, 20, 25, 40, 53, 60, 75, 80, 93, 100, 110};
int i;

void interpolate(double x[], double y[])
{
    for (i=0; i<10; i++)
    {
        m[i] = (y[i+1] - y[i]) / (x[i+1] - x[i]);
        c[i] = y[i] - m[i]*x[i];
    }
}

double sensorVtoT(double volt)
{
    double temp = 0;
    if (volt >= x[0] && volt < x[1])
        temp = m[0]*volt + c[0];
    else if (volt >= x[1] && volt < x[2])
        temp = m[1]*volt + c[1];
    else if (volt >= x[2] && volt < x[3])
        temp = m[2]*volt + c[2];
    else if (volt >= x[3] && volt < x[4])
        temp = m[3]*volt + c[3];
    else if (volt >= x[4] && volt < x[5])
        temp = m[4]*volt + c[4];
    else if (volt >= x[5] && volt < x[6])
        temp = m[5]*volt + c[5];
    else if (volt >= x[6] && volt < x[7])
        temp = m[6]*volt + c[6];
    else if (volt >= x[7] && volt < x[8])
        temp = m[7]*volt + c[7];
    else if (volt >= x[8] && volt < x[9])
        temp = m[8]*volt + c[8];
    else if (volt >= x[9] && volt <= x[10])
        temp = m[9]*volt + c[9];

    /*
    if (volt == 10.0)
        temp = m[(int)volt-1]*volt + c[(int)volt-1];
    else    
        temp = m[(int)volt]*volt + c[(int)volt];
    */
    return temp;
}


int main()
{
    interpolate(x,y);

    for (i=0; i< (1<<12); i++)
    {   
        vin[i] = ((double)i/((1<<12)-1) * x[10]);
        tout[i] = sensorVtoT(vin[i]);
    }

    /*
    for (i=0; i< (1<<12); i++)
        printf("vin = %f \t tout = %f\n",vin[410],tout[410]);
    */


    double v_in = 0.995;
    while (v_in <= 1.1)
    {
        printf("v_in = %f \t t_in = %f\n", v_in, sensorVtoT(v_in));
        v_in += 0.001;
    }

    /*
    printf("%f\t%f\n",m[0],c[0]);
    float v_in = 0;
    scanf("%f",&v_in);
    printf("vin = %f\t t_out = %f\n",v_in, sensorVtoT(v_in));
    */


    return 0;
}