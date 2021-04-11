// Ver1.0.0 2021/04/08 k-trash

#pragma once

#include <gtk/gtk.h>
#include "route_header.hpp"

class RouteGui{
	public:
		RouteGui(void);
		bool moveRobot(bool p_flag_);
		void setWidget(void);
		
		RouteMake RouteMaker;

		GtkWidget *window;
		double robot_place[2];
		double target_place[2];
		double now_vel[2];
	private:
		void drawRobot(const double *position_);

		GtkWidget *canvas;
};
