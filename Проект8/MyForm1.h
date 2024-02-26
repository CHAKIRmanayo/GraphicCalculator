#pragma once
#include "my_stack1.h"
#include "my_queue1.h"
#include "my_lexems1.h"

namespace GraphicCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
		char*  s1;
		char*  s2;
		char*  s3;
		MyQueue* q;
		double xMax, xMin;
		Point1* points1;
		int* i1;
		double step;
		float* yMin;
		float* yMax;
		double scaleX;
		double scaleY;
		float xLine;
		float yLine;
	private: System::Windows::Forms::TextBox^  tbMin;
	public: 
	private: System::Windows::Forms::TextBox^  tbMax;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::PictureBox^  pb1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  lblStep;
		
	public:	 
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			q = new MyQueue[1];
			*q = initMyQueue();
			s1 = new char[0];
			s2 = new char[0];
			s3 = new char[0];
			points1 = new Point1[1];
			i1 = new int[1];
			yMin = new float[1];
			yMax = new float[1];
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb1;
	protected: 

	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Button^  btnC;
	private: Double  lnew;
	private: System::Windows::Forms::Label^  lblErr;
	private: System::Windows::Forms::Label^  lblLexems;
	private: System::Windows::Forms::Label^  label1;






	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb1 = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->lblErr = (gcnew System::Windows::Forms::Label());
			this->lblLexems = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbMin = (gcnew System::Windows::Forms::TextBox());
			this->tbMax = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblStep = (gcnew System::Windows::Forms::Label());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->pb1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
			this->SuspendLayout();
			// 
			// tb1
			// 
			this->tb1->Location = System::Drawing::Point(37, 32);
			this->tb1->Name = L"tb1";
			this->tb1->Size = System::Drawing::Size(205, 22);
			this->tb1->TabIndex = 0;
			this->tb1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(24, 308);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(156, 72);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &MyForm::btnOK_Click);
			// 
			// btnC
			// 
			this->btnC->Location = System::Drawing::Point(25, 386);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(155, 72);
			this->btnC->TabIndex = 2;
			this->btnC->Text = L"C";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &MyForm::btnC_Click);
			// 
			// lblErr
			// 
			this->lblErr->AutoSize = true;
			this->lblErr->Location = System::Drawing::Point(34, 77);
			this->lblErr->Name = L"lblErr";
			this->lblErr->Size = System::Drawing::Size(0, 17);
			this->lblErr->TabIndex = 3;
			// 
			// lblLexems
			// 
			this->lblLexems->AutoSize = true;
			this->lblLexems->Location = System::Drawing::Point(34, 139);
			this->lblLexems->Name = L"lblLexems";
			this->lblLexems->Size = System::Drawing::Size(42, 17);
			this->lblLexems->TabIndex = 4;
			this->lblLexems->Text = L"Xmax";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Xmin";
			// 
			// tbMin
			// 
			this->tbMin->Location = System::Drawing::Point(37, 114);
			this->tbMin->Name = L"tbMin";
			this->tbMin->Size = System::Drawing::Size(100, 22);
			this->tbMin->TabIndex = 7;
			this->tbMin->TextChanged += gcnew System::EventHandler(this, &MyForm::tbMin_TextChanged);
			// 
			// tbMax
			// 
			this->tbMax->Location = System::Drawing::Point(37, 159);
			this->tbMax->Name = L"tbMax";
			this->tbMax->Size = System::Drawing::Size(100, 22);
			this->tbMax->TabIndex = 8;
			this->tbMax->TextChanged += gcnew System::EventHandler(this, &MyForm::tbMax_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 220);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Step";
			// 
			// lblStep
			// 
			this->lblStep->AutoSize = true;
			this->lblStep->Location = System::Drawing::Point(37, 268);
			this->lblStep->Name = L"lblStep";
			this->lblStep->Size = System::Drawing::Size(0, 17);
			this->lblStep->TabIndex = 10;
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->LargeChange = 1;
			this->hScrollBar1->Location = System::Drawing::Point(37, 237);
			this->hScrollBar1->Maximum = 10;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(271, 21);
			this->hScrollBar1->TabIndex = 11;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// pb1
			// 
			this->pb1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pb1->Location = System::Drawing::Point(331, 32);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(782, 471);
			this->pb1->TabIndex = 12;
			this->pb1->TabStop = false;
			this->pb1->SizeChanged += gcnew System::EventHandler(this, &MyForm::pb1_SizeChanged);
			this->pb1->Resize += gcnew System::EventHandler(this, &MyForm::pb1_Resize);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Function";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(37, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1125, 515);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pb1);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->lblStep);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbMax);
			this->Controls->Add(this->tbMin);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblLexems);
			this->Controls->Add(this->lblErr);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->tb1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	char* convertStringToChar(String^ path){
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path).ToPointer();
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (tb1->Text->Length == 0) {
			s1 = new char[0];
		}
		if (tb1->Text->Length > 0 && tb1->Text[tb1->Text->Length - 1] == ' ') {
			tb1->Text = tb1->Text->Remove(tb1->Text->Length - 1);
			tb1->SelectionStart = tb1->Text->Length;
		}
		if (testBrackets(convertStringToChar(tbMin->Text)) || testBrackets(convertStringToChar(tbMax->Text)) || testBrackets(convertStringToChar(tb1->Text)))
			lblErr->Text = "Error brackets";
		else
			lblErr->Text = "";
		correctSTR(convertStringToChar(tb1->Text));
		if (lblErr->Text == "")
			sepLexem(convertStringToChar(tb1->Text));
	}

	void correctSTR(char* s) {
		int i, pos2, save1, save2;
		int b = 0;
		int pos1 = testStr(s, s1, &i, &pos2);
		while(isCurr(pos1)) {
			save1 = pos1;
			save2 = pos2;
			s = corrStr(s, pos1, i);
			s1 = new char[strlen(s)];
			strcpy(s1, s);
			b++;
			pos1 = testStr(s, s1, &i, &pos2);
		}
		if (b > 0){
			tb1->Text = gcnew String(s);
			tb1->SelectionStart = save1 + save2;
		}
		else {
			s1 = new char[strlen(s)];
			strcpy(s1, s);
		}
	}

	void sepLexem(char* s){
		int t = 0;
		*q = sepLexem1(s, &t);
		if(t == 0){
			*q = reRecord(*q);
		}
	}

	private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Double::TryParse(tbMax->Text, xMax) && Double::TryParse(tbMin->Text, xMin) && Double::TryParse(lblStep->Text, step)) {
			if ((lblErr->Text == "Error brackets") || (tbMax->Text == "") || (tbMin->Text == "") || (lblStep->Text == "") || (tb1->Text->Length == 0) || (xMin >= xMax))
				MessageBox::Show("Error");
			else {
				points1 = getPoints(xMax, xMin, step, *q, i1, yMin, yMax);
				*yMax = Math::Round(*yMax, 2);
				*yMin = Math::Round(*yMin, 2);
				draw();
			}
		}
		else {
			MessageBox::Show("Error");
		}
	}

	private: System::Void btnC_Click(System::Object^  sender, System::EventArgs^  e) {
		tb1->Text = "";
		tb1->Focus();
	}
	
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		lblStep->Text = Convert::ToString(0.314159265351 / Math::Pow(10, hScrollBar1->Value));
	}

	void draw() {
		pb1->Image = gcnew Bitmap(pb1->Width, pb1->Height);
		Graphics^ g = Graphics::FromImage(pb1->Image);
		Pen^ p = gcnew Pen(Color::Black);
		scaleY = (pb1->Height - 100) / (*yMax - *yMin);
		scaleX = (pb1->Width - 100) / (xMax - xMin);
		drawLC(g, p);
		drawGr(g, p);
		drawNmb(g, p);
	}

	void drawNmb(Graphics^ g, Pen^ p) {
		SolidBrush^ b = gcnew SolidBrush(Color::Black);
		p->Width = 1;
		p->Color = Color::Black;
		drawNul(g, b);
		drawNmbX1(g, b);
		drawNmbX2(g, b);
		drawNmbY1(g, b);
		drawNmbY2(g, b);
	}

	void drawNmbX1(Graphics^ g, SolidBrush^ b) {
		int r = NulLoc();
		if ((r == 1 || r == 2) && (xMax <= 0 && xMin < 0)) {
			if (xMax != 0)
				g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 60, yLine - 18);

			g->DrawString(Convert::ToString(xMin), this->Font, b, 40, yLine - 18);
		}

		else if ((r == 1 || r == 2) && (xMax > 0 && xMin >= 0)) {
			if (xMin != 0)
				g->DrawString(Convert::ToString(xMin), this->Font, b, 45, yLine - 18);

			g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 55, yLine - 18);
		}

		else if ((r == 1 || r == 2) && (xMax > 0 && xMin < 0)) {
			g->DrawString(Convert::ToString(xMin), this->Font, b, 15, yLine - 18);
			g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 80, yLine - 18);
		}
	}

	void drawNmbX2(Graphics^ g, SolidBrush^ b) {
		int r = NulLoc();
		if ((r == 4 || r == 3) && (xMax <= 0 && xMin < 0)) {
			if (xMax != 0)
				g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 60, yLine + 10);

			g->DrawString(Convert::ToString(xMin), this->Font, b, 40, yLine + 10);
		}

		else if ((r == 3 || r == 4) && (xMax > 0 && xMin >= 0)) {
			if (xMin != 0)
				g->DrawString(Convert::ToString(xMin), this->Font, b, 45, yLine + 10);

			g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 55, yLine + 10);
		}

		else if ((r == 3 || r == 4) && (xMax > 0 && xMin < 0)) {
			g->DrawString(Convert::ToString(xMin), this->Font, b, 15, yLine + 10);
			g->DrawString(Convert::ToString(xMax), this->Font, b, pb1->Width - 80, yLine + 10);
		}
	}

	void drawNmbY1(Graphics^ g, SolidBrush^ b) {

		int r = NulLoc();
		if ((r == 1 || r == 4) && (*yMax == *yMin && *yMax != 0))
			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine + 5, pb1->Height / 2 - 7);

		else if ((r == 1 || r == 4) && (*yMax <= 0 && *yMin < 0)) {
			if (*yMax != 0)
				g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine + 5, 45);

			g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine + 5, pb1->Height - 55);
		}

		else if ((r == 1 || r == 4) && (*yMax > 0 && *yMin >= 0)) {
			if (*yMin != 0)
				g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine + 5, pb1->Height - 55);

			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine + 5, 45);
		}

		else if ((r == 1 || r == 4) && (*yMax > 0 && *yMin < 0)) {
			g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine + 5, pb1->Height - 55);
			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine + 5, 45);
		}
	}

	void drawNmbY2(Graphics^ g, SolidBrush^ b) {
		int r = NulLoc();
		if ((r == 2 || r == 3) && (*yMax == *yMin && *yMax != 0))
			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine - 32, pb1->Height / 2 - 7);

		else if ((r == 2 || r == 3) && (*yMax <= 0 && *yMin < 0)) {
			if (*yMax != 0)
				g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine - 32, 45);

			g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine - 32, pb1->Height - 55);
		}

		else if ((r == 3 || r == 2) && (*yMax > 0 && *yMin >= 0)) {
			if (*yMin != 0)
				g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine - 32, pb1->Height - 55);

			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine - 32, 45);
		}

		else if ((r == 3 || r == 2) && (*yMax > 0 && *yMin < 0)) {
			g->DrawString(Convert::ToString(*yMin), this->Font, b, xLine - 35, pb1->Height - 55);
			g->DrawString(Convert::ToString(*yMax), this->Font, b, xLine - 35, 45);
		}
	}

	int NulLoc() {
		int t;
		if (xMax <= 0 && xMin < 0) {
			if (*yMax <= 0 && *yMin < 0)
				t = 1;
			else t = 4;
		}
		else {
			if (*yMax <= 0 && *yMin < 0)
				t = 2;
			else t = 3;
		}
		return t;
	}

	void drawNul(Graphics^ g, SolidBrush^ b) {
		int r = NulLoc();
		if (r == 1)
			g->DrawString(Convert::ToString(0), this->Font, b, xLine + 5, yLine - 18);
		if (r == 2)
			g->DrawString(Convert::ToString(0), this->Font, b, xLine - 15, yLine - 18);
		if (r == 3)
			g->DrawString(Convert::ToString(0), this->Font, b, xLine - 15, yLine + 5);
		if (r == 4)
			g->DrawString(Convert::ToString(0), this->Font, b, xLine + 5, yLine + 5);
	}

	void drawLC(Graphics^ g, Pen^ p) {
		int r = NulLoc();
		p->Width = 2;
		p->Color = Color::Black;
		xLine = getXC();
		yLine = getYC();
		g->DrawLine(p, xLine, 0.0, xLine, float(pb1->Height));
		g->DrawLine(p, 0.0, yLine, float(pb1->Width), yLine);
	}

	float getXC() {
		if (xMax > 0 && xMin >= 0) {
			if (xMin == 0)
				return 50;
			return 30;
		}
		if (xMax > 0 && xMin < 0)
			return -scaleX * xMin + 25;
		if (xMax <= 0 && xMin < 0) {
			if (xMax == 0)
				return pb1->Width - 50;
			return pb1->Width - 30;
		}
	}

	float getYC() {
		if (*yMax == 0 && *yMin == 0)
			return pb1->Height / 2;
		if (*yMax <= 0 && *yMin < 0) {
			if (*yMax == 0)
				return 50;
			return 30;
		}
		if (*yMax > 0 && *yMin < 0)
			return scaleY * (*yMax) + 50;
		if (*yMax > 0 && *yMin >= 0) {
			if (*yMin == 0)
				return pb1->Height - 50;
			return pb1->Height - 30;
		}
		return pb1->Height - 50;
		if (*yMax == 0 && *yMin == 0)
			return pb1->Height / 2;
	}

	void drawGr(Graphics^ g, Pen^ p) {
		p->Color = Color::RoyalBlue;
		p->Width = 2;
		int countX = getCountX(xMin, xMax, *yMin, *yMax);
		int countY = getCountY(xMin, xMax, *yMin, *yMax);
		Point1* points = new Point1[*i1];
		points = getScale(points1, *i1, scaleX, scaleY, *yMax, xMin, step, countX, countY, pb1->Width, pb1->Height);
		drawLine(g, p, points);
	}

	void drawLine(Graphics^ g, Pen^ p, Point1* points) {
		float deltY = 0;
		for (int t = 0; t < *i1 - 1; t++) {

			int w = 0;
			int v = 0;
			if (deltY == 0) {
				g->DrawLine(p, points[t].x, points[t].y, points[t + 1].x, points[t + 1].y);
				deltY = Math::Abs(points[t].y - points[t + 1].y);
				v++;
			}
			else if (Math::Abs(points[t].y - points[t + 1].y) / deltY > 1.1 && (scaleY*(*yMax) + 50 - points[t + 1].y)*(scaleY*(*yMax) + 50 - points[t].y) < 0) {
				if (deltY > 2)
					w++;
			}
			if (w == 0 && v == 0) {
				g->DrawLine(p, points[t].x, points[t].y, points[t + 1].x, points[t + 1].y);
			}
			deltY = Math::Abs(points[t].y - points[t + 1].y);
		}
	}

private: System::Void pb1_Resize(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pb1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
	if (Double::TryParse(tbMax->Text, xMax) && Double::TryParse(tbMin->Text, xMin) && Double::TryParse(lblStep->Text, step)) {
		if ((lblErr->Text == "Error brackets") || (tbMax->Text == "") || (tbMin->Text == "") || (lblStep->Text == "") || (tb1->Text->Length == 0) || (xMin >= xMax))
			MessageBox::Show("Error");
		else {
			draw();
			pb1->Invalidate();
		}
	}
}

private: System::Void tbMin_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (tbMin->Text->Length > 0) {
		if (testBrackets(convertStringToChar(tbMin->Text)) || testBrackets(convertStringToChar(tbMax->Text)) || testBrackets(convertStringToChar(tb1->Text)))
			lblErr->Text = "Error brackets";
		else
			lblErr->Text = "";
		char* s = convertStringToChar(tbMin->Text);
		int i, f, q, p;
		int b = 0;
		int t = testStr(s, s2, &i, &f);
		do {
			t = testStr(s, s2, &i, &f);
			if (isCurr(t)) {
				s = corrStr(s, t, i);
				s2 = new char[strlen(s)];
				strcpy(s2, s); b++;
			}
		} while (isCurr(testStr(s, s2, &q, &p)));

		if (b > 0) {
			tbMin->Text = gcnew String(s);
			tbMin->SelectionStart = f + t;
		}
		else{
			s2=new char[strlen(s)];
			strcpy(s2,s);
		}
	}
}
	private: System::Void tbMax_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (tbMax->Text->Length > 0) {
			if (testBrackets(convertStringToChar(tbMin->Text)) || testBrackets(convertStringToChar(tbMax->Text)) || testBrackets(convertStringToChar(tb1->Text)))
				lblErr->Text = "Error brackets";
			else
				lblErr->Text = "";
			char* s = convertStringToChar(tbMax->Text);
			int i, f, q, p; int b = 0;
			int t = testStr(s, s3, &i, &f);
			do {
				t = testStr(s, s3, &i, &f);
				if (isCurr(t)) {
					s = corrStr(s, t, i);
					s3 = new char[strlen(s)];
					strcpy(s3, s); b++;
				}
			} while (isCurr(testStr(s, s3, &q, &p)));
			if (b > 0) {
				tbMax->Text = gcnew String(s);
				tbMax->SelectionStart = f + t;
			}
			else {
				s3 = new char[strlen(s)];
				strcpy(s3, s);
			}
		}
	}
};
}
