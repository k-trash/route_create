// Ver1.0.0 2021/04/06 k-trash

#include <cmath>
#include "route_header.hpp"

routeMake::routeMake(void){
	max_vel = max_acc = 0.0f;
	vel_dir[0] = vel_dir[1] = 0.0f;
}

bool routeMake::searchRoute(const double *now_vel_, double *next_vel_){
	double theta, next_abs;
	
	if(getVecAbs(vec_dir) == 0.0f){
		next_vel_[X] = next_vel_[Y] = 0.0f;
		return false;
	}else if(getVecAbs(now_vel_) == 0.0f){
		theta = atan2(vec_dir[X], vec_dir[Y];
	}else{
		theta = atan2(vec_dir[X], vec_dir[Y]) - getTheta(vec_dir, now_vel_);
	}

	next_vel_[X] = now_vel_[X] + (max_acc * cos(theta));
	next_vel_[Y] = now_vel_[Y] + (max_acc * cos(theta));

	next_abs = getVecAbs(next_vel_);
	if(next_abs > max_vel){
		next_vel_[X] = next_vel_[X] * max_vel / next_abs;
		next_vel_[Y] = next_vel_[Y] * max_vel / next_abs;
	}

	return true;
}

void routeMake::setMaxVel(double max_vel_){
	max_vel = max_vel_;
}

void routeMake::setMaxAcc(double max_acc_){
	max_acc = max_acc_;
}

void routeMake::setDirect(const double *target_point_, const double *now_point_){
	vec_dir[X] = target_point_[X] - now_point_[X];
	vec_dir[Y] = target_point_[Y] - now_point_[Y];
}

double routeMake::getTheta(const double *vec_1_, const double *vec_2_){
	return acos(((vec_1_[X]*vec_2_[X])+(vec_1_[Y]*vec_2_[Y]))/(getVecAbs(vec_1_)*getVecAbs(vec_2_)));
}

double routeMake::getVecAbs(const double *vec_){
	return sqrt((vec_[0]*vec_[0])+(vec_[1]*vec[1]));
}
