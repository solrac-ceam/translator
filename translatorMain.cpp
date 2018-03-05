/***************************************************************
 * Name:      translatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Carlos E. Alfaro Mroales (solrac.azathot@gmail.com)
 * Created:   2018-02-26
 * Copyright: Carlos E. Alfaro Mroales (none)
 * License:   MIT License
 **************************************************************/

#include "translatorMain.h"
#include <wx/msgdlg.h>

#include <sys/stat.h>
#include "json.hpp"
#include "utils.hpp"

//(*InternalHeaders(translatorDialog)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(translatorDialog)
const long translatorDialog::ID_CHOICE1 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON1 = wxNewId();
const long translatorDialog::ID_CHOICE2 = wxNewId();
const long translatorDialog::ID_TEXTCTRL1 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON6 = wxNewId();
const long translatorDialog::ID_PANEL1 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON5 = wxNewId();
const long translatorDialog::ID_TEXTCTRL2 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON7 = wxNewId();
const long translatorDialog::ID_PANEL2 = wxNewId();
const long translatorDialog::ID_STATICLINE1 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON2 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON3 = wxNewId();
const long translatorDialog::ID_BITMAPBUTTON4 = wxNewId();
const long translatorDialog::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(translatorDialog,wxDialog)
    //(*EventTable(translatorDialog)
    //*)
END_EVENT_TABLE()

translatorDialog::translatorDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(translatorDialog)
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer5;

    Create(parent, wxID_ANY, _("Translator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    chcFrom = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    BoxSizer4->Add(chcFrom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("icons/left_right.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBackgroundColour(wxColour(0,0,0));
    BitmapButton1->SetToolTip(_("Swap languages"));
    BoxSizer4->Add(BitmapButton1, 0, wxTOP|wxBOTTOM|wxEXPAND, 4);
    chcTo = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    BoxSizer4->Add(chcTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer3->Add(BoxSizer4, 0, wxEXPAND, 4);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(255,255,255));
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    tctrlInput = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    tctrlInput->SetFocus();
    BoxSizer6->Add(tctrlInput, 1, wxEXPAND, 4);
    BitmapButton6 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("icons/play.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_BOTTOM|wxNO_BORDER|wxNO_FULL_REPAINT_ON_RESIZE, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BitmapButton6->SetBackgroundColour(wxColour(255,255,255));
    BitmapButton6->SetToolTip(_("Listen"));
    BoxSizer6->Add(BitmapButton6, 0, wxALIGN_BOTTOM, 4);
    Panel1->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel1);
    BoxSizer6->SetSizeHints(Panel1);
    BoxSizer5->Add(Panel1, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND, 4);
    BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("icons/translate.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BitmapButton5->SetToolTip(_("Translate"));
    BoxSizer5->Add(BitmapButton5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer3->Add(BoxSizer5, 0, wxEXPAND, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxColour(255,255,255));
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    tctrlOutput = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(350,200), wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer7->Add(tctrlOutput, 1, wxEXPAND, 4);
    BitmapButton7 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("icons/play.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    BitmapButton7->SetBackgroundColour(wxColour(252,252,252));
    BitmapButton7->SetToolTip(_("Listen"));
    BoxSizer7->Add(BitmapButton7, 0, wxALIGN_BOTTOM, 4);
    Panel2->SetSizer(BoxSizer7);
    BoxSizer7->Fit(Panel2);
    BoxSizer7->SetSizeHints(Panel2);
    BoxSizer3->Add(Panel2, 1, wxALL|wxALIGN_LEFT, 4);
    BoxSizer1->Add(BoxSizer3, 1, wxEXPAND, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL, _T("ID_STATICLINE1"));
    BoxSizer1->Add(StaticLine1, 0, wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("icons/about.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetToolTip(_("About"));
    BoxSizer2->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("icons/settings.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetToolTip(_("Settings"));
    BoxSizer2->Add(BitmapButton3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BitmapButton4 = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("icons/quit.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->SetToolTip(_("Quit"));
    BoxSizer2->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    swapInfoMessageDialog = new wxMessageDialog(this, _("Swap between\"Auto detect\" and any other language is not permited."), _("Message"), wxOK|wxICON_INFORMATION, wxDefaultPosition);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnSwapLanguages);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnTranslate);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnAbout);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnQuit);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&translatorDialog::OnInit);
    //*)

    configPathname_ = "config.json";
}

translatorDialog::~translatorDialog()
{
    //(*Destroy(translatorDialog)
    //*)
}

void translatorDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void translatorDialog::OnAbout(wxCommandEvent& event)
{
	wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void translatorDialog::OnTranslate(wxCommandEvent& event)
{
	std::string sl(chcFrom->GetString(chcFrom->GetSelection()).ToUTF8());
	sl = engine_.getLanguages().find(Engine::LangInfoAndLocale{sl})->iso_1;
	std::string tl(chcTo->GetString(chcTo->GetSelection()).ToUTF8());
	tl = engine_.getLanguages().find(Engine::LangInfoAndLocale{tl})->iso_1;
	// TODO: load the locale language.
	std::string text(tctrlInput->GetValue().ToUTF8());
	nlohmann::json res = engine_.sendRequestAndGetResponse(text, sl, tl, "es");
	std::string strRes = res.dump();
	tctrlOutput->SetValue(wxString::FromUTF8(strRes.c_str()));
}

void translatorDialog::OnInit(wxInitDialogEvent& event)
{
	nlohmann::json settings;
	// check if the configuration file exist.
	struct stat fileStat;
	if (stat(configPathname_.c_str(), &fileStat) != 0) {
		settings = createConfigFile(configPathname_);
	}
	else {
		settings = readConfigurations(configPathname_);
	}

	int fromIdx = 0;
	int toIdx = 0;
	int i = -1;
	for (const Engine::LangInfoAndLocale& lang : engine_.getLanguages()) {
		chcFrom->Append(wxString::FromUTF8(lang.name.c_str()));
		chcTo->Append(wxString::FromUTF8(lang.name.c_str()));
		++i;
		if (lang.iso_1 == settings["from"])
			fromIdx = i;
		if (lang.iso_1 == settings["to"])
			toIdx = i;
	}
	chcTo->Delete(0);
	toIdx--;
	chcFrom->SetColumns(settings["choice columns"]);
	chcTo->SetColumns(settings["choice columns"]);
	chcFrom->SetSelection(fromIdx);
	chcTo->SetSelection(toIdx);
}

void translatorDialog::OnSwapLanguages(wxCommandEvent& event)
{
	int temp = chcFrom->GetSelection();
	if (temp == 0) {
		swapInfoMessageDialog->ShowModal();
		return;
	}
	chcFrom->SetSelection(chcTo->GetSelection()+1);
	chcTo->SetSelection(temp-1);
}
