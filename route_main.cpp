// Ver 1.0.0 2021/04/11 k-trash

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
	
	RouteCreater.target_place[X] = 100.0f;
	RouteCreater.target_place[Y] = 50.0f;

	g_timeout_add(250, (GSourceFunc)callFunc, NULL);

	gtk_widget_show_all(RouteCreater.window);
	gtk_main();

	return 0;
}

gboolean callFunc(gpointer user_data_){
	if(RouteCreater.moveRobot(NULL)){
		RouteCreater.target_place[X] = 200.0f;
		RouteCreater.target_place[Y] = 25.0f;
	}

	return TRUE;
}
