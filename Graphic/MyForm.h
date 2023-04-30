#pragma once
#include <cmath>
#include <array>
#include <iostream>
namespace Graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			pbPlot->Image = gcnew Bitmap(pbPlot->Width, pbPlot->Height);
			br = gcnew SolidBrush(Color::White);
			br_text = gcnew SolidBrush(Color::Black);
			pn_axes = gcnew Pen(Color::Black, 3);
			pn_line = gcnew Pen(Color::Blue, 3);
			pn_grid = gcnew Pen(Color::Gray, 1);
			printFont = gcnew System::Drawing::Font("Arial", 8);
			br_poly = gcnew SolidBrush(Color::Aquamarine);

			dgv->RowCount = 3;
			dgv->ColumnCount = 3;
			for (int i = 0; i < 3; i++)
				dgv->Columns[i]->Width = 55;
			dgv[0, 0]->Value = 1; dgv[1, 0]->Value = 0; dgv[2, 0]->Value = 0;
			dgv[0, 1]->Value = 0; dgv[1, 1]->Value = 1; dgv[2, 1]->Value = 0;
			dgv[0, 2]->Value = 0; dgv[1, 2]->Value = 0; dgv[2, 2]->Value = 1;
			count = 0;

			origin.X = pbPlot->Image->Width / 2;
			origin.Y = pbPlot->Image->Height / 2;
			Zero = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbPlot;
	protected:

	protected:





	private: System::Windows::Forms::Button^ btn_moveDown;
	private: System::Windows::Forms::Button^ btn_moveUp;
	private: System::Windows::Forms::Button^ btn_scaleUp;
	private: System::Windows::Forms::Button^ btn_scaleDown;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btn_moveLeft;
	private: System::Windows::Forms::Button^ btn_moveRight;
	private: System::Windows::Forms::Button^ btn_scaleOut;
	private: System::Windows::Forms::Button^ btn_scaleIn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ lbX;

	private: System::Windows::Forms::Button^ btnPlot;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::ListBox^ lbY;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dgv;

	private: System::Windows::Forms::Button^ btnAgainst;
	private: System::Windows::Forms::Button^ btnFollow;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btnDecline;
















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pbPlot = (gcnew System::Windows::Forms::PictureBox());
			this->btn_moveDown = (gcnew System::Windows::Forms::Button());
			this->btn_moveUp = (gcnew System::Windows::Forms::Button());
			this->btn_scaleUp = (gcnew System::Windows::Forms::Button());
			this->btn_scaleDown = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_moveLeft = (gcnew System::Windows::Forms::Button());
			this->btn_moveRight = (gcnew System::Windows::Forms::Button());
			this->btn_scaleOut = (gcnew System::Windows::Forms::Button());
			this->btn_scaleIn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbX = (gcnew System::Windows::Forms::ListBox());
			this->btnPlot = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->lbY = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->btnAgainst = (gcnew System::Windows::Forms::Button());
			this->btnFollow = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnDecline = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
			this->SuspendLayout();
			// 
			// pbPlot
			// 
			this->pbPlot->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbPlot->Location = System::Drawing::Point(12, 12);
			this->pbPlot->Name = L"pbPlot";
			this->pbPlot->Size = System::Drawing::Size(595, 436);
			this->pbPlot->TabIndex = 0;
			this->pbPlot->TabStop = false;
			this->pbPlot->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Mouse_Click);
			// 
			// btn_moveDown
			// 
			this->btn_moveDown->Location = System::Drawing::Point(744, 12);
			this->btn_moveDown->Name = L"btn_moveDown";
			this->btn_moveDown->Size = System::Drawing::Size(100, 69);
			this->btn_moveDown->TabIndex = 6;
			this->btn_moveDown->Text = L"/\\\r\n|\r\n|";
			this->btn_moveDown->UseVisualStyleBackColor = true;
			this->btn_moveDown->Click += gcnew System::EventHandler(this, &MyForm::btn_moveDown_Click);
			// 
			// btn_moveUp
			// 
			this->btn_moveUp->Location = System::Drawing::Point(744, 379);
			this->btn_moveUp->Name = L"btn_moveUp";
			this->btn_moveUp->Size = System::Drawing::Size(100, 69);
			this->btn_moveUp->TabIndex = 7;
			this->btn_moveUp->Text = L"|\r\n|\r\n\\/";
			this->btn_moveUp->UseVisualStyleBackColor = true;
			this->btn_moveUp->Click += gcnew System::EventHandler(this, &MyForm::btn_moveUp_Click);
			// 
			// btn_scaleUp
			// 
			this->btn_scaleUp->Location = System::Drawing::Point(613, 12);
			this->btn_scaleUp->Name = L"btn_scaleUp";
			this->btn_scaleUp->Size = System::Drawing::Size(100, 69);
			this->btn_scaleUp->TabIndex = 8;
			this->btn_scaleUp->Text = L"/\\\r\n|\r\n\\/";
			this->btn_scaleUp->UseVisualStyleBackColor = true;
			this->btn_scaleUp->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleUp_Click);
			// 
			// btn_scaleDown
			// 
			this->btn_scaleDown->Location = System::Drawing::Point(613, 379);
			this->btn_scaleDown->Name = L"btn_scaleDown";
			this->btn_scaleDown->Size = System::Drawing::Size(100, 69);
			this->btn_scaleDown->TabIndex = 9;
			this->btn_scaleDown->Text = L"\\/\r\n|\r\n/\\";
			this->btn_scaleDown->UseVisualStyleBackColor = true;
			this->btn_scaleDown->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleDown_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(740, 206);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 40);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Переме-\r\nщать по Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(614, 196);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 80);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Масштаби-\r\nровать\r\n(Y по\r\nумолчанию)";
			// 
			// btn_moveLeft
			// 
			this->btn_moveLeft->Location = System::Drawing::Point(12, 554);
			this->btn_moveLeft->Name = L"btn_moveLeft";
			this->btn_moveLeft->Size = System::Drawing::Size(100, 69);
			this->btn_moveLeft->TabIndex = 12;
			this->btn_moveLeft->Text = L"<====";
			this->btn_moveLeft->UseVisualStyleBackColor = true;
			this->btn_moveLeft->Click += gcnew System::EventHandler(this, &MyForm::btn_moveLeft_Click);
			// 
			// btn_moveRight
			// 
			this->btn_moveRight->Location = System::Drawing::Point(507, 554);
			this->btn_moveRight->Name = L"btn_moveRight";
			this->btn_moveRight->Size = System::Drawing::Size(100, 69);
			this->btn_moveRight->TabIndex = 13;
			this->btn_moveRight->Text = L"====>";
			this->btn_moveRight->UseVisualStyleBackColor = true;
			this->btn_moveRight->Click += gcnew System::EventHandler(this, &MyForm::btn_moveRight_Click);
			// 
			// btn_scaleOut
			// 
			this->btn_scaleOut->Location = System::Drawing::Point(12, 454);
			this->btn_scaleOut->Name = L"btn_scaleOut";
			this->btn_scaleOut->Size = System::Drawing::Size(100, 69);
			this->btn_scaleOut->TabIndex = 14;
			this->btn_scaleOut->Text = L"<===>";
			this->btn_scaleOut->UseVisualStyleBackColor = true;
			this->btn_scaleOut->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleOut_Click);
			// 
			// btn_scaleIn
			// 
			this->btn_scaleIn->Location = System::Drawing::Point(507, 454);
			this->btn_scaleIn->Name = L"btn_scaleIn";
			this->btn_scaleIn->Size = System::Drawing::Size(100, 69);
			this->btn_scaleIn->TabIndex = 15;
			this->btn_scaleIn->Text = L">===<";
			this->btn_scaleIn->UseVisualStyleBackColor = true;
			this->btn_scaleIn->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleIn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 578);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 20);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Перемещать по X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(219, 478);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(278, 20);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Масштабировать (X по умолчанию)";
			// 
			// lbX
			// 
			this->lbX->FormattingEnabled = true;
			this->lbX->ItemHeight = 20;
			this->lbX->Location = System::Drawing::Point(864, 12);
			this->lbX->Name = L"lbX";
			this->lbX->Size = System::Drawing::Size(123, 244);
			this->lbX->TabIndex = 18;
			this->lbX->Click += gcnew System::EventHandler(this, &MyForm::lbX_SelectedIndexChanged);
			// 
			// btnPlot
			// 
			this->btnPlot->Location = System::Drawing::Point(993, 529);
			this->btnPlot->Name = L"btnPlot";
			this->btnPlot->Size = System::Drawing::Size(123, 94);
			this->btnPlot->TabIndex = 19;
			this->btnPlot->Text = L"Построить";
			this->btnPlot->UseVisualStyleBackColor = true;
			this->btnPlot->Click += gcnew System::EventHandler(this, &MyForm::btnPlot_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(864, 529);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(123, 94);
			this->btnClear->TabIndex = 20;
			this->btnClear->Text = L"Очистка";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lbY
			// 
			this->lbY->FormattingEnabled = true;
			this->lbY->ItemHeight = 20;
			this->lbY->Location = System::Drawing::Point(993, 12);
			this->lbY->Name = L"lbY";
			this->lbY->Size = System::Drawing::Size(123, 244);
			this->lbY->TabIndex = 21;
			this->lbY->Click += gcnew System::EventHandler(this, &MyForm::lbY_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(918, 259);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 20);
			this->label5->TabIndex = 22;
			this->label5->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1046, 259);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 20);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Y";
			// 
			// dgv
			// 
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->ColumnHeadersVisible = false;
			this->dgv->Location = System::Drawing::Point(864, 314);
			this->dgv->Name = L"dgv";
			this->dgv->ReadOnly = true;
			this->dgv->RowHeadersVisible = false;
			this->dgv->RowHeadersWidth = 62;
			this->dgv->RowTemplate->Height = 28;
			this->dgv->Size = System::Drawing::Size(252, 134);
			this->dgv->TabIndex = 24;
			// 
			// btnAgainst
			// 
			this->btnAgainst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->btnAgainst->Location = System::Drawing::Point(744, 454);
			this->btnAgainst->Name = L"btnAgainst";
			this->btnAgainst->Size = System::Drawing::Size(100, 69);
			this->btnAgainst->TabIndex = 26;
			this->btnAgainst->Text = L"⟲";
			this->btnAgainst->UseVisualStyleBackColor = true;
			this->btnAgainst->Click += gcnew System::EventHandler(this, &MyForm::btnAgainst_Click);
			// 
			// btnFollow
			// 
			this->btnFollow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->btnFollow->Location = System::Drawing::Point(613, 554);
			this->btnFollow->Name = L"btnFollow";
			this->btnFollow->Size = System::Drawing::Size(100, 69);
			this->btnFollow->TabIndex = 27;
			this->btnFollow->Text = L"⟳";
			this->btnFollow->UseVisualStyleBackColor = true;
			this->btnFollow->Click += gcnew System::EventHandler(this, &MyForm::btnFollow_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(740, 543);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 80);
			this->label7->TabIndex = 28;
			this->label7->Text = L"Поворот\r\n(вокруг нуля\r\nпо\r\nумолчанию)";
			// 
			// btnDecline
			// 
			this->btnDecline->Location = System::Drawing::Point(864, 282);
			this->btnDecline->Name = L"btnDecline";
			this->btnDecline->Size = System::Drawing::Size(252, 26);
			this->btnDecline->TabIndex = 29;
			this->btnDecline->Text = L"Снять выделение";
			this->btnDecline->UseVisualStyleBackColor = true;
			this->btnDecline->Click += gcnew System::EventHandler(this, &MyForm::btnDecline_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1128, 635);
			this->Controls->Add(this->btnDecline);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->btnFollow);
			this->Controls->Add(this->btnAgainst);
			this->Controls->Add(this->dgv);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lbY);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnPlot);
			this->Controls->Add(this->lbX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_scaleIn);
			this->Controls->Add(this->btn_scaleOut);
			this->Controls->Add(this->btn_moveRight);
			this->Controls->Add(this->btn_moveLeft);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_scaleDown);
			this->Controls->Add(this->btn_scaleUp);
			this->Controls->Add(this->btn_moveUp);
			this->Controls->Add(this->btn_moveDown);
			this->Controls->Add(this->pbPlot);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Brush^ br, ^ br_text, ^ br_poly;
		Pen^ pn_axes, ^ pn_line, ^ pn_grid;
		System::Drawing::Font^ printFont;
		int count;
		Point origin;
		bool Zero;

		void clear(Image^ img, Brush^ b) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(b, 0, 0, img->Width, img->Height);
			pbPlot->Refresh();
			count = 0;
			lbX->Items->Clear();
			lbY->Items->Clear();
		}

		void plot_axes(Image^ img, Pen^ pn) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->DrawLine(pn, 0, origin.Y, img->Width, origin.Y);
			gr->DrawString("X", printFont, br_text, img->Width - 20, origin.Y - 20);
			gr->DrawLine(pn, origin.X, 0, origin.X, img->Height);
			gr->DrawString("Y", printFont, br_text, origin.X - 20, 0);
		}

		void matOut(double A[3][3]) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					std::cout << A[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}

		void matOutX(double X[3][1]) {
			for (int i = 0; i < 3; i++) {
				std::cout << X[i][0];
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}

		void mulX(double T[3][3], double C[3][1], double(&A)[3][1]) {
			double TEMP[3][1];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 1; j++) {
					TEMP[i][j] = 0;
					for (int p = 0; p < 3; p++)
						TEMP[i][j] += T[i][p] * C[p][j];
				}
			for (int i = 0; i < 3; i++)
				A[i][0] = TEMP[i][0];
		}

		void mul(double T[3][3], double C[3][3], double (&A)[3][3]) {
			double TEMP[3][3];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					TEMP[i][j] = 0;
					for (int p = 0; p < 3; p++)
						TEMP[i][j] += C[i][p] * T[p][j];
				}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					A[i][j] = TEMP[i][j];
		}

		void inverse(double m[3][3], double(&A)[3][3]) {
			double det = m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
				m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
				m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

			double invdet = 1 / det;

			//Matrix33d minv; // inverse of matrix m
			A[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * invdet;
			A[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invdet;
			A[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invdet;
			A[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invdet;
			A[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invdet;
			A[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) * invdet;
			A[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * invdet;
			A[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) * invdet;
			A[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * invdet;
		}

private: System::Void Mouse_Click(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	lbX->Items->Add(Convert::ToString(e->X - origin.X));
	lbY->Items->Add(Convert::ToString(origin.Y - e->Y));
	count++;
}
private: System::Void btnPlot_Click(System::Object^ sender, System::EventArgs^ e) {
	if (count == 0)
		return;
	Graphics^ gr = Graphics::FromImage(pbPlot->Image);
	gr->FillRectangle(br, 0, 0, pbPlot->Image->Width, pbPlot->Image->Height);
	array<PointF>^ points = gcnew array< PointF >(count);
	PointF p;

	double A[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	double X[3][1];
	for (int i = 0; i < count; i++) {
		p.X = Convert::ToInt16(lbX->Items[i]->ToString());
		p.Y = Convert::ToInt16(lbY->Items[i]->ToString());
		X[0][0] = p.X;
		X[1][0] = p.Y;
		X[2][0] = 1;
		mulX(A, X, X);
		p.X = X[0][0] + origin.X;
		p.Y = -X[1][0] + origin.Y;
		points[i] = p;
	}
	gr->FillPolygon(br_poly, points);
	plot_axes(pbPlot->Image, pn_axes);
	pbPlot->Refresh();
	delete points;
}
private: System::Void btn_moveLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = -10;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveRight_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = +10;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveUp_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = -10;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveDown_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = +10;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleOut_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbX->SelectedIndices->Count != 0) {
		double Tc[3][3];
		Tc[0][0] = 1; Tc[0][1] = 0; Tc[0][2] = Convert::ToDouble(lbX->Items[lbX->SelectedIndex]->ToString());
		Tc[1][0] = 0; Tc[1][1] = 1; Tc[1][2] = 0;
		Tc[2][0] = 0; Tc[2][1] = 0; Tc[2][2] = 1;
		double T[3][3];
		T[0][0] = 1.1; T[0][1] = 0; T[0][2] = 0;
		T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
		double TcInv[3][3];
		inverse(Tc, TcInv);
		double A[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
			}
		mul(Tc, A, A);
		mul(T, A, A);
		mul(TcInv, A, A);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				dgv[j, i]->Value = A[i][j];
			}
		btnPlot_Click(sender, e);
		return;
	}
	double T[3][3];
	double A[3][3];
	T[0][0] = 1.1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleIn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbX->SelectedIndices->Count != 0) {
		double Tc[3][3];
		Tc[0][0] = 1; Tc[0][1] = 0; Tc[0][2] = Convert::ToDouble(lbX->Items[lbX->SelectedIndex]->ToString());
		Tc[1][0] = 0; Tc[1][1] = 1; Tc[1][2] = 0;
		Tc[2][0] = 0; Tc[2][1] = 0; Tc[2][2] = 1;
		double T[3][3];
		T[0][0] = 0.9; T[0][1] = 0; T[0][2] = 0;
		T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
		double TcInv[3][3];
		inverse(Tc, TcInv);
		double A[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
			}
		mul(Tc, A, A);
		mul(T, A, A);
		mul(TcInv, A, A);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				dgv[j, i]->Value = A[i][j];
			}
		btnPlot_Click(sender, e);
		return;
	}
	double T[3][3];
	double A[3][3];
	T[0][0] = 0.9; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleUp_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbX->SelectedIndices->Count != 0) {
		double Tc[3][3];
		Tc[0][0] = 1; Tc[0][1] = 0; Tc[0][2] = 0;
		Tc[1][0] = 0; Tc[1][1] = 1; Tc[1][2] = Convert::ToDouble(lbY->Items[lbY->SelectedIndex]->ToString());;
		Tc[2][0] = 0; Tc[2][1] = 0; Tc[2][2] = 1;
		double T[3][3];
		T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
		T[1][0] = 0; T[1][1] = 1.1; T[1][2] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
		double TcInv[3][3];
		inverse(Tc, TcInv);
		double A[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
			}
		mul(Tc, A, A);
		mul(T, A, A);
		mul(TcInv, A, A);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				dgv[j, i]->Value = A[i][j];
			}
		btnPlot_Click(sender, e);
		return;
	}
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 1.1; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleDown_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbX->SelectedIndices->Count != 0) {
		double Tc[3][3];
		Tc[0][0] = 1; Tc[0][1] = 0; Tc[0][2] = 0;
		Tc[1][0] = 0; Tc[1][1] = 1; Tc[1][2] = Convert::ToDouble(lbY->Items[lbY->SelectedIndex]->ToString());;
		Tc[2][0] = 0; Tc[2][1] = 0; Tc[2][2] = 1;
		double T[3][3];
		T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
		T[1][0] = 0; T[1][1] = 0.9; T[1][2] = 0;
		T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
		double TcInv[3][3];
		inverse(Tc, TcInv);
		double A[3][3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
			}
		mul(Tc, A, A);
		mul(T, A, A);
		mul(TcInv, A, A);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				dgv[j, i]->Value = A[i][j];
			}
		btnPlot_Click(sender, e);
		return;
	}
	double T[3][3];
	double A[3][3];
	T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
	T[1][0] = 0; T[1][1] = 0.9; T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	clear(pbPlot->Image, br);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = 0;
		}
	dgv[0, 0]->Value = 1; dgv[1, 0]->Value = 0; dgv[2, 0]->Value = 0;
	dgv[0, 1]->Value = 0; dgv[1, 1]->Value = 1; dgv[2, 1]->Value = 0;
	dgv[0, 2]->Value = 0; dgv[1, 2]->Value = 0; dgv[2, 2]->Value = 1;
}
private: System::Void btnAgainst_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = cos(Math::PI / 12); T[0][1] = -sin(Math::PI / 12); T[0][2] = 0;
	T[1][0] = sin(Math::PI / 12); T[1][1] = cos(Math::PI / 12); T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void btnFollow_Click(System::Object^ sender, System::EventArgs^ e) {
	double T[3][3];
	double A[3][3];
	T[0][0] = cos(Math::PI / 12); T[0][1] = sin(Math::PI / 12); T[0][2] = 0;
	T[1][0] = -sin(Math::PI / 12); T[1][1] = cos(Math::PI / 12); T[1][2] = 0;
	T[2][0] = 0; T[2][1] = 0; T[2][2] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			A[i][j] = Convert::ToDouble(dgv[j, i]->Value->ToString());
		}
	mul(T, A, A);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			dgv[j, i]->Value = A[i][j];
		}
	btnPlot_Click(sender, e);
}
private: System::Void lbX_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	lbY->SetSelected(lbX->SelectedIndex, true);
}
private: System::Void lbY_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	lbX->SetSelected(lbY->SelectedIndex, true);
}
private: System::Void btnDecline_Click(System::Object^ sender, System::EventArgs^ e) {
	lbX->SelectedIndices->Clear();
	lbY->SelectedIndices->Clear();
}
};
}
