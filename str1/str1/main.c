//
//  main.c
//  str1
//
//  Created by Алексей Татарников on 22.12.2022.
//

#include <stdio.h>
#include <gtk/gtk.h>
#include "rs1.h"

// set timer callback and pass value to be shown as a label
// running_string function produces an array of strings to be shown and after that we just show the values by the timer

extern int errno;
RS_ARRAY* str_vector;
char **ptr1;

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
    for(int i = 0; i < str_vector->size; i++)
    {
        g_print("%s\n", str_vector->array[i]);
    }
}

gboolean
time_handler(GtkWidget *widget)
{
    
//  if (widget == NULL) return FALSE;
//
//  gtk_widget_queue_draw(widget);
//    running_string("abcd", 1, 100, 2, widget);

  
  return TRUE;
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    str_vector = split_string ("abcd");
    // TODO: check - on how to pass a pointer, update it within a function
    // check_ptr1(&ptr1);

//    sleep(2);
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    button = gtk_button_new_with_label ("Hello World");
    g_signal_connect(button, "clicked", G_CALLBACK (print_hello), NULL);
//    g_signal_connect(button, "expose-event", G_CALLBACK(on_expose_event), NULL);

    gtk_window_set_child (GTK_WINDOW (window), button);

//    g_timeout_add(200, (GSourceFunc) time_handler, (gpointer) window);

    sleep(2);
    gtk_window_present (GTK_WINDOW (window));
}

static void
shutdown (GtkApplication *app,
          gpointer user_data)
{
    g_print("I'm done\n");
    if (str_vector == NULL)
    {
        fprintf(stderr, "Can't release NULL pointer for std_vector");
    } else
    {
        free_rs(str_vector);
    }
}

int
main (int argc,
      char **argv)
{
    // TODO: !! the app is unstable for some reason, it throws exceptions 
    // when trying to run or free pointers....
    GtkApplication *app;
    int status;

    app = gtk_application_new ("run.the.string", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    g_signal_connect (app, "shutdown", G_CALLBACK (shutdown), NULL);

//    sleep(2);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    
    return status;
}
