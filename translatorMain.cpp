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
const long translatorDialog::ID_BUTTON3 = wxNewId();
const long translatorDialog::ID_TEXTCTRL2 = wxNewId();
const long translatorDialog::ID_STATICLINE1 = wxNewId();
const long translatorDialog::ID_BUTTON1 = wxNewId();
const long translatorDialog::ID_BUTTON4 = wxNewId();
const long translatorDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(translatorDialog,wxDialog)
    //(*EventTable(translatorDialog)
    //*)
END_EVENT_TABLE()

translatorDialog::translatorDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(translatorDialog)
    wxBoxSizer* BoxSizer5;

    Create(parent, wxID_ANY, _("Translator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    chcFrom = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    BoxSizer4->Add(chcFrom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("icons/left_right.ico"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBackgroundColour(wxColour(0,0,255));
    BoxSizer4->Add(BitmapButton1, 0, wxTOP|wxBOTTOM|wxEXPAND, 4);
    chcTo = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    BoxSizer4->Add(chcTo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer3->Add(BoxSizer4, 0, wxEXPAND, 4);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    tctrlInput = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer5->Add(tctrlInput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button3 = new wxButton(this, ID_BUTTON3, _("Translate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer5->Add(Button3, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer3->Add(BoxSizer5, 0, wxEXPAND, 5);
    tctrlOutput = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(336,205), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(tctrlOutput, 1, wxALL|wxEXPAND, 4);
    BoxSizer1->Add(BoxSizer3, 1, wxEXPAND, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL, _T("ID_STATICLINE1"));
    BoxSizer1->Add(StaticLine1, 0, wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button4 = new wxButton(this, ID_BUTTON4, _("Settings"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnTranslate);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&translatorDialog::OnQuit);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&translatorDialog::OnInit);
    //*)
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
	chcFrom->SetColumns(2);
	chcTo->SetColumns(2);
	for (const Engine::LangInfoAndLocale& lang : engine_.getLanguages()) {
		chcFrom->Append(wxString::FromUTF8(lang.name.c_str()));
		chcTo->Append(wxString::FromUTF8(lang.name.c_str()));
	}
	// TODO: load the settings from the configuration file.
	chcFrom->SetSelection(0);
	chcTo->SetSelection(0);
}
