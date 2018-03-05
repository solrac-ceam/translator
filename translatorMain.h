/***************************************************************
 * Name:      translatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carlos E. Alfaro Mroales (solrac.azathot@gmail.com)
 * Created:   2018-02-26
 * Copyright: Carlos E. Alfaro Mroales (none)
 * License:   MIT License
 **************************************************************/

#ifndef TRANSLATORMAIN_H
#define TRANSLATORMAIN_H

//(*Headers(translatorDialog)
#include <wx/bmpbuttn.h>
#include <wx/msgdlg.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

#include <string>
#include "engine.hpp"

class translatorDialog: public wxDialog
{
    public:

        translatorDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~translatorDialog();

    private:

        //(*Handlers(translatorDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTranslate(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnSwapLanguages(wxCommandEvent& event);
        //*)

        //(*Identifiers(translatorDialog)
        static const long ID_CHOICE1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_CHOICE2;
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON6;
        static const long ID_PANEL1;
        static const long ID_BITMAPBUTTON5;
        static const long ID_TEXTCTRL2;
        static const long ID_BITMAPBUTTON7;
        static const long ID_PANEL2;
        static const long ID_STATICLINE1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(translatorDialog)
        wxBitmapButton* BitmapButton2;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton3;
        wxBoxSizer* BoxSizer3;
        wxMessageDialog* swapInfoMessageDialog;
        wxTextCtrl* tctrlOutput;
        wxBoxSizer* BoxSizer2;
        wxPanel* Panel2;
        wxStaticLine* StaticLine1;
        wxBitmapButton* BitmapButton5;
        wxBoxSizer* BoxSizer4;
        wxBitmapButton* BitmapButton4;
        wxChoice* chcFrom;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* tctrlInput;
        wxBitmapButton* BitmapButton7;
        wxChoice* chcTo;
        wxBitmapButton* BitmapButton1;
        wxBoxSizer* BoxSizer6;
        wxBitmapButton* BitmapButton6;
        //*)

        std::string configPathname_;
        Engine      engine_;

        DECLARE_EVENT_TABLE()
};

#endif // TRANSLATORMAIN_H
