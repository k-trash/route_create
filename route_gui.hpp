// Ver1.0.0 2021/04/06 k-trash

#pragma once

#include <gtk/gtk.h>
#include "route_header.hpp"

class routeGui{
	public:
		routeGui(void);
	private:
		void drawRobot(const double *position);
		void setWidget(void);

		GtkWidget *window;
		GtkWidget *canvas;
};
