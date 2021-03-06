// Ver1.0.0 2021/04/08 k-trash

#pragma once

constexpr bool X = 0;
constexpr bool Y = 1;

class RouteMake{
	public:
		RouteMake(void);
		bool searchVel(const double *now_vel_, double *next_vel_);
		void setMaxVel(double max_vel_);
		void setMaxAcc(double max_acc_);
		void setDirect(const double *target_point_, const double *now_point_);
		double getVecAbs(const double *vec_);
		
		double vec_dir[2];
	private:
		void getDirect(const double *robot_vel_, double *acc_dir);
		double getVecInner(const double *vec_1_, const double *vec_2_);

		double max_vel, max_acc;
};
