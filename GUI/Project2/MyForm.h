#pragma once

namespace Project1 {
	using namespace System::IO::Ports;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: SerialPort^ serialPort;

	public:


		MainForm(void)
		{
			InitializeComponent();
			serialPort = gcnew SerialPort();
			serialPort->PortName = "COM3"; // Cổng COM cần kết nối
			serialPort->BaudRate = 9600;  // Tốc độ Baud
			serialPort->Parity = Parity::None;
			serialPort->DataBits = 8;
			serialPort->StopBits = StopBits::One;
			serialPort->ReadTimeout = 500;
			serialPort->WriteTimeout = 500;
			serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm() {
			if (serialPort && serialPort->IsOpen) {
				serialPort->Close();
			}
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ ConnectToDevice_Click;
	protected:

	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnBaseLeft;
	private: System::Windows::Forms::Button^ btnBaseRight;
	private: System::Windows::Forms::Button^ btnShoulderUp;
	private: System::Windows::Forms::Button^ btnShoulderDown;

	private: System::Windows::Forms::Button^ btnElbowUp;
	private: System::Windows::Forms::Button^ btnElbowDown;
	protected:

	protected:







	private: System::Windows::Forms::Button^ btnWristUp;
	private: System::Windows::Forms::Button^ btnWristDown;
	private: System::Windows::Forms::Button^ btnDetectObject;




	private: System::Windows::Forms::Label^ txtStatus;




















	private: System::Windows::Forms::Label^ lblStatus;







	private:
		System::Windows::Forms::Label^ lblServo;
		System::Windows::Forms::TextBox^ txtServoValue;
		System::Windows::Forms::Button^ btnSetServo;

	private: System::Windows::Forms::Button^ btnSavePositions;
	private: System::Windows::Forms::Button^ btnRePlay;
	private: System::Windows::Forms::Button^ btnClearPositions;
	private: System::Windows::Forms::Button^ btnStop;

private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

private: System::Diagnostics::PerformanceCounter^ performanceCounter1;
























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ConnectToDevice_Click = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnBaseLeft = (gcnew System::Windows::Forms::Button());
			this->btnBaseRight = (gcnew System::Windows::Forms::Button());
			this->btnShoulderUp = (gcnew System::Windows::Forms::Button());
			this->btnShoulderDown = (gcnew System::Windows::Forms::Button());
			this->btnElbowUp = (gcnew System::Windows::Forms::Button());
			this->btnElbowDown = (gcnew System::Windows::Forms::Button());
			this->btnWristUp = (gcnew System::Windows::Forms::Button());
			this->btnWristDown = (gcnew System::Windows::Forms::Button());
			this->btnDetectObject = (gcnew System::Windows::Forms::Button());
			this->txtStatus = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->lblServo = (gcnew System::Windows::Forms::Label());
			this->txtServoValue = (gcnew System::Windows::Forms::TextBox());
			this->btnSetServo = (gcnew System::Windows::Forms::Button());
			this->btnSavePositions = (gcnew System::Windows::Forms::Button());
			this->btnRePlay = (gcnew System::Windows::Forms::Button());
			this->btnClearPositions = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->performanceCounter1 = (gcnew System::Diagnostics::PerformanceCounter());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->performanceCounter1))->BeginInit();
			this->SuspendLayout();
			// 
			// ConnectToDevice_Click
			// 
			this->ConnectToDevice_Click->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ConnectToDevice_Click->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConnectToDevice_Click->Location = System::Drawing::Point(376, 196);
			this->ConnectToDevice_Click->Margin = System::Windows::Forms::Padding(2);
			this->ConnectToDevice_Click->Name = L"ConnectToDevice_Click";
			this->ConnectToDevice_Click->Size = System::Drawing::Size(103, 46);
			this->ConnectToDevice_Click->TabIndex = 0;
			this->ConnectToDevice_Click->Text = L"Connect To Device";
			this->ConnectToDevice_Click->UseVisualStyleBackColor = false;
			this->ConnectToDevice_Click->Click += gcnew System::EventHandler(this, &MainForm::ConnectToDevice_Click_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(512, 196);
			this->btnExit->Margin = System::Windows::Forms::Padding(2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(115, 46);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// btnBaseLeft
			// 
			this->btnBaseLeft->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBaseLeft->Location = System::Drawing::Point(19, 20);
			this->btnBaseLeft->Margin = System::Windows::Forms::Padding(2);
			this->btnBaseLeft->Name = L"btnBaseLeft";
			this->btnBaseLeft->Size = System::Drawing::Size(89, 42);
			this->btnBaseLeft->TabIndex = 2;
			this->btnBaseLeft->Text = L"Base Left";
			this->btnBaseLeft->UseVisualStyleBackColor = true;
			this->btnBaseLeft->Click += gcnew System::EventHandler(this, &MainForm::btnBaseLeft_Click);
			// 
			// btnBaseRight
			// 
			this->btnBaseRight->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBaseRight->Location = System::Drawing::Point(249, 20);
			this->btnBaseRight->Margin = System::Windows::Forms::Padding(2);
			this->btnBaseRight->Name = L"btnBaseRight";
			this->btnBaseRight->Size = System::Drawing::Size(93, 42);
			this->btnBaseRight->TabIndex = 3;
			this->btnBaseRight->Text = L"Base Right";
			this->btnBaseRight->UseVisualStyleBackColor = true;
			this->btnBaseRight->Click += gcnew System::EventHandler(this, &MainForm::btnBaseRight_Click);
			// 
			// btnShoulderUp
			// 
			this->btnShoulderUp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnShoulderUp->Location = System::Drawing::Point(19, 82);
			this->btnShoulderUp->Margin = System::Windows::Forms::Padding(2);
			this->btnShoulderUp->Name = L"btnShoulderUp";
			this->btnShoulderUp->Size = System::Drawing::Size(89, 42);
			this->btnShoulderUp->TabIndex = 4;
			this->btnShoulderUp->Text = L"Shoulder Up";
			this->btnShoulderUp->UseVisualStyleBackColor = true;
			this->btnShoulderUp->Click += gcnew System::EventHandler(this, &MainForm::btnShoulderUp_Click);
			// 
			// btnShoulderDown
			// 
			this->btnShoulderDown->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnShoulderDown->Location = System::Drawing::Point(249, 82);
			this->btnShoulderDown->Margin = System::Windows::Forms::Padding(2);
			this->btnShoulderDown->Name = L"btnShoulderDown";
			this->btnShoulderDown->Size = System::Drawing::Size(93, 42);
			this->btnShoulderDown->TabIndex = 5;
			this->btnShoulderDown->Text = L"Shoulder Down";
			this->btnShoulderDown->UseVisualStyleBackColor = true;
			this->btnShoulderDown->Click += gcnew System::EventHandler(this, &MainForm::btnShoulderDown_Click);
			// 
			// btnElbowUp
			// 
			this->btnElbowUp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnElbowUp->Location = System::Drawing::Point(19, 139);
			this->btnElbowUp->Margin = System::Windows::Forms::Padding(2);
			this->btnElbowUp->Name = L"btnElbowUp";
			this->btnElbowUp->Size = System::Drawing::Size(89, 42);
			this->btnElbowUp->TabIndex = 6;
			this->btnElbowUp->Text = L"Elbow Up";
			this->btnElbowUp->UseVisualStyleBackColor = true;
			this->btnElbowUp->Click += gcnew System::EventHandler(this, &MainForm::btnElbowUp_Click);
			// 
			// btnElbowDown
			// 
			this->btnElbowDown->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnElbowDown->Location = System::Drawing::Point(249, 139);
			this->btnElbowDown->Margin = System::Windows::Forms::Padding(2);
			this->btnElbowDown->Name = L"btnElbowDown";
			this->btnElbowDown->Size = System::Drawing::Size(93, 42);
			this->btnElbowDown->TabIndex = 7;
			this->btnElbowDown->Text = L"Elbow Down";
			this->btnElbowDown->UseVisualStyleBackColor = true;
			this->btnElbowDown->Click += gcnew System::EventHandler(this, &MainForm::btnElbowDown_Click);
			// 
			// btnWristUp
			// 
			this->btnWristUp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWristUp->Location = System::Drawing::Point(136, 20);
			this->btnWristUp->Margin = System::Windows::Forms::Padding(2);
			this->btnWristUp->Name = L"btnWristUp";
			this->btnWristUp->Size = System::Drawing::Size(94, 42);
			this->btnWristUp->TabIndex = 8;
			this->btnWristUp->Text = L"Wrist Up";
			this->btnWristUp->UseVisualStyleBackColor = true;
			this->btnWristUp->Click += gcnew System::EventHandler(this, &MainForm::btnWristUp_Click);
			// 
			// btnWristDown
			// 
			this->btnWristDown->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWristDown->Location = System::Drawing::Point(132, 139);
			this->btnWristDown->Margin = System::Windows::Forms::Padding(2);
			this->btnWristDown->Name = L"btnWristDown";
			this->btnWristDown->Size = System::Drawing::Size(93, 42);
			this->btnWristDown->TabIndex = 9;
			this->btnWristDown->Text = L"Wrist Down";
			this->btnWristDown->UseVisualStyleBackColor = true;
			this->btnWristDown->Click += gcnew System::EventHandler(this, &MainForm::btnWristDown_Click);
			// 
			// btnDetectObject
			// 
			this->btnDetectObject->BackColor = System::Drawing::SystemColors::Info;
			this->btnDetectObject->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDetectObject->Location = System::Drawing::Point(133, 82);
			this->btnDetectObject->Margin = System::Windows::Forms::Padding(2);
			this->btnDetectObject->Name = L"btnDetectObject";
			this->btnDetectObject->Size = System::Drawing::Size(94, 42);
			this->btnDetectObject->TabIndex = 10;
			this->btnDetectObject->Text = L"Detect";
			this->btnDetectObject->UseVisualStyleBackColor = false;
			this->btnDetectObject->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
			// 
			// txtStatus
			// 
			this->txtStatus->AutoSize = true;
			this->txtStatus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStatus->Location = System::Drawing::Point(440, 108);
			this->txtStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtStatus->Name = L"txtStatus";
			this->txtStatus->Size = System::Drawing::Size(70, 16);
			this->txtStatus->TabIndex = 11;
			this->txtStatus->Text = L"Trạng Thái";
			this->txtStatus->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Location = System::Drawing::Point(441, 139);
			this->lblStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(10, 13);
			this->lblStatus->TabIndex = 24;
			this->lblStatus->Text = L" ";
			this->lblStatus->Click += gcnew System::EventHandler(this, &MainForm::lblStatus_Click);
			// 
			// lblServo
			// 
			this->lblServo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F));
			this->lblServo->Location = System::Drawing::Point(133, 216);
			this->lblServo->Name = L"lblServo";
			this->lblServo->Size = System::Drawing::Size(83, 23);
			this->lblServo->TabIndex = 0;
			this->lblServo->Text = L"Servo Angle:";
			this->lblServo->Click += gcnew System::EventHandler(this, &MainForm::lblServo_Click);
			// 
			// txtServoValue
			// 
			this->txtServoValue->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->txtServoValue->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F));
			this->txtServoValue->Location = System::Drawing::Point(214, 216);
			this->txtServoValue->Name = L"txtServoValue";
			this->txtServoValue->Size = System::Drawing::Size(100, 23);
			this->txtServoValue->TabIndex = 1;
			this->txtServoValue->TextChanged += gcnew System::EventHandler(this, &MainForm::txtServoValue_TextChanged);
			// 
			// btnSetServo
			// 
			this->btnSetServo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F));
			this->btnSetServo->Location = System::Drawing::Point(12, 212);
			this->btnSetServo->Name = L"btnSetServo";
			this->btnSetServo->Size = System::Drawing::Size(100, 30);
			this->btnSetServo->TabIndex = 2;
			this->btnSetServo->Text = L"Set Servo";
			this->btnSetServo->UseVisualStyleBackColor = true;
			this->btnSetServo->Click += gcnew System::EventHandler(this, &MainForm::btnSetServo_Click);
			// 
			// btnSavePositions
			// 
			this->btnSavePositions->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSavePositions->Location = System::Drawing::Point(104, 260);
			this->btnSavePositions->Margin = System::Windows::Forms::Padding(2);
			this->btnSavePositions->Name = L"btnSavePositions";
			this->btnSavePositions->Size = System::Drawing::Size(104, 42);
			this->btnSavePositions->TabIndex = 25;
			this->btnSavePositions->Text = L"Save Positions";
			this->btnSavePositions->UseVisualStyleBackColor = true;
			this->btnSavePositions->Click += gcnew System::EventHandler(this, &MainForm::btnSavePosition_Click);
			// 
			// btnRePlay
			// 
			this->btnRePlay->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRePlay->Location = System::Drawing::Point(104, 313);
			this->btnRePlay->Margin = System::Windows::Forms::Padding(2);
			this->btnRePlay->Name = L"btnRePlay";
			this->btnRePlay->Size = System::Drawing::Size(104, 42);
			this->btnRePlay->TabIndex = 27;
			this->btnRePlay->Text = L"RePlay";
			this->btnRePlay->UseVisualStyleBackColor = true;
			this->btnRePlay->Click += gcnew System::EventHandler(this, &MainForm::btnRePlay_Click);
			// 
			// btnClearPositions
			// 
			this->btnClearPositions->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClearPositions->Location = System::Drawing::Point(242, 260);
			this->btnClearPositions->Margin = System::Windows::Forms::Padding(2);
			this->btnClearPositions->Name = L"btnClearPositions";
			this->btnClearPositions->Size = System::Drawing::Size(104, 42);
			this->btnClearPositions->TabIndex = 28;
			this->btnClearPositions->Text = L"Clear Positons";
			this->btnClearPositions->UseVisualStyleBackColor = true;
			this->btnClearPositions->Click += gcnew System::EventHandler(this, &MainForm::btnClearPositions_Click);
			// 
			// btnStop
			// 
			this->btnStop->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStop->Location = System::Drawing::Point(242, 313);
			this->btnStop->Margin = System::Windows::Forms::Padding(2);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(104, 42);
			this->btnStop->TabIndex = 29;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MainForm::btnStop_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 366);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnClearPositions);
			this->Controls->Add(this->btnRePlay);
			this->Controls->Add(this->btnSavePositions);
			this->Controls->Add(this->lblServo);
			this->Controls->Add(this->txtServoValue);
			this->Controls->Add(this->btnSetServo);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->txtStatus);
			this->Controls->Add(this->btnDetectObject);
			this->Controls->Add(this->btnWristDown);
			this->Controls->Add(this->btnWristUp);
			this->Controls->Add(this->btnElbowDown);
			this->Controls->Add(this->btnElbowUp);
			this->Controls->Add(this->btnShoulderDown);
			this->Controls->Add(this->btnShoulderUp);
			this->Controls->Add(this->btnBaseRight);
			this->Controls->Add(this->btnBaseLeft);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->ConnectToDevice_Click);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->performanceCounter1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnShoulderDown_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("SHOULDER_DOWN");
			lblStatus->Text = "Command Sent: SHOULDER_DOWN";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnElbowDown_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("ELBOW_DOWN");
			lblStatus->Text = "Command Sent: ELBOW_DOWN";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnBaseLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("BASE_LEFT");
			lblStatus->Text = "Command Sent: BASE_LEFT";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}

	private: System::Void ConnectToDevice_Click_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (!serialPort->IsOpen) {
				serialPort->Open();
				lblStatus->Text = "Connected to COM3";
			}
		}
		catch (UnauthorizedAccessException^) {
			lblStatus->Text = "Access denied to COM3";
		}
		catch (IOException^) {
			lblStatus->Text = "Error: Unable to open COM3";
		}
		catch (Exception^ ex) {
			lblStatus->Text = "Error: " + ex->Message;
		}

	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void btnShoulderUp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("SHOULDER_UP");
			lblStatus->Text = "Command Sent: SHOULDER_UP";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnBaseRight_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("BASE_RIGHT");
			lblStatus->Text = "Command Sent: BASE_RIGHT";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnWristUp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("WRIST_UP");
			lblStatus->Text = "Command Sent: WRIST_UP";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnElbowUp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("ELBOW_UP");
			lblStatus->Text = "Command Sent: ELBOW_UP";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnWristDown_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("WRIST_DOWN");
			lblStatus->Text = "Command Sent: WRIST_DOWN";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		lblStatus->Text = "Exited";
		Application::Exit();
	}
	private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (serialPort->IsOpen) {
				serialPort->WriteLine("detect 0 0 0"); // Gửi lệnh detect tới Arduino
				lblStatus->Text = "Detect command sent.";
			}
			else {
				lblStatus->Text = "Serial port not open.";
			}
		}
		catch (Exception^ ex) {
			lblStatus->Text = "Error sending detect command: " + ex->Message;
		}
	}
	private: System::Void ZTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnMove_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("MOVE");
			lblStatus->Text = "Command Sent: MOVE";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnSavePosition_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("SAVE_POSITIONS");
			lblStatus->Text = "Command Sent: SAVE_POSITIONS";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnRePlay_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("REPLAY_POSITIONS");
			lblStatus->Text = "Command Sent: REPLAY_POSITIONS";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("STOP_REPLAY");
			lblStatus->Text = "Command Sent: STOP_REPLAY";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void btnClearPositions_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("CLEAR_POSITIONS");
			lblStatus->Text = "Command Sent: CLEAR_POSITIONS";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}


	private: System::Void XTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void YTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void lblStatus_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void UpdateStatus(String^ data) {
		if (lblStatus != nullptr) {
			lblStatus->Text = data;
		}
	}

	private: System::Void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		try {
			String^ incomingData = serialPort->ReadLine();
			this->Invoke(gcnew System::Action<String^>(this, &MainForm::UpdateStatus), incomingData);
		}
		catch (System::IO::IOException^) {
			this->Invoke(gcnew System::Action<String^>(this, &MainForm::UpdateStatus), "I/O Error occurred.");
		}
		catch (System::TimeoutException^) {
			this->Invoke(gcnew System::Action<String^>(this, &MainForm::UpdateStatus), "Timeout occurred.");
		}
		catch (Exception^) {
			this->Invoke(gcnew System::Action<String^>(this, &MainForm::UpdateStatus), "Unknown error.");
		}
	}

	private: System::Void btnqyaytrai_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private:
		void btnSetServo_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				// Lấy giá trị từ TextBox
				String^ input = this->txtServoValue->Text;

				// Tách hai giá trị từ chuỗi nhập vào
				array<String^>^ values = input->Split(' ');
				if (values->Length != 2) {
					MessageBox::Show(L"Please enter exactly two values separated by a space.", L"Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				// Chuyển đổi hai giá trị từ chuỗi sang số nguyên
				int angle1, angle2;
				if (!Int32::TryParse(values[0], angle1) || angle1 < 0 || angle1 > 180 ||
					!Int32::TryParse(values[1], angle2) || angle2 < 0 || angle2 > 180) {
					MessageBox::Show(L"Both values must be integers between 0 and 180.", L"Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				// Tạo lệnh điều khiển
				String^ command = L"SET_SERVO " + angle1.ToString() + L" " + angle2.ToString();

				// Gửi lệnh qua cổng nối tiếp
				if (!serialPort->IsOpen) {
					MessageBox::Show(L"Serial port is not open.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				serialPort->WriteLine(command);

			}
			catch (Exception^ ex) {

			}
		}


	private: System::Void lblServo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort->IsOpen) {
			serialPort->WriteLine("SHOULDER_UP");
			lblStatus->Text = "Command Sent:SHOULDER_UP";
		}
		else {
			lblStatus->Text = "Not connected to COM3";
		}
	}
	private: System::Void txtServoValue_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void btnControl_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textControlValue_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnup_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
