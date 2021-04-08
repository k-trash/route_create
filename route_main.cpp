// Ver 1.0.0 2021/04/08 k-trash

#include <gtk/gtk.h>
#include "route_gui.hpp"
#include "route_header.hpp"

int main(int argc, char *argv[]){
	double places[2];
	RouteGui RouteCreater;

	gtk_init(&argc, &argv);

	RouteCreater.setWidget();
	RouteCreater.RouteMaker.setMaxVel(5.0f);
	RouteCreater.RouteMaker.setMaxAcc(2.0f);
	
	places[X] = 100.0f;
	places[Y] = 50.0f;
	RouteCreater.RouteMaker.setDirect(places, RouteCreater.robot_place);

	g_time_add(500, (GSourceFunc)RouteCreater.moveRobot, NULL);

	gtk_widget_shoe_all(RouteCreater.window);
	gtk_main();

	return 0;
}
