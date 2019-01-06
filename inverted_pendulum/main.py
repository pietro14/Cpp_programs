from math import *


# physical constants and parameters

g  = 9.80252       # g. acceleration     [m/s^2 ]

m  = 0.050         # mass of pendulum    [Kg]
L  = 0.1#0.10          # pendulum length     [m] 

# I =              # momentum of inertia [Kg*m^2]  
k = 2              # friction coefficient [1/s]    

dt = 1e-7          # time unit           [s]   
Delta_t = 1e-5	   # time sensibility of Arduino [s]
T  = 4             # simul. duration     [s]
N  = int(T/dt)          # number of steps 

#a_0 =  g + 1e-2   	  # [m/s^2]  acceleration parameter

# initial conditions
phi_0 	= 0

theta_0 = (0.1)*pi/180    # [rad]         (theta = 0 means upright position)   
#theta_0 =  (0 + 178)*pi/180    # [rad]         (theta = pi means upright position)


omega_0 = (0)*pi/180       # [rad/s]
alpha_0 = 0         	  # [rad/s^2]
# simulation 

theta = theta_0
omega = omega_0

print "t [s]	theta [deg]    omega [deg/s]	alpha_w [deg/s^2] "
for i in range(0,N-1):
	t = i*dt
	
	if (i % 1000) == 0 :	
		a = (g+0.1)*tan(theta_0) #+ sqrt(g*L)*omega_0          #*tan(theta_0)             #	a = a_0*tan(theta_0)	
	alpha_f = - k*omega     
		
	alpha_w =   g * sin(theta_0) / L    # if theta = 0  is upright position
#	alpha_w = - g * sin(theta_0) / L    # if theta = pi is upright position
	
#	alpha   = alpha_w + alpha_f	# NO INTERVET PENDULUM

	phi_0 = - atan(a/g) + theta_0
	alpha   = sqrt(g**2+a**2)*sin(phi_0)/L 	+ alpha_f # INVERTED PENDULUM
 
	omega = omega_0 + alpha * dt
	theta = theta_0 + omega_0 * dt + 0.5 * alpha * dt**2

   	theta_0 = theta
	omega_0 = omega
	
	print t, theta*180/pi , omega*180/pi , alpha_w*180/pi
 

