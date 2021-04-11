// Ver 1.0.0 2021/04/11 k-trash

#include <gtk/gtk.h>
#include <time.h>
#include "route_gui.hpp"
#include "route_header.hpp"

RouteGui RouteCreater;

double positions[4][2] = {{185.0f, 30.0f}, { 250.0f, 60.0f}, {285.0f, 88.0f}, {320.0f, 95.0f}};

gboolean callFunc(gpointer user_data_);

int main(int argc, char *argv[]){
	double places[2];

	gtk_init(&argc, &argv);

	RouteCreater.setWidget();
	RouteCreater.RouteMaker.setMaxVel(5.0f);
	RouteCreater.RouteMaker.setMaxAcc(0.50f);
	
	RouteCreater.target_place[X] = positions[0][X];
	RouteCreater.target_place[Y] = positions[0][Y];

	g_timeout_add(100, (GSourceFunc)callFunc, NULL);

	gtk_widget_show_all(RouteCreater.window);
	gtk_main();

	return 0;
}

gboolean callFunc(gpointer user_data_){
	static int count = 0;
	bool change_flag = false;

	if(count < 3){
		change_flag = RouteCreater.moveRobot(false);
	}else{
		change_flag = RouteCreater.moveRobot(true);
	}

	if(change_flag){
		count++;
		if(count >= 3){
			count = 3;
		}
		RouteCreater.target_place[X] = positions[count][X];
		RouteCreater.target_place[Y] = positions[count][Y];
	}

	return TRUE;
}
