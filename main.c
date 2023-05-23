#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

GtkBuilder *builder;
GtkWidget *window;
GtkStack *stack;

void on_main_window_destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void mensagem(char text[100], char secondary_text[100], char icon_name[100]){

    GtkMessageDialog *mensagem_dialogo = gtk_builder_get_object(builder, "mensagem");

    g_object_set(mensagem_dialogo, "text", text, NULL);
    g_object_set(mensagem_dialogo, "secondary_text", secondary_text, NULL);
    g_object_set(mensagem_dialogo, "icon_name", icon_name, NULL);

    gtk_widget_show_all(mensagem_dialogo);
    gtk_dialog_run     (mensagem_dialogo);
    gtk_widget_hide    (mensagem_dialogo);
}

void login(char *email, char *senha, bool *lembrar){
    if((strcmp(email, "admin") == 0) && (strcmp(senha, "admin") == 0)){
        mensagem("Bem vindo", "Usuario logado com sucesso!", "emblem-default");
        gtk_stack_set_visible_child_name(stack, "view_inicial");
    }
    else{
        mensagem("Aviso", "Senha ou email incorretos!", "dialog-error");
    }
}

void on_botao_login_clicked(GtkWidget *widget, gpointer data){
    char *email = gtk_entry_get_text(gtk_builder_get_object(builder, "email"));
    char *senha = gtk_entry_get_text(gtk_builder_get_object(builder, "senha"));
    bool *lembrar = gtk_toggle_button_get_active(gtk_builder_get_object(builder, "lembrar"));
    login(email, senha, lembrar);

}

void on_botao_cadastrar_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_cadastro");
}

void on_botao_listar_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_listar");
}

void on_botao_sair_inicial_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_cad_voltar_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_inicial");
}

void on_botao_cadastrar_clicked(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void on_botao_listar_voltar_clicked(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_inicial");
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


    stack =     GTK_WIDGET(gtk_builder_get_object(builder, "stack"));
    window =    GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
