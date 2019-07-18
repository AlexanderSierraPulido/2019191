#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

void Euler();
void Leap_frog();
void RK4();

float dv_x();
float dxdt ();
float dv_y();
float dydt();

int main()
    {
    Euler();
    return 0;
    }

float dv_x(float x,float y)
    {
    float G = 1.982*pow(10,-29);
    float M = 1.989*pow(10,30);
    float r = sqrt(pow(x,2)+pow(y,2));
    return -G*M*x/pow(r,3);
    }

float dv_y(float x,float y)
    {
    float G = 1.982*pow(10,-29);
    float M = 1.989*pow(10,30);
    float r = sqrt(pow(x,2)+pow(y,2));
    return -G*M*y/pow(r,3);
    }

void Euler()a
    {
    float x_pas = 0.1163 , y_pas = 0.9772;
    float vx_pas = -6.35, vy_pas = 0.606;
    float dt = 0.005 , t =0;
    float x_fut,y_fut,vx_fut,vy_fut;
    
    ofstream outfile;
    outfile.open("Euler.txt");
    
    for(int i =0;i<100000;i++)
        {
        if(i%1000 == 0)
            {
            outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<t<<endl;
            }
        x_fut = x_pas + dt*vx_pas;
        y_fut = y_pas + dt*vy_pas;
        vx_fut = vx_pas + dt*dv_x(x_pas,y_pas);
        vy_fut = vy_pas + dt*dv_y(x_pas,y_pas);
        t = t + dt;
        x_pas = x_fut;
        y_pas = y_fut;
        vx_pas = vx_fut;
        vy_pas = vy_fut;        
        
        }
    outfile.close();
    }
