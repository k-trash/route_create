// Ver1.0.0 2021/04/08 k-trash

#include <cmath>
#include "route_header.hpp"

RouteMake::routeMake(void){
	max_vel = max_acc = 0.0f;
	vel_dir[0] = vel_dir[1] = 0.0f;
}

bool RouteMake::searchVel(const double *now_vel_, double *next_vel_){
	double next_abs;
	double acc_dir[2];

	if(getVecAbs(vec_dir) == 0.0f){
		next_vel_[X] = next_vel_[Y] = 0.0f;
		return false;
	}else if(getVecAbs(now_vel_) == 0.0f){
		acc_dir[X] = vec_dir[X]*max_acc/getVecAbs(vec_dir);
		acc_dir[Y] = vec_dir[Y]*max_acc/getVecAbs(vec_dir);
	}else{
		getDirect(now_vel_, acc_dir);
		next_abs = getVecAbs(acc_dir);
		acc_dir[X] = acc_dir[X]*max_acc/next_abs;
		acc_dir[Y] = acc_dir[Y]*max_acc/next_abs;
	}

	next_vel_[X] = now_vel_[X] + acc_dir[X];
	next_vel_[Y] = now_vel_[Y] + acc_dir[Y];

	next_abs = getVecAbs(next_vel_);
	if(next_abs > max_vel){
		next_vel_[X] = next_vel_[X] * max_vel / next_abs;
		next_vel_[Y] = next_vel_[Y] * max_vel / next_abs;
	}

	return true;
}

void RouteMake::setMaxVel(double max_vel_){
	max_vel = max_vel_;
}

void RouteMake::setMaxAcc(double max_acc_){
	max_acc = max_acc_;
}

void RouteMake::setDirect(const double *target_point_, const double *now_point_){
	vec_dir[X] = target_point_[X] - now_point_[X];
	vec_dir[Y] = target_point_[Y] - now_point_[Y];
}

void RouteMake::getDirect(const double *robot_vel_, double *acc_dir_){
	double con_mat = 1.0f/((vec_dir[X]*vec_dir[X])+(vec_dir[Y]*vec_dir[Y]));
	
	acc_dir_[X] = con_mat*((((vec_dir[X]*vec_dir[X])-(vec_dir[Y]*vec_dir[Y]))*robot_vel_[X])+(2.0f*vec_dir[X]*vec_dir[Y]*robot_vel_[Y]));
	acc_dir_[Y] = con_mat*((2.0f*vec_dir[X]*vec_dir[Y]*robot_vel_[X])-(((vec_dir[X]*vec_dir[X])-(vec_dir[Y]*vec_dir[Y]))*robot_vel_[Y]));
}

double RouteMake::getVecAbs(const double *vec_){
	return sqrt((vec_[0]*vec_[0])+(vec_[1]*vec[1]));
}
