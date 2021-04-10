// Ver 1.0.0 2021/04/08 k-trash

#include <gtk/gtk.h>
#include <time.h>
#include "route_gui.hpp"
#include "route_header.hpp"

RouteGui RouteCreater;

gboolean callFunc(gpointer user_data_);

int main(int argc, char *argv[]){
	double places[2];

	gtk_init(&argc, &argv);

	RouteCreater.setWidget();
	RouteCreater.RouteMaker.setMaxVel(5.0f);
	RouteCreater.RouteMaker.setMaxAcc(0.50f);
	
	//places[X] = 100.0f;
	//places[Y] = 50.0f;
	RouteCreater.target_place[X] = 100.0f;
	RouteCreater.target_place[Y] = 50.0f;
	//RouteCreater.RouteMaker.setDirect(places, RouteCreater.robot_place);

	g_timeout_add(250, (GSourceFunc)callFunc, NULL);

	gtk_widget_show_all(RouteCreater.window);
	gtk_main();

	return 0;
}

gboolean callFunc(gpointer user_data_){
	RouteCreater.moveRobot(NULL);

	return TRUE;
}
