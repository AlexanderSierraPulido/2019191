#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

void Euler(float dt,string file);
void Leap_frog(float dt,string file);
void Runge_kutta(float dt,string file);

float dv_x(float x,float y);
float dv_y(float x,float y);

float G = 1.982*pow(10,-29);
float M = 1.989*pow(10,30);
float m = 5.972*pow(10,24);

int main()
    {
    Euler(0.005,"Euler_0.005.txt");
    Euler(0.0025,"Euler_0.0025.txt");
    Euler(0.0005,"Euler_0.0005.txt");
    Leap_frog(0.005,"Leap_0.005.txt");
    Leap_frog(0.0025,"Leap_0.0025.txt");
    Leap_frog(0.0005,"Leap_0.0005.txt");
    Runge_kutta(0.005,"RK_0.005.txt");
    Runge_kutta(0.0025,"RK_0.0025.txt");
    Runge_kutta(0.0005,"RK_0.0005.txt");

    return 0;
    }

float dv_x(float x,float y)
    {
    float r = sqrt(pow(x,2)+pow(y,2));
    return -G*M*x/pow(r,3);
    }

float dv_y(float x,float y)
    {

    float r = sqrt(pow(x,2)+pow(y,2));
    return -G*M*y/pow(r,3);
    }

void Euler(float dt,string file)
    {
    float x_pas = 0.1163 , y_pas = 0.9772;
    float vx_pas = -6.35, vy_pas = 0.606;
    float t =0, t_fin = 20;
    float x_fut,y_fut,vx_fut,vy_fut;
    float L,E;
    
    ofstream outfile;
    outfile.open(file);
    
    while(t<t_fin)
        {
        L = (pow(vx_pas,2)+pow(vy_pas,2))*m*sqrt(pow(x_pas,2)+pow(y_pas,2));
        E = 0.5*m*(pow(vx_pas,2)+pow(vy_pas,2)) - G*M*m/sqrt(pow(x_pas,2)+pow(y_pas,2));
        outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<L<<","<<E<<","<<t<<endl;
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
    float L,E;

    ofstream outfile;
    outfile.open(file);
    
    while(t<t_fin)
        {
        L = (pow(vx_pas,2)+pow(vy_pas,2))*m*sqrt(pow(x_pas,2)+pow(y_pas,2));
        E = 0.5*m*(pow(vx_pas,2)+pow(vy_pas,2)) - G*M*m/sqrt(pow(x_pas,2)+pow(y_pas,2));
        outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<L<<","<<E<<","<<t<<endl;
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
    
void Runge_kutta(float dt,string file)
    {
    float x_pas = 0.1163 , y_pas = 0.9772;
    float vx_pas = -6.35, vy_pas = 0.606;
    float t =0, t_fin = 20;
    float x_fut,y_fut,vx_fut,vy_fut;
    float k1_x,k2_x,k3_x,k4_x;
    float k1_y,k2_y,k3_y,k4_y;
    float k1_vx,k2_vx,k3_vx,k4_vx;
    float k1_vy,k2_vy,k3_vy,k4_vy;
    float L,E;
    
    ofstream outfile;
    outfile.open(file);
    
    while(t<t_fin)
        {
        L = (pow(vx_pas,2)+pow(vy_pas,2))*m*sqrt(pow(x_pas,2)+pow(y_pas,2));
        E = 0.5*m*(pow(vx_pas,2)+pow(vy_pas,2)) - G*M*m/sqrt(pow(x_pas,2)+pow(y_pas,2));
        outfile<<x_pas<<","<<y_pas<<","<<vx_pas<<","<<vy_pas<<","<<L<<","<<E<<","<<t<<endl;
        
        k1_x = vx_pas;
        k1_y = vy_pas;
        k1_vx = dv_x(x_pas,y_pas);
        k1_vy = dv_y(x_pas,y_pas);        

        x_fut = x_pas + (dt/2.)*k1_x;
        y_fut = y_pas + (dt/2.)*k1_y;
        vx_fut = vx_pas + (dt/2.)*k1_vx;
        vy_fut = vy_pas + (dt/2.)*k1_vy;
        k2_x = vx_fut;
        k2_y = vy_fut;
        k2_vx = dv_x(x_fut,y_fut);
        k2_vy = dv_y(x_fut,y_fut);
        
        x_fut = x_pas + (dt/2.)*k2_x;
        y_fut = y_pas + (dt/2.)*k2_y;
        vx_fut = vx_pas + (dt/2.)*k2_vx;
        vy_fut = vy_pas + (dt/2.)*k2_vy;
        k3_x = vx_fut;
        k3_y = vy_fut;
        k3_vx = dv_x(x_fut,y_fut);
        k3_vy = dv_y(x_fut,y_fut);
        
        x_fut = x_pas + (dt/2.)*k3_x;
        y_fut = y_pas + (dt/2.)*k3_y;
        vx_fut = vx_pas + (dt/2.)*k3_vx;
        vy_fut = vy_pas + (dt/2.)*k3_vy;
        k4_x = vx_fut;
        k4_y = vy_fut;
        k4_vx = dv_x(x_fut,y_fut);
        k4_vy = dv_y(x_fut,y_fut);
        
        x_fut = x_pas + dt*(k1_x + 2*k2_x + 2*k3_x + k4_x)/6.;
        y_fut = y_pas + dt*(k1_y + 2*k2_y + 2*k3_y + k4_y)/6.;
        vx_fut = vx_pas + dt*(k1_vx + 2*k2_vx + 2*k3_vx + k4_vx)/6.;
        vy_fut = vy_pas + dt*(k1_vy + 2*k2_vy + 2*k3_vy + k4_vy)/6.;
        t = t+dt;
        x_pas = x_fut;
        y_pas = y_fut;
        vx_pas = vx_fut;
        vy_pas = vy_fut;     
        }
    outfile.close();
    }

