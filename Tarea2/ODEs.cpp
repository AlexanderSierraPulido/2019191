#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

void Euler(float dt);
void Leap_frog(float dt);
void RK4();

float dv_x();
float dxdt ();
float dv_y();
float dydt();

int main()
    {
    Euler(0.005,"Euler_0.005");
    Euler(0.5,"Euler_0.005");
    Leap_frog(0.005);
    
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

void Euler(float dt,string file)
    {
    float x_pas = 0.1163 , y_pas = 0.9772;
    float vx_pas = -6.35, vy_pas = 0.606;
    float t =0, t_fin = 20;
    float x_fut,y_fut,vx_fut,vy_fut;
    
    ofstream outfile;
    outfile.open(file);
    
    while(t<t_fin)
        {
        outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<t<<endl;
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
 
void Leap_frog(float dt,string file)
    {
    float x_pas = 0.1163 , y_pas = 0.9772;
    float vx_pas = -6.35, vy_pas = 0.606;
    float t =0, t_fin = 20;
    float x_fut,y_fut,vx_fut,vy_fut,x_pre,y_pre,vx_pre,vy_pre;

    ofstream outfile;
    outfile.open(file);
    
    while(t<t_fin)
        {
        outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<t<<endl;
        x_pre = vx_pas*2*dt + x_pas;
        y_pre = vy_pas*2*dt + y_pas;
        x_fut = 2*dt*vx_pas + x_pas;
        y_fut = 2*dt*vy_pas + y_pas;
        vx_fut = vx_pas + 2*dt*dv_x(x_pre,y_pre);
        vy_fut = vy_pas + 2*dt*dv_y(x_pre,y_pre);
        t = t + dt;
        x_pas = x_fut;
        y_pas = y_fut;
        vx_pas = vx_fut;
        vy_pas = vy_fut;   
        }
    outfile.close();
    }
    
void Runge_kutta()
    {
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    
    
    
    
    
    
    
    
