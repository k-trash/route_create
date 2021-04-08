// Ver1.0.0 2021/04/08 k-trash

#pragma once

#include <gtk/gtk.h>
#include "route_header.hpp"

class RouteGui{
	public:
		routeGui(void);
		gboolean moveRobot(gpointer user_data_);

		RouteMake RouteMaker;

		double robot_place[2];
		double now_vel;
	private:
		void drawRobot(const double *position_);
		void setWidget(void);

		GtkWidget *window;
		GtkWidget *canvas;
};
