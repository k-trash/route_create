// Ver1.0.0 2021/04/11 k-trash

#include <gtk/gtk.h>
#include "route_gui.hpp"
#include "route_header.hpp"

RouteGui::RouteGui(void){
	robot_place[X] = robot_place[Y] = 0.0f;
	now_vel[X] = -5.0f;
	now_vel[Y] = 0.0f;
	target_place[X] = target_place[Y] = 0.0f;
}

bool RouteGui::moveRobot(gpointer user_data_){
	double robot_vel[2] = {0.0f};
	
	RouteMaker.setDirect(target_place, robot_place);
	RouteMaker.searchVel(now_vel, robot_vel);
	robot_place[X] += robot_vel[X];
	robot_place[Y] += robot_vel[Y];
	
	now_vel[X] = robot_vel[X];
	now_vel[Y] = robot_vel[Y];

	drawRobot(robot_place);

	if(RouteMaker.getVecAbs(RouteMaker.vec_dir) < 1.0f){
		return true;
	}else{
		return false;
	}
}

void RouteGui::drawRobot(const double *position_){
	GdkWindow *drawable = canvas -> window;
	cairo_t *cr;

	cr = gdk_cairo_create(drawable);
	cairo_set_line_width(cr, 1.0f);

	cairo_set_source_rgb(cr, 0.0f, 0.0f, 0.0f);
	cairo_rectangle(cr, int(position_[X]+15.0f), int(position_[Y]+15.0f), 30, 30);

	cairo_stroke(cr);

	cairo_destroy(cr);
}

void RouteGui::setWidget(void){
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 600, 300);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	canvas = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), canvas);
}
