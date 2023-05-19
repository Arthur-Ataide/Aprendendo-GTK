#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

GtkBuilder *builder;
GtkWidget *window;

void on_main_window_destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void login(char *email, char *senha, bool *lembrar){
    if((strcmp(email, "Arthur") == 0) && (strcmp(senha, "1234") == 0)){
        g_print("Usuario logado");
    }
    else{
        g_print("Email ou senha incorretos");
    }
}

void on_botao_login_clicked(GtkWidget *widget, gpointer data){
    char *email = gtk_entry_get_text(gtk_builder_get_object(builder, "email"));
    char *senha = gtk_entry_get_text(gtk_builder_get_object(builder, "senha"));
    bool *lembrar = gtk_toggle_button_get_active(gtk_builder_get_object(builder, "lembrar"));
    g_print("%d", *lembrar);

}

void on_botao_cadastrar_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_listar_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_sair_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_cad_voltar_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_cadastrar_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_listar_voltar_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_listar_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("ui.glade");

    gtk_builder_add_callback_symbols(
        builder,
        "on_botao_login_clicked",                       G_CALLBACK(on_botao_login_clicked),
        "on_main_window_destroy",                       G_CALLBACK(on_main_window_destroy),
        "on_botao_cadastrar_inicial_clicked",           G_CALLBACK(on_botao_cadastrar_inicial_clicked),
        "on_botao_listar_inicial_clicked",              G_CALLBACK(on_botao_listar_inicial_clicked),
        "on_botao_sair_inicial_clicked",                G_CALLBACK(on_botao_sair_inicial_clicked),
        "on_botao_cad_voltar_clicked",                  G_CALLBACK(on_botao_cad_voltar_clicked),
        "on_botao_cadastrar_clicked",                   G_CALLBACK(on_botao_cadastrar_clicked),
        "on_botao_listar_voltar_clicked",               G_CALLBACK(on_botao_listar_voltar_clicked),
        "on_botao_listar_clicked",                      G_CALLBACK(on_botao_listar_clicked),

    NULL);

    gtk_builder_connect_signals(builder,NULL);


    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
