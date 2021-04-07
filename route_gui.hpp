// Ver1.0.0 2021/04/07 k-trash

#pragma once

#include <gtk/gtk.h>
#include "route_header.hpp"

class RouteGui{
	public:
		routeGui(void);
		void moveRobot(double max_vel_, double max_acc_);

		RouteMake RouteMaker;
	private:
		void drawRobot(const double *position_);
		void setWidget(void);

		GtkWidget *window;
		GtkWidget *canvas;
};
