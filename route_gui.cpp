// Ver1.0.0 2021/04/08 k-trash

#include <gtk/gtk.h>
#include "route_gui.hpp"
#include "route_header.hpp"

RouteGui::RouteGui(void){
	robot_place[X] = robot_place[Y] = 0.0f;
	now_vel = 0.0f;
}

gboolean RouteGui::moveRobot(gpointer user_data_){
	double robot_vel[2] = {0.0f};
	RouteMaker.searchVel(now_vel, robot_vel);
	robot_place[X] += robot_vel[X]*0.5f;
	robot_place[Y] += robot_vel[Y]*0.5f;
	
	now_vel[X] = robot_vel[X];
	now_vel[Y] = robot_vel[Y];

	drawRobot(robot_place);
}

void RouteGui::drawRobot(const double *position_){
	GdkWindow *drawable = canvas -> window;
	cairo_t *cr;

	cr = gdk_cairo_create(drawable);
	cairo_set_line_width(cr, 1.0f);

	cairo_set_source_rgb(cr, 0.0f, 0.0f, 0.0f);
	cairo_rectangle(cr, int(position_[X]+15.0f), int(position_[X]+15.0f), 30, 30);

	cairo_stroke(cr);

	cairo_destroy(cr);
}

void RouteGui::setWidget(void){
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 600, 300);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quite), NULL);
	canvas = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), canvas);
}
