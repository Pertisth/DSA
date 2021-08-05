#include <iostream>
#include <iomanip>


using namespace std;

float cal_Angle(int h,double m)
{
  	if (h <0 || m < 0 || h >12 || m > 60)
    {
      return 0.00;
    }
    if(h==12)
    {
        h=0;
    }
    if(m==60)
    {
        m=0;
    }
    int hour_angle = 0.5*(h*60+m);
    int min_angle = 6*m;

    int angle = abs(hour_angle - min_angle);

    int angle2 = 360-angle;

    if(angle > angle2)
    {
        return angle2;
    }
    else
    {
        return angle;
    }

}

int main()
{
    int r;
    float l;
    float formula;
    cin >> r;
    cin >> l;
    if(r>12)
    {
        formula = 0.0666666666666667*l;
    }
    else if(r<=12)
    {
        formula = 0.0333333333333333*l;
    }
    int h=formula;

    double m = (formula - h)*60;

    float angle = cal_Angle(h,m);
    printf("%.2f",angle);
    return 0;


}
