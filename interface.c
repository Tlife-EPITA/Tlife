//STRUCT TO INIT GLADE OBJECTS

typedef struct GUI
{
    GtkWindow* interface;
    GtkStack* window_pages;
    ///////////////////////////////////////
    GtkBox* main_menu;

    GtkButton* first_responder_menu;
    GtkButton* medical_staff_menu;

    ///////////////////////////////////////
    GtkBox* first_responder_menu;

    GtkEntry* systole_input_entry;
    GtkEntry* diastole_input_entry;

    GtkEntry* pulse_rate_input_entry;
    GtkEntry* respiratory_rate_input_entry;
    GtkEntry* blood_sugar_input_entry;

    GtkEntry* family_name_input_entry;
    GtkEntry* first_name_input_entry;
    GtkEntry* birth_date_input_entry;
    GtkEntry* emergency_contact_input_entry;

    //////////////////////////////////////
    GtkBox* medical_staff_menu;

    /////////////////////////////////////
    GtkBox* operation_number_menu;

    GtkEntry* operation_number_input_entry;
}GUI;

//FUNCTIONS


//MAIN
int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);
    GtkBuilder* builder = gtk_builder_new_from_file("tlife_interface.glade");




    ////////////////////////////////////////
    GtkWindow* interface = GTK_WINDOW(gtk_builder_get_object
	(builder, "interface"));
    GtkStack* window_pages = GTK_STACK(gtk_builder_get_object
	(builder, "window_pages")
    ///////////////////////////////////////
    GtkBox* main_menu = GTK_BOX(gtk_builder_get_object(builder, "main_menu"));

    GtkButton* first_responder_menu = 
	GTK_BUTTON(gtk_builder_get_object(builder,"first_responder_menu_button"));
    GtkButton* medical_staff_menu = 
	GTK_BUTTON(gtk_builder_get_object(builder,"medical_staff_menu_button"));

    ///////////////////////////////////////
    GtkBox* first_responder_menu = 
	GTK_BOX(gtk_builder_get_object(builder,"first_responder_menu"));

    GtkEntry* systole_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"systole_input_entry"));
    GtkEntry* diastole_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"diastole_input_entry"));

    GtkEntry* pulse_rate_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"pulse_rate_input_entry"));
    GtkEntry* respiratory_rate_input_entry 
	= GTK_ENTRY(gtk_builder_get_object(builder,"respiratory_rate_input_entry"));
    GtkEntry* blood_sugar_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"blood_sugar_input_entry"));

    GtkEntry* family_name_input_entry =
	GTK_ENTRY(gtk_builder_get_object(builder,"family_name_input_entry"));
    GtkEntry* first_name_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"first_name_input_entry"));
    GtkEntry* birth_date_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"birth_date_input_entry"));
    GtkEntry* emergency_contact_input_entry =
	GTK_ENTRY(gtk_builder_get_object(builder,"emergency_contact_input_entry"));

    //////////////////////////////////////
    GtkBox* medical_staff_menu = 
	GTK_BOX(gtk_builder_get_object(builder,"medical_staff_menu"));

    /////////////////////////////////////
    GtkBox* operation_number_menu = 
	GTK_BOX(gtk_builder_get_object(builder,"operation_number_menu"));

    GtkEntry* operation_number_input_entry = 
	GTK_ENTRY(gtk_builder_get_object(builder,"operation_number_input_entry"));

    gtk_main();

    return EXIT_SUCCESS;
}
