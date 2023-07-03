#pragma once

namespace MkFile {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Summary for gui
	/// </summary>
	public ref class gui : public System::Windows::Forms::Form
	{
	public:
		gui(void);

	protected:
		~gui();

	private:
		System::Windows::Forms::Label^ title_lbl;
		System::Windows::Forms::Label^ file_name_lbl;
		System::Windows::Forms::RichTextBox^ file_name_input;
		System::Windows::Forms::Label^ file_ext_lbl;
		System::Windows::Forms::ComboBox^ file_extension_input;
		System::Windows::Forms::ListView^ file_queue_list;
		System::Windows::Forms::ListViewItem^ new_list_item;
		System::Windows::Forms::Button^ create_files_btn;
		System::Windows::Forms::Button^ done_btn;
		System::Windows::Forms::Label^ file_path_lbl;
		System::Windows::Forms::RichTextBox^ file_path_input;
		System::Windows::Forms::Button^ choose_path_btn;
		System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
		System::ComponentModel::IContainer^ components;

		System::String^ file_creation_path = nullptr;
		System::String^ DEFAULT_FILE_CREATION_PATH = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments) + "\\MkFilev1.0\\"); // Remove in release version.
		System::String^ file_name = nullptr;
		System::String^ DEFAULT_FILE_NAME = "File";
		System::String^ DEFAULT_FILE_EXT = ".txt";
		System::String^ file_ext = nullptr;
		static int DEFAULT_FILE_COUNT = 0;
		static int SAME_FILE_COUNT = 1;
		cli::array<System::String^>^ files_to_create;
		System::IO::File^ creation_file;

		System::Windows::Forms::Button^ add_file_btn;
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ file_menu;
		System::Windows::Forms::ToolStripMenuItem^ view_menu;
		System::Windows::Forms::ToolStripMenuItem^ view_menu_theme;
		System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ help_menu;
		System::Windows::Forms::ToolStripMenuItem^ help_menu_view_help;
		System::Windows::Forms::ToolStripMenuItem^ help_menu_feedback;
		System::Windows::Forms::ToolStripMenuItem^ help_menu_technical_support;
		System::Windows::Forms::ToolStripMenuItem^ help_menu_about;
		System::Windows::Forms::ToolStripMenuItem^ file_menu_restart;
		System::Windows::Forms::ToolStripMenuItem^ file_menu_exit;
		System::Windows::Forms::ToolStripMenuItem^ theme_menu_light;
		System::Windows::Forms::ToolStripMenuItem^ theme_menu_dark;
		System::Windows::Forms::ColumnHeader^ file_column_header;
		System::Windows::Forms::Label^ output_lbl;

		System::Windows::Forms::ToolTip^ output_lbl_tooltip;
		System::Windows::Forms::ToolTip^ choose_path_btn_tooltip;
		System::Windows::Forms::ToolTip^ add_file_btn_tooltip;
		System::Windows::Forms::ToolTip^ create_btn_tooltip;
		System::Windows::Forms::ToolTip^ done_btn_tooltip;
		System::Windows::Forms::Button^ clear_queue_btn;

		// Helper Methods

		void out(System::String^ text);

		void InitializeComponent(void);

		void choose_path_btn_Click(System::Object^ sender, System::EventArgs^ e);

		void done_btn_click(System::Object^ sender, System::EventArgs^ e);

		void on_file_name_input_text_changed(System::Object^ sender, System::EventArgs^ e);

		void on_file_extension_input_text_changed(System::Object^ sender, System::EventArgs^ e);

		void on_file_path_input_text_changed(System::Object^ sender, System::EventArgs^ e);

		void on_add_file_btn_click(System::Object^ sender, System::EventArgs^ e);

		void create_files_btn_click(System::Object^ sender, System::EventArgs^ e);

		void on_gui_shown(System::Object^ sender, System::EventArgs^ e);

		void on_file_menu_restart_click(System::Object^ sender, System::EventArgs^ e);

		void on_file_menu_exit_click(System::Object^ sender, System::EventArgs^ e);

		void on_theme_menu_light_click(System::Object^ sender, System::EventArgs^ e);

		void on_theme_menu_dark_click(System::Object^ sender, System::EventArgs^ e);

		void on_clear_btn_cick(System::Object^ sender, System::EventArgs^ e);
	};
}
