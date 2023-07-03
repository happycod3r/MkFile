#include "gui.h"


MkFile::gui::gui(void) {
	this->InitializeComponent();
}

MkFile::gui::~gui() {
	if (components) {
		delete components;
	}
}

// Helper Methods

void MkFile::gui::out(System::String^ text) {
	this->output_lbl->Text = text;
}

void MkFile::gui::InitializeComponent(void) {
	this->components = (gcnew System::ComponentModel::Container());
	this->title_lbl = (gcnew System::Windows::Forms::Label());
	this->file_name_lbl = (gcnew System::Windows::Forms::Label());
	this->file_name_input = (gcnew System::Windows::Forms::RichTextBox());
	this->file_ext_lbl = (gcnew System::Windows::Forms::Label());
	this->file_extension_input = (gcnew System::Windows::Forms::ComboBox());
	this->file_queue_list = (gcnew System::Windows::Forms::ListView());
	this->file_column_header = (gcnew System::Windows::Forms::ColumnHeader());
	this->create_files_btn = (gcnew System::Windows::Forms::Button());
	this->done_btn = (gcnew System::Windows::Forms::Button());
	this->file_path_lbl = (gcnew System::Windows::Forms::Label());
	this->file_path_input = (gcnew System::Windows::Forms::RichTextBox());
	this->choose_path_btn = (gcnew System::Windows::Forms::Button());
	this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
	this->add_file_btn = (gcnew System::Windows::Forms::Button());
	this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
	this->file_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->file_menu_restart = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->file_menu_exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->view_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->view_menu_theme = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->theme_menu_light = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->theme_menu_dark = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->help_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->help_menu_view_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->help_menu_feedback = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->help_menu_technical_support = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->help_menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->output_lbl = (gcnew System::Windows::Forms::Label());
	this->output_lbl_tooltip = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->choose_path_btn_tooltip = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->add_file_btn_tooltip = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->create_btn_tooltip = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->done_btn_tooltip = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->clear_queue_btn = (gcnew System::Windows::Forms::Button());

	this->menuStrip1->SuspendLayout();
	this->SuspendLayout();
	// 
	// title_lbl
	// 
	this->title_lbl->AutoSize = true;
	this->title_lbl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->title_lbl->Font = (gcnew System::Drawing::Font(L"Consolas", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->title_lbl->Location = System::Drawing::Point(240, 43);
	this->title_lbl->Name = L"title_lbl";
	this->title_lbl->Size = System::Drawing::Size(111, 43);
	this->title_lbl->TabIndex = 0;
	this->title_lbl->Text = L"MkFile";
	this->title_lbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;

	// 
	// file_name_lbl
	//
	this->file_name_lbl->AutoSize = true;
	this->file_name_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->file_name_lbl->Location = System::Drawing::Point(40, 115);
	this->file_name_lbl->Name = L"file_name_lbl";
	this->file_name_lbl->Size = System::Drawing::Size(74, 20);
	this->file_name_lbl->TabIndex = 1;
	this->file_name_lbl->Text = L"File Name:";
	// 
	// file_name_input
	// 
	this->file_name_input->BackColor = System::Drawing::SystemColors::Window;
	this->file_name_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->file_name_input->Location = System::Drawing::Point(120, 115);
	this->file_name_input->Multiline = false;
	this->file_name_input->Name = L"file_name_input";
	this->file_name_input->Size = System::Drawing::Size(190, 20);
	this->file_name_input->TabIndex = 2;
	this->file_name_input->Text = L"";
	this->file_name_input->TextChanged += gcnew System::EventHandler(this, &gui::on_file_name_input_text_changed);
	// 
	// file_ext_lbl
	// 
	this->file_ext_lbl->AutoSize = true;
	this->file_ext_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->file_ext_lbl->Location = System::Drawing::Point(40, 156);
	this->file_ext_lbl->Name = L"file_ext_lbl";
	this->file_ext_lbl->Size = System::Drawing::Size(99, 20);
	this->file_ext_lbl->TabIndex = 3;
	this->file_ext_lbl->Text = L"File Extension:";
	// 
	// file_extension_input
	// 
	this->file_extension_input->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->file_extension_input->FormattingEnabled = true;
	this->file_extension_input->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
		L".txt", L".html", L".xml",
			L".css", L".less", L".js",
			L".php", L".sql", L".mysql",
			L".py", L".java", L".cpp",
			L".hpp", L".h", L".sh",
			L".zsh"
	});
	this->file_extension_input->Location = System::Drawing::Point(140, 155);
	this->file_extension_input->Name = L"file_extension_input";
	this->file_extension_input->Size = System::Drawing::Size(170, 21);
	this->file_extension_input->TabIndex = 4;
	this->file_extension_input->Text = L".txt";
	this->file_extension_input->TextChanged += gcnew System::EventHandler(this, &gui::on_file_extension_input_text_changed);
	// 
	// file_queue_list
	// 
	this->file_queue_list->Alignment = System::Windows::Forms::ListViewAlignment::Left;
	this->file_queue_list->BackColor = System::Drawing::SystemColors::Window;
	this->file_queue_list->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->file_queue_list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->file_column_header });
	this->file_queue_list->GridLines = true;
	this->file_queue_list->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
	this->file_queue_list->Location = System::Drawing::Point(318, 115);
	this->file_queue_list->Name = L"file_queue_list";
	this->file_queue_list->ShowItemToolTips = true;
	this->file_queue_list->Size = System::Drawing::Size(260, 99);
	this->file_queue_list->TabIndex = 5;
	this->file_queue_list->UseCompatibleStateImageBehavior = false;
	this->file_queue_list->View = System::Windows::Forms::View::Details;
	// 
	// file_column_header
	// 
	this->file_column_header->Text = L"File Queue";
	this->file_column_header->Width = 164;
	// 
	// create_files_btn
	// 
	this->create_files_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->create_files_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->create_files_btn->Location = System::Drawing::Point(439, 288);
	this->create_files_btn->Name = L"create_files_btn";
	this->create_files_btn->Size = System::Drawing::Size(77, 29);
	this->create_files_btn->TabIndex = 6;
	this->create_files_btn->Text = L"Create";
	this->create_btn_tooltip->SetToolTip(this->create_files_btn, L"Click the \"Create\" button to create all of the files \r\nadded to the file queue.");
	this->create_files_btn->UseVisualStyleBackColor = true;
	this->create_files_btn->Click += gcnew System::EventHandler(this, &gui::create_files_btn_click);
	// 
	// done_btn
	// 
	this->done_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->done_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->done_btn->Location = System::Drawing::Point(522, 288);
	this->done_btn->Name = L"done_btn";
	this->done_btn->Size = System::Drawing::Size(75, 29);
	this->done_btn->TabIndex = 7;
	this->done_btn->Text = L"Done";
	this->done_btn_tooltip->SetToolTip(this->done_btn, L"Click the \"Done\" button to exit the program.\r\n");
	this->done_btn->UseVisualStyleBackColor = true;
	this->done_btn->Click += gcnew System::EventHandler(this, &gui::done_btn_click);
	// 
	// file_path_lbl
	// 
	this->file_path_lbl->AutoSize = true;
	this->file_path_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->file_path_lbl->Location = System::Drawing::Point(40, 195);
	this->file_path_lbl->Name = L"file_path_lbl";
	this->file_path_lbl->Size = System::Drawing::Size(66, 20);
	this->file_path_lbl->TabIndex = 8;
	this->file_path_lbl->Text = L"File Path:";
	// 
	// file_path_input
	// 
	this->file_path_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->file_path_input->Location = System::Drawing::Point(110, 195);
	this->file_path_input->Multiline = false;
	this->file_path_input->Name = L"file_path_input";
	this->file_path_input->Size = System::Drawing::Size(200, 20);
	this->file_path_input->TabIndex = 9;
	this->file_path_input->Text = L"";
	this->file_path_input->TextChanged += gcnew System::EventHandler(this, &gui::on_file_path_input_text_changed);
	// 
	// choose_path_btn
	// 
	this->choose_path_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->choose_path_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->choose_path_btn->Location = System::Drawing::Point(110, 221);
	this->choose_path_btn->Name = L"choose_path_btn";
	this->choose_path_btn->Size = System::Drawing::Size(85, 28);
	this->choose_path_btn->TabIndex = 10;
	this->choose_path_btn->Text = "Path";
	this->choose_path_btn_tooltip->SetToolTip(this->choose_path_btn, L"Click the \"Choose Path\" button to choose which \r\npath you would like to have the "
		L"current file that your \r\nadding saved to. ");
	this->choose_path_btn->UseVisualStyleBackColor = true;
	this->choose_path_btn->Click += gcnew System::EventHandler(this, &gui::choose_path_btn_Click);
	// 
	// add_file_btn
	// 
	this->add_file_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->add_file_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->add_file_btn->Location = System::Drawing::Point(200, 221);
	this->add_file_btn->Name = L"add_file_btn";
	this->add_file_btn->Size = System::Drawing::Size(85, 28);
	this->add_file_btn->TabIndex = 11;
	this->add_file_btn->Text = L"Add File";
	this->add_file_btn_tooltip->SetToolTip(this->add_file_btn, L"Click the \"Add File To Queue\" button to add\r\nthe current file that you want to cr"
		L"eate to the \r\nfile queue.");
	this->add_file_btn->UseVisualStyleBackColor = true;
	this->add_file_btn->Click += gcnew System::EventHandler(this, &gui::on_add_file_btn_click);
	// 
	// menuStrip1
	// 
	this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
	this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
		this->file_menu, this->view_menu,
			this->toolsToolStripMenuItem, this->help_menu
	});
	this->menuStrip1->Location = System::Drawing::Point(0, 0);
	this->menuStrip1->Name = L"menuStrip1";
	this->menuStrip1->Size = System::Drawing::Size(609, 24);
	this->menuStrip1->TabIndex = 13;
	this->menuStrip1->Text = L"menuStrip1";
	// 
	// file_menu
	// 
	this->file_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
		this->file_menu_restart,
			this->file_menu_exit
	});
	this->file_menu->Name = L"file_menu";
	this->file_menu->Size = System::Drawing::Size(37, 20);
	this->file_menu->Text = L"File";

	// 
			// file_menu_restart
			// 
	this->file_menu_restart->Name = L"file_menu_restart";
	this->file_menu_restart->Size = System::Drawing::Size(110, 22);
	this->file_menu_restart->Text = L"Restart";
	this->file_menu_restart->Click += gcnew System::EventHandler(this, &gui::on_file_menu_restart_click);
	// 
	// file_menu_exit
	// 
	this->file_menu_exit->Name = L"file_menu_exit";
	this->file_menu_exit->Size = System::Drawing::Size(110, 22);
	this->file_menu_exit->Text = L"Exit";
	this->file_menu_exit->Click += gcnew System::EventHandler(this, &gui::on_file_menu_exit_click);
	// 
	// view_menu
	// 
	this->view_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->view_menu_theme });
	this->view_menu->Name = L"view_menu";
	this->view_menu->Size = System::Drawing::Size(44, 20);
	this->view_menu->Text = L"View";
	// 
	// view_menu_theme
	// 
	this->view_menu_theme->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
		this->theme_menu_light,
			this->theme_menu_dark
	});
	this->view_menu_theme->Name = L"view_menu_theme";
	this->view_menu_theme->Size = System::Drawing::Size(111, 22);
	this->view_menu_theme->Text = L"Theme";

	// 
	// help_menu
	// 
	this->help_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
		this->help_menu_view_help,
			this->help_menu_feedback, this->help_menu_technical_support, this->help_menu_about
	});
	this->help_menu->Name = L"help_menu";
	this->help_menu->Size = System::Drawing::Size(44, 20);
	this->help_menu->Text = L"Help";
	// 
	// help_menu_view_help
	// 
	this->help_menu_view_help->Name = L"help_menu_view_help";
	this->help_menu_view_help->Size = System::Drawing::Size(169, 22);
	this->help_menu_view_help->Text = L"View Help";
	// 
	// help_menu_feedback
	// 
	this->help_menu_feedback->Name = L"help_menu_feedback";
	this->help_menu_feedback->Size = System::Drawing::Size(169, 22);
	this->help_menu_feedback->Text = L"FeedBack";
	// 
	// help_menu_technical_support
	// 
	this->help_menu_technical_support->Name = L"help_menu_technical_support";
	this->help_menu_technical_support->Size = System::Drawing::Size(169, 22);
	this->help_menu_technical_support->Text = L"Technical Support";
	// 
	// help_menu_about
	// 
	this->help_menu_about->Name = L"help_menu_about";
	this->help_menu_about->Size = System::Drawing::Size(169, 22);
	this->help_menu_about->Text = L"About MkFile1.0";
	// 
	// output_lbl
	// 
	this->output_lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	this->output_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->output_lbl->Location = System::Drawing::Point(10, 288);
	this->output_lbl->Name = L"output_lbl";
	this->output_lbl->Size = System::Drawing::Size(423, 29);
	this->output_lbl->TabIndex = 15;
	this->output_lbl->Text = L"Add files to begin";
	this->output_lbl_tooltip->SetToolTip(this->output_lbl, L"Output text is displayed here.\r\n");
	// 
	// clear_queue_btn
	// 
	this->clear_queue_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->clear_queue_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->clear_queue_btn->Location = System::Drawing::Point(318, 221);
	this->clear_queue_btn->Name = L"clear_queue_btn";
	this->clear_queue_btn->Size = System::Drawing::Size(260, 28);
	this->clear_queue_btn->TabIndex = 16;
	this->clear_queue_btn->Text = L"Clear Queue";
	// 
	// gui
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::DarkGray;
	this->ClientSize = System::Drawing::Size(609, 329);
	this->Controls->Add(this->clear_queue_btn);
	this->Controls->Add(this->output_lbl);
	this->Controls->Add(this->menuStrip1);
	this->Controls->Add(this->add_file_btn);
	this->Controls->Add(this->choose_path_btn);
	this->Controls->Add(this->file_path_input);
	this->Controls->Add(this->file_path_lbl);
	this->Controls->Add(this->done_btn);
	this->Controls->Add(this->create_files_btn);
	this->Controls->Add(this->file_queue_list);
	this->Controls->Add(this->file_extension_input);
	this->Controls->Add(this->file_ext_lbl);
	this->Controls->Add(this->file_name_input);
	this->Controls->Add(this->file_name_lbl);
	this->Controls->Add(this->title_lbl);
	this->MainMenuStrip = this->menuStrip1;
	this->menuStrip1->BackColor = System::Drawing::Color::Gray;
	this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
	this->Name = L"gui";
	this->Tag = L"   ";
	this->Text = L"MkFile v1.0";
	this->Shown += gcnew System::EventHandler(this, &gui::on_gui_shown);
	this->menuStrip1->ResumeLayout(false);
	this->menuStrip1->PerformLayout();
	this->ResumeLayout(false);

	this->PerformLayout();
	this->clear_queue_btn->UseVisualStyleBackColor = true;
	this->clear_queue_btn->Click += gcnew System::EventHandler(this, &gui::on_clear_btn_cick);


}

void MkFile::gui::choose_path_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	folderBrowserDialog1->ShowDialog();
	file_path_input->Text = folderBrowserDialog1->SelectedPath;
	file_creation_path = folderBrowserDialog1->SelectedPath;
}

void MkFile::gui::done_btn_click(System::Object^ sender, System::EventArgs^ e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Are you sure you want to exit?", "Exit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
		Application::Exit();
	}
}

void MkFile::gui::on_file_name_input_text_changed(System::Object^ sender, System::EventArgs^ e) {
	file_name = file_name_input->Text;
	out(file_name_input->Text);
}

void MkFile::gui::on_file_extension_input_text_changed(System::Object^ sender, System::EventArgs^ e) {
	file_ext = file_extension_input->Text;
	out(output_lbl->Text + file_extension_input->Text);
}

void MkFile::gui::on_file_path_input_text_changed(System::Object^ sender, System::EventArgs^ e) {
	file_creation_path = file_path_input->Text;
	out(file_path_input->Text + "\\" + output_lbl->Text);
}

void MkFile::gui::on_add_file_btn_click(System::Object^ sender, System::EventArgs^ e) {
	new_list_item = gcnew ListViewItem();
	String^ full_file_name;
	if (!String::IsNullOrEmpty(file_name_input->Text))
	{
		file_name = file_name_input->Text;
	}
	if (String::IsNullOrEmpty(file_ext))
	{
		file_ext = DEFAULT_FILE_EXT;
	}
	if (String::IsNullOrEmpty(file_name))
	{
		DEFAULT_FILE_COUNT += 1;
		file_name = DEFAULT_FILE_NAME + DEFAULT_FILE_COUNT;
	}

	if (String::IsNullOrEmpty(file_creation_path))
	{
		file_creation_path = DEFAULT_FILE_CREATION_PATH;
	}

	full_file_name = file_creation_path + "\\" + file_name + file_ext;
	for (int index = 0; index < file_queue_list->Items->Count; index++)
	{
		if (full_file_name == file_queue_list->Items[index]->Text)
		{
			full_file_name = file_creation_path + "\\" + file_name + SAME_FILE_COUNT + file_ext;
			SAME_FILE_COUNT += 1;
		}
	}
	out("Added to queue: " + full_file_name);

	file_queue_list->Items->Add(full_file_name);
	file_name = nullptr;
}

void MkFile::gui::create_files_btn_click(System::Object^ sender, System::EventArgs^ e) {

	int queue_count = file_queue_list->Items->Count;
	files_to_create = (gcnew array<String^>(queue_count));

	for (int index = 0; index < queue_count; index++)
	{
		files_to_create[index] = file_queue_list->Items[index]->Text;
		creation_file->Create(files_to_create[index])->Close();
		file_queue_list->Items[index]->Text = "Created file.";
	}
	file_queue_list->Items->Clear();
	SAME_FILE_COUNT = 1;
	DEFAULT_FILE_COUNT = 0;
}

void MkFile::gui::on_gui_shown(System::Object^ sender, System::EventArgs^ e) {

}

void MkFile::gui::on_file_menu_restart_click(System::Object^ sender, System::EventArgs^ e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Are you sure you would like to restart?", "Restart?", MessageBoxButtons::YesNo, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1))
	{
		Application::Restart();
	}
}

void MkFile::gui::on_file_menu_exit_click(System::Object^ sender, System::EventArgs^ e) {
	if (System::Windows::Forms::DialogResult::Yes == MessageBox::Show("Are you sure you would like to exit?", "Exit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1))
	{
		Application::Exit();
	}
}

void MkFile::gui::on_theme_menu_light_click(System::Object^ sender, System::EventArgs^ e) {
	this->BackColor = SystemColors::Control;
	this->ForeColor = SystemColors::ControlText;

	this->file_name_input->BackColor = SystemColors::Window;
	this->file_extension_input->BackColor = SystemColors::Window;
	this->file_path_input->BackColor = SystemColors::Window;
	this->file_queue_list->BackColor = SystemColors::Window;

	this->file_name_input->ForeColor = SystemColors::WindowText;
	this->file_extension_input->ForeColor = SystemColors::WindowText;
	this->file_path_input->ForeColor = SystemColors::WindowText;
	this->file_queue_list->ForeColor = SystemColors::WindowText;
}

void MkFile::gui::on_theme_menu_dark_click(System::Object^ sender, System::EventArgs^ e) {
	this->BackColor = Color::Black;
	this->ForeColor = SystemColors::ControlLight;

	this->file_name_input->BackColor = SystemColors::ControlDarkDark;
	this->file_extension_input->BackColor = SystemColors::ControlDarkDark;
	this->file_path_input->BackColor = SystemColors::ControlDarkDark;
	this->file_queue_list->BackColor = SystemColors::ControlDarkDark;

	this->file_name_input->ForeColor = Color::Cyan;
	this->file_extension_input->ForeColor = Color::Cyan;
	this->file_path_input->ForeColor = Color::Cyan;
	this->file_queue_list->ForeColor = Color::Cyan;

}

void MkFile::gui::on_clear_btn_cick(System::Object^ sender, System::EventArgs^ e) {
	file_queue_list->Items->Clear();
	out("Queue has been cleared");
}