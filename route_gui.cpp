// Ver1.0.0 2021/04/06 k-trash

#include <gtk_gtk.h>
#include "route_gui.hpp"
#include "route_header.hpp"

routeGui::routeGui(void){

}

void routeGui::drawRobot(const double *position){
	GdkWindow *drawable = canvas -> window;
	cairo_t *cr;

	cr = gdk_cairo_create(drawable);
	cairo_set_line_width(cr, 1.0f);

	cairo_set_source_rgb(cr, 0.0f, 0.0f, 0.0f);
	cairo_rectangle(cr, int(position[X]+15.0f), int(position[X]+15.0f), 30, 30);

	cairo_stroke(cr);

	cairo_destroy(cr);
}

void setWdget(void){
	window = gtkwindow_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 600, 300);
	g_signal_connect(G_OBJECT(window), canvas);
}
